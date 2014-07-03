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
#define N 100000
#define maxn 300005  
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
using namespace std;  
int s[N+5];
int n;
void Update(int x,int val){
    for(int i=x;i<=N;i+=lowbit(i))
        s[i]+=val;
}
int sum(int x){
    int ret=0;
    for(int i=x;i>0;i-=lowbit(i))
        ret+=s[i];
    return ret;
}
void query(int a,int k){
    int t=sum(N)-sum(a);
    if(t<k) {puts("Not Find!");return ;}
    int low=a+1,high=N,mid;
    while(low<=high){
        mid=(low+high)>>1;
        int cnt=sum(mid)-sum(a);
        int t1=sum(mid-1)-sum(a);
        if((cnt==k&&t1!=k)||(t1<k&&cnt>k)) {printf("%d\n",mid);return ;}
        if(cnt<k) low=mid+1;
        else high=mid-1;
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF){
        mem(s,0);
        while(n--){
            int k,l,r,val;
            scanf("%d",&k);
            if(k==0){
                scanf("%d",&val);
                Update(val,1);
            }
            else if(k==1){
                scanf("%d",&val);
                int t=sum(val)-sum(val-1);
                if(t==0) puts("No Elment!");
                else Update(val,-1);
            }
            else{
                scanf("%d%d",&l,&r);
                query(l,r);
            }
        }
    } return 0;
}