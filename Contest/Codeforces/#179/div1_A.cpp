#include<iostream>      
#include<cstdio>      
#include<map>      
#include<cstring>      
#include<cmath>      
#include<vector>      
#include<algorithm>      
#include<set>      
#include<stack>    
#include<string>      
#include<ctime>    
#include<queue>      
#define inf 0x3f3f3f3f   
#define maxn 210005      
#define eps 1e-8    
#define zero(a) fabs(a)<eps      
#define Min(a,b) ((a)<(b)?(a):(b))      
#define Max(a,b) ((a)>(b)?(a):(b))      
#define pb(a) push_back(a)      
#define mp(a,b) make_pair(a,b)      
#define mem(a,b) memset(a,b,sizeof(a))      
#define LL long long      
#define MOD 1000000007    
#define sqr(a) ((a)*(a))      
#define Key_value ch[ch[root][1]][0]      
#define test puts("OK");      
#define pi acos(-1.0)    
#define lowbit(x) ((-(x))&(x))    
#define HASH1 1331    
#define HASH2 10001 
#define lson step<<1
#define rson step<<1|1   
#define C   240      
#define vi vector<int>    
#define TIME 10      
//#pragma comment(linker, "/STACK:1024000000,1024000000")      
using namespace std;
const int N=100005; 
struct Node{
	int left,right;
	LL add;
}L[N<<2];
LL x[N],y[N],d[N];
int n,m,k;
LL sum[N],a[N];
void bulid(int step,int l,int r){
	L[step].left=l;
	L[step].right=r;
	L[step].add=0;
	if(l==r){
		return ;
	}
	int m=(l+r)>>1;
	bulid(lson,l,m);
	bulid(rson,m+1,r);
}
void push_down(int step){
	if(L[step].add){
		L[lson].add+=L[step].add;
		L[rson].add+=L[step].add;
		L[step].add=0;
	}
}
void update(int step,int l,int r,LL val){
	if(L[step].left==l&&L[step].right==r){
		L[step].add+=val;
		return ;
	}
	push_down(step);
	int m=(L[step].left+L[step].right)>>1;
	if(r<=m) update(lson,l,r,val);
	else if(l>m) update(rson,l,r,val);
	else{
		update(lson,l,m,val);
		update(rson,m+1,r,val);
	}
}
void query(int step,int l,int r){
	if(l==r){
		a[l]+=L[step].add;
		return ;
	}
	int m=(l+r)>>1;
	push_down(step);
	query(lson,l,m);
	query(rson,m+1,r);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%I64d%I64d%I64d",&x[i],&y[i],&d[i]);
	for(int i=0;i<k;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		sum[u]++;sum[v+1]--;
	}
	for(int i=1;i<=m;i++)
		sum[i]+=sum[i-1];
	bulid(1,1,n);
	for(int i=1;i<=m;i++){
		update(1,x[i],y[i],(LL)d[i]*sum[i]);
	}
	query(1,1,n);
	for(int i=1;i<=n;i++)
		printf("%I64d%c",a[i],i==n?'\n':' ');
}