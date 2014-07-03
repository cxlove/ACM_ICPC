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
#define N 200000 
#define maxn 300005  
#define eps 1e-12
#define zero(a) fabs(a)<eps  
#define Min(a,b) ((a)<(b)?(a):(b))  
#define Max(a,b) ((a)>(b)?(a):(b))  
#define pb(a) push_back(a)  
#define mp(a,b) make_pair(a,b)  
#define mem(a,b) memset(a,b,sizeof(a))  
#define LL unsigned long long  
#define MOD 1000000007
#define lson step<<1
#define rson step<<1|1
#define sqr(a) ((a)*(a))  
#define Key_value ch[ch[root][1]][0]  
#define test puts("OK");  
#define pi acos(-1.0)
#define lowbit(x) ((-(x))&(x))
#pragma comment(linker, "/STACK:1024000000,1024000000")  
using namespace std;
struct Point{
    int x,y;
    bool operator<(const Point p)const{
        return x<p.x;
    }
}p[N+5];
int y[N],cnt;
int l[N+5],r[N+5];
int n;
void Update(int *s,int x,int val){
    for(int i=x;i<=cnt;i+=lowbit(i))
        s[i]+=val;
}
int sum(int *s,int x){
    int ret=0;
    for(int i=x;i>0;i-=lowbit(i))
        ret+=s[i];
    return ret;
}
int main(){
    //freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=0;i<n;i++){
            scanf("%d%d",&p[i].x,&p[i].y);
            y[i]=p[i].y;
        }
        sort(p,p+n);
        sort(y,y+n);
        cnt=unique(y,y+n)-y;
        mem(l,0);mem(r,0);
        for(int i=0;i<n;i++)
            Update(r,lower_bound(y,y+cnt,p[i].y)-y+1,1);
        int Stan=-1,st=0;
        vector<int>Ollie;
        for(int i=1;i<=n;i++){
            if(i==n||p[i].x!=p[i-1].x){
                for(int j=st;j<i;j++)
                    Update(r,lower_bound(y,y+cnt,p[j].y)-y+1,-1);
                int stan=-1,ollie=-1;
                for(int j=st;j<i;j++){
                    int pos=lower_bound(y,y+cnt,p[j].y)-y+1;
                    int a=sum(r,cnt)-sum(r,pos)+sum(l,pos-1);
                    int b=sum(l,cnt)-sum(l,pos)+sum(r,pos-1);
                    if(b==ollie) stan=min(stan,a);
                    else if(b>ollie) stan=a,ollie=b;  
                }
                if(stan>Stan){
                    Stan=stan;
                    Ollie.clear();
                }
                if(stan==Stan) Ollie.pb(ollie);
                for(int j=st;j<i;j++)
                    Update(l,lower_bound(y,y+cnt,p[j].y)-y+1,1);
                st=i;
            }
        }
        printf("Stan: %d; Ollie:",Stan);
        sort(Ollie.begin(),Ollie.end());
        cnt=unique(Ollie.begin(),Ollie.end())-Ollie.begin();
        for(int i=0;i<cnt;i++) printf(" %d",Ollie[i]);
        puts(";");
    }
    return 0;
}

