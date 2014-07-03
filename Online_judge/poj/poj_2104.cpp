#include<iostream>  
#include<cstdio>  
#include<map>  
#include<cstring>  
#include<cmath>  
#include<vector>  
#include<algorithm>  
#include<set>  
#include<string>  
#include<ctime>
#include<queue>  
#define inf 1000000005  
#define M 10000005 
#define N 100005
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
#define C   240  
#define vi vector<int>
#define TIME 10  
#pragma comment(linker, "/STACK:1024000000,1024000000")  
using namespace std;
int n,q,m,tot;
int a[N],t[N];
int T[M],lson[M],rson[M],c[M];
void Init_hash(){
    for(int i=1;i<=n;i++)
        t[i]=a[i];
    sort(t+1,t+1+n);
    m=unique(t+1,t+1+n)-t-1;
}
int bulid(int l,int r){
    int root=tot++;
    c[root]=0;
    if(l!=r){
        int mid=(l+r)>>1;
        lson[root]=bulid(l,mid);
        rson[root]=bulid(mid+1,r);
    }
    return root;
}
int hash(int x){
    return lower_bound(t+1,t+1+m,x)-t;
}
int update(int root,int pos,int val){
    int newroot=tot++,tmp=newroot;
    c[newroot]=c[root]+val;
    int l=1,r=m;
    while(l<r){
        int mid=(l+r)>>1;
        //cout<<l<<" "<<r<<endl;
        if(pos<=mid){
            lson[newroot]=tot++;rson[newroot]=rson[root];
            newroot=lson[newroot];root=lson[root];
            r=mid;
        }
        else{
            rson[newroot]=tot++;lson[newroot]=lson[root];
            newroot=rson[newroot];root=rson[root];
            l=mid+1;
        }
        c[newroot]=c[root]+val;
    }
    return tmp;
}
int query(int left_root,int right_root,int k){
    int l=1,r=m;
    while(l<r){
        int mid=(l+r)>>1;
        if(c[lson[left_root]]-c[lson[right_root]]>=k){
            r=mid;
            left_root=lson[left_root];
            right_root=lson[right_root];
        }
        else{
            l=mid+1;
            k-=c[lson[left_root]]-c[lson[right_root]];
            left_root=rson[left_root];
            right_root=rson[right_root];
        }
    }
    return l;
}
int main(){
    while(scanf("%d%d",&n,&q)!=EOF){
        tot=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        Init_hash();
        T[n+1]=bulid(1,m);
        for(int i=n;i;i--){
            int pos=hash(a[i]);
            T[i]=update(T[i+1],pos,1);
        }
        while(q--){
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            printf("%d\n",t[query(T[l],T[r+1],k)]);
        }
    }
    return 0;
}
