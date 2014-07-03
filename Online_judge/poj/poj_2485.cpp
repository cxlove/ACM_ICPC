#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Node{
	int x,y,v;
}a[500*500+10];
int cnt,n,pre[505];
bool cmp(Node n1,Node n2){
	return n1.v<n2.v;
}
void Init(){
	cnt=0;
	for(int i=0;i<n;i++)
		pre[i]=i;
}
int find(int x){
	if(pre[x]==x) return x;
	return pre[x]=find(pre[x]);
}
void MST(){
	int sum=0,i;
	for(i=0;sum<n-1;i++){
		int ra=find(a[i].x);
		int rb=find(a[i].y);
		if(ra!=rb){
			sum++;
			pre[ra]=rb;
		}
	}
	printf("%d\n",a[i-1].v);	
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		Init();
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				int k;
				scanf("%d",&k);
				a[cnt].x=i;
				a[cnt].y=j;
				a[cnt++].v=k;
			}
		sort(a,a+cnt,cmp);
		MST();
	}
	return 0;
}