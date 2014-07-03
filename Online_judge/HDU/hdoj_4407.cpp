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
#define inf 1<<28
#define M 100005
#define N 400005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define MOD 1000000007
using namespace std;
map<int,int>mp;
map<int,int>::iterator it;
int n,q;
int prime[N][15]={0},flag[N]={0};
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
void Prime(){
    for(int i=2;i<N;i++){
        if(flag[i]){continue;}
        prime[i][++prime[i][0]]=i;
        for(int j=2;j*i<N;j++){
           flag[i*j]=1;
            prime[i*j][++prime[i*j][0]]=i;
        }
    }
}
LL ans;
void dfs(int idx,int num,int cnt,int m,int n,int p){
    if(cnt==m){
        int k=n/num;
        if(m&1) ans-=(LL)num*k*(k+1)/2;
        else ans+=(LL)num*k*(k+1)/2;
        return ;
    }
    if(idx>prime[p][0]) return;
    if(num>n) return ;
    dfs(idx+1,num,cnt,m,n,p);
    dfs(idx+1,num*prime[p][idx],cnt+1,m,n,p);
}
LL slove(int n,int p){
    if(n<=0) return 0;
    ans=(LL)n*(n+1)/2;
    for(int i=1;i<=prime[p][0];i++){
    //    cout<<prime[p][i]<<endl;
        dfs(1,1,0,i,n,p);
    }
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    Prime();
    while(t--){
        scanf("%d%d",&n,&q);
        mp.clear();
        while(q--){
            int k,x,y,c;
            scanf("%d",&k);
            if(k==1){
                scanf("%d%d%d",&x,&y,&c);
                LL ret=slove(y,c)-slove(x-1,c);
                for(it=mp.begin();it!=mp.end();it++){
                    if((*it).first>=x&&y>=(*it).first){                
                        if(gcd(c,(*it).first)==1) ret-=(*it).first;    
                        if(gcd(c,(*it).second)==1) ret+=(*it).second;
                    }
                }
                printf("%I64d\n",ret);;
            }
            else{
                scanf("%d%d",&x,&y);
                mp[x]=y;
            }
        }
    }
    return 0;
}