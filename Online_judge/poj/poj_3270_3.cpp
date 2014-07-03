#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node{
	int k,t;
}b[10005];
int n,a[10005],sum=0,c[10005];
bool vis[10005];
void dfs(int m,int count){
	for(int i=0;i<n;i++){
		if(a[i]==m&&!vis[i]){
			b[count].k++;
			b[count].t=min(b[count].t,a[i]);
			vis[i]=true;
			dfs(c[i],count);
			break;
		}
	}
}
int main(){
	int mmin=9999999;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		c[i]=a[i];
		sum+=a[i];
		mmin=min(mmin,a[i]);
	}
	sort(c,c+n);
	memset(vis,false,sizeof(vis));
	int count=0;
	for(int i=0;i<n;i++)
		if(!vis[i]){
			b[count].t=a[i];
			b[count].k=1;
			vis[i]=true;
			dfs(c[i],count);
			count++;
		}
	int ans=sum;
	for(int i=0;i<count;i++)
		ans+=min((b[i].k-2)*b[i].t,b[i].t+(b[i].k+1)*mmin);
	printf("%d\n",ans);
	return 0;
}	



