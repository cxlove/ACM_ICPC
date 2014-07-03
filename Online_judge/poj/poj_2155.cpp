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
#define N 70005
#define maxn 300005  
#define eps 1e-7
#define zero(a) fabs(a)<eps  
#define Min(a,b) ((a)<(b)?(a):(b))  
#define Max(a,b) ((a)>(b)?(a):(b))  
#define pb(a) push_back(a)  
#define mp(a,b) make_pair(a,b)  
#define mem(a,b) memset(a,b,sizeof(a))  
#define LL long long  
#define MOD 2012  
#define lson step<<1
#define rson step<<1|1
#define sqr(a) ((a)*(a))  
#define Key_value ch[ch[root][1]][0]  
#define test puts("OK");  
#define pi acos(-1.0)
#define lowbit(x) ((x)&(-(x)))
#pragma comment(linker, "/STACK:1024000000,1024000000")  
using namespace std;  
int x,y,xx,yy;
int n,q;
int s[1005][1005];
void Update(int x,int y){
    for(int i=x;i>0;i-=lowbit(i))
        for(int j=y;j>0;j-=lowbit(j))
            s[i][j]^=1;
}
int sum(int x,int y){
    int ret=0;
    for(int i=x;i<=n;i+=lowbit(i))
        for(int j=y;j<=n;j+=lowbit(j))
            ret^=s[i][j];
    return ret;
}
int main(){
    //freopen("in.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        mem(s,0);
        while(q--){
            char str[5];
            scanf("%s",str);
            if(str[0]=='C'){
                scanf("%d%d%d%d",&x,&y,&xx,&yy);
                Update(xx,yy);
                Update(x-1,yy);
                Update(xx,y-1);
                Update(x-1,y-1);
            }
            else{
                scanf("%d%d",&x,&y);
                printf("%d\n",sum(x,y));
            }
        }
        if(t) puts("");
    }
    return 0;
}