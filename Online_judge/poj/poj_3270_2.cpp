#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node{
	int val,cnt;
}a[10005];
int n,m[10005],t[10005],tot=0;
bool flag[10005];
void dfs(int num,int idx){
	for(int i=1;i<=n;i++){
		if(t[i]==num&&flag[i]==false){
			flag[i]=true;
			a[idx].val=min(a[idx].val,t[i]);
			a[idx].cnt++;
			dfs(m[i],tot);
		}
	}
}
int main(){
	int sum=0,mmin=1<<30;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&m[i]);
		sum+=m[i];
		t[i]=m[i];
		mmin=min(m[i],mmin);
	}
	sort(m+1,m+n+1);
	memset(flag,false,sizeof(flag));
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			flag[i]=true;
			a[tot].cnt=1;
			a[tot].val=t[i];
			dfs(m[i],tot);
			tot++;
		}
	}
	for(int i=0;i<tot;i++)
		sum+=min((a[i].cnt-2)*a[i].val,mmin*(a[i].cnt+1)+a[i].val);
	printf("%d\n",sum);
	return 0;
}