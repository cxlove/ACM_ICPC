#include<iostream>    
#include<cstdio>    
#include<map>    
#include<cstring>    
#include<cmath>    
#include<vector>    
#include<algorithm>    
#include<set>    
#include<string>    
#include<queue>    
#define inf 1600005    
#define M 40    
#define N 200005  
#define maxn 2000005    
#define eps 1e-7  
#define zero(a) fabs(a)<eps    
#define Min(a,b) ((a)<(b)?(a):(b))    
#define Max(a,b) ((a)>(b)?(a):(b))    
#define pb(a) push_back(a)    
#define mp(a,b) make_pair(a,b)    
#define mem(a,b) memset(a,b,sizeof(a))    
#define LL long long    
#define MOD 1000000007  
#define lson step<<1  
#define rson step<<1|1  
#define sqr(a) ((a)*(a))    
#define Key_value ch[ch[root][1]][0]    
#define test puts("OK");    
#define pi acos(-1.0)  
#define lowbit(x) ((x)&(-(x)))  
#pragma comment(linker, "/STACK:1024000000,1024000000")    
#define vi vector<int>   
using namespace std;  
struct Node{
    int left,right;
    LL sum,add;
}L[N<<2];
int n,tot=1;
void bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].sum=L[step].add=0;
    if(l==r) return ;
    int m=(l+r)>>1;
    bulid(lson,l,m);
    bulid(rson,m+1,r);
}
void push_up(int step){
    L[step].sum=L[lson].sum+L[rson].sum;
}
void push_down(int step){
    if(L[step].add){
        L[lson].add+=L[step].add;
        L[rson].add+=L[step].add;
        L[lson].sum+=L[step].add*(L[lson].right-L[lson].left+1);
        L[rson].sum+=L[step].add*(L[rson].right-L[rson].left+1);
        L[step].add=0;
    }
}
void add(int step,int pos,int val){
    if(L[step].left==pos&&L[step].right==pos){
        L[step].sum=val;
        return ;
    }
    int m=(L[step].left+L[step].right)>>1;
    push_down(step);
    if(pos<=m ) add(lson,pos,val);
    else add(rson,pos,val);
    push_up(step);
}
void update(int step,int l,int r,int val){
    if(L[step].left==l&&L[step].right==r){
        L[step].add+=val;
        L[step].sum+=val*(r-l+1);
        return ;
    }
    int m=(L[step].left+L[step].right)>>1;
    push_down(step);
    if(r<=m) update(lson,l,r,val);
    else if(l>m) update(rson,l,r,val);
    else{
        update(lson,l,m,val);
        update(rson,m+1,r,val);
    }
    push_up(step);
}
LL query(int step,int l,int r){
    if(L[step].left==l&&L[step].right==r)
        return L[step].sum;
    push_down(step);
    int m=(L[step].left+L[step].right)>>1;
    if(r<=m) return query(lson,l,r);
    else if(l>m) return query(rson,l,r);
    else return query(lson,l,m)+query(rson,m+1,r);
}
int main(){
    scanf("%d",&n);
    bulid(1,1,n+1);
    while(n--){
        int t;
        scanf("%d",&t);
        if(t==3) tot--;
        else if(t==2){
            int k;scanf("%d",&k);
            tot++;
            add(1,tot,k);
        }
        else{
            int a,k;
            scanf("%d%d",&a,&k);
            update(1,1,a,k);
        }
        printf("%.10f\n",query(1,1,tot)*1.0/tot);
    }
    return 0;
}