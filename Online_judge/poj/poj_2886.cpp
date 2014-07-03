#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct Line{
	int left,right,mid;
	int cnt;
}L[1500005];
struct Node{
	char name[50];
	int next;
}p[500005];
int a[37]={1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,7560,10080,15120,20160,25200,27720,45360,50400,  
	55440,83160,110880,166320,221760,277200,332640,498960,500001};  
int b[37]={1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,64,72,80,84,90,96,100,108,120,128,144,160,168,180,192,200,1314521};  
int bulid(int step,int l,int r){
	L[step].right=r;
	L[step].left=l;
	L[step].mid=(l+r)/2;
	if(l==r)
		 return L[step].cnt=1;
	return L[step].cnt=bulid(2*step,l,(l+r)/2)+bulid(2*step+1,(l+r)/2+1,r);
}
int query(int step,int idx){
	L[step].cnt--;
	if(L[step].left==L[step].right)
		return L[step].left;
	if(L[2*step].cnt>=idx)
		return query(2*step,idx);
	else
		return query(2*step+1,idx-L[2*step].cnt);
}
int main(){
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF){
		for(int i=1;i<=n;i++)
			scanf("%s%d",p[i].name,&p[i].next);
		int r=0;
		while(a[r]<=n)
			r++;
		int m=a[r-1];
		int mmax=b[r-1];
		bulid(1,1,n);
		int nextpos=0,currentpos=k;
		p[0].next=0;
		while(m--){
			if(p[nextpos].next>0)
				currentpos=1+((currentpos+p[nextpos].next-2)%L[1].cnt+L[1].cnt)%L[1].cnt;
			else
				currentpos=1+((currentpos+p[nextpos].next-1)%L[1].cnt+L[1].cnt)%L[1].cnt;
			nextpos=query(1,currentpos);
		}
		printf("%s %d\n",p[nextpos].name,mmax);
	}
	return 0;
}