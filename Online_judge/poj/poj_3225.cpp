/*
ID:cxlove
PROB:Help with Intervals 
DATA:2012.2.26
HINT:线段树
*/
#include<iostream>
#include<cstdio>
#define MAX 65537
using namespace std;
struct line{
	int left,right,mid;
	int cover,change;
	int dis(){return right-left+1;}
	void Xor(){
		if(cover!=-1)
			cover^=1;
		else
			change^=1;
	}
}L[MAX*2*3];
struct ope{
	int left,right;
	char kind;
}p[100000];
int val[2*MAX];
void bulid(int step,int l,int r){
	L[step].left=l;
	L[step].right=r;
	L[step].mid=(l+r)/2;
	L[step].cover=0;
	L[step].change=0;
	if(l==r)
		return;
	bulid(2*step,l,(l+r)/2);
	bulid(2*step+1,(l+r)/2+1,r);
}
void update(int step,int l,int r,int k){
	if(L[step].right<l||L[step].left>r)
		return;
	if(L[step].left>=l&&L[step].right<=r){
		L[step].cover=k;
		L[step].change=0;
		return;
	}
	if(L[step].cover!=-1){
		L[step*2].cover=L[2*step+1].cover=L[step].cover;
		L[step*2].change=L[2*step+1].change=L[step].change;		
		L[step].change=0;
		L[step].cover=-1;
	}
	if(L[step].change){
		L[2*step].Xor();
		L[2*step+1].Xor();
		L[step].change=0;
	}	
	update(2*step,l,r,k);
	update(2*step+1,l,r,k);
	L[step].cover=(L[2*step].cover==L[2*step+1].cover?L[2*step].cover:-1);
}
void getxor(int step,int l,int r){
	if(L[step].right<l||L[step].left>r)
		return;
	if(L[step].left>=l&&L[step].right<=r){
		if(L[step].cover!=-1)
			L[step].cover^=1;
		else
	    	L[step].change^=1;
		return ;
	}
	if(L[step].cover!=-1){
		L[step*2].cover=L[2*step+1].cover=L[step].cover;
		L[step*2].change=L[2*step+1].change=L[step].change;		
		L[step].change=0;
		L[step].cover=-1;
	}
	if(L[step].change){
		L[2*step].Xor();
		L[2*step+1].Xor();
		L[step].change=0;
	}
	getxor(2*step,l,r);
	getxor(2*step+1,l,r);
	L[step].cover=(L[2*step].cover==L[2*step+1].cover?L[2*step].cover:-1);
}
void query(int step){
	if(L[step].left==L[step].right){
		val[L[step].left]=L[step].cover;
		return;
	}
	if(L[step].cover!=-1){
		L[step*2].cover=L[2*step+1].cover=L[step].cover;
		L[step*2].change=L[2*step+1].change=L[step].change;		
		L[step].change=0;
		L[step].cover=-1;
	}
	if(L[step].change){
		L[2*step].Xor();
		L[2*step+1].Xor();
		L[step].change=0;
	}
	query(2*step);
	query(2*step+1);
}
int main(){
	char str,ch1,ch2;
	int a,b,maxn=0;
	int m=0;
	while(scanf("%c %c%d,%d%c\n",&str,&ch1,&a,&b,&ch2)!=EOF){
		if(ch1=='(')
			a=a*2+1;
		else
			a=a*2;
		if(ch2==')')
			b=b*2-1;
		else
			b=b*2;		
		maxn=max(maxn,max(a,b));
		if(a>b)
			continue;
		p[m].left=a;p[m].right=b;p[m].kind=str;
		m++;
	}
	bulid(1,0,maxn+2);
	for(int i=0;i<m;i++){
		a=p[i].left;b=p[i].right;
		switch(p[i].kind){
		case 'U':{
			update(1,a,b,1);
			break;
				 }
		case 'I':{
			update(1,0,a-1,0);
			update(1,b+1,maxn+2,0);
			break;
				 }
		case 'D':{
			update(1,a,b,0);
			break;
				 }
		case 'C':{
			getxor(1,0,maxn+2);
			update(1,0,a-1,0);
			update(1,b+1,maxn+2,0);
			break;
				 }
		case 'S':{
			getxor(1,a,b);
			break;
				 }
		}
	}
	query(1);
	int i,j,flag=0;
	for(i=0;i<=maxn+2;i++)
		if(val[i]){
			for(j=i+1;j<=maxn+2;j++)
				if(!val[j])
					break;
			if(flag)
				printf(" ");
			printf("%c%d,%d%c",i%2==0?'[':'(',i/2,(j)/2,(j-1)%2==0?']':')');
			i=j;
			flag=1;
		}
	if(!flag)		
		printf("empty set");
	printf("\n");
	return 0;
}
/*
U [1,5]
D [3,3]
S [2,4]
C (1,5)
I (2,3]
*/
				





