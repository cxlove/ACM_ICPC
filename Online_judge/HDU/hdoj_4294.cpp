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
#define N 50005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define MOD 1000000007
using namespace std;
int num[2],m,step[N],pre[N];
int n,c,ope[N];
string s,ans;
bool bfs(){
    queue<int>que;
    mem(step,0);
    for(int i=0;i<m;i++){
        if(!num[i]||step[num[i]%n]) continue;
        pre[num[i]%n]=-1;
        step[num[i]%n]=1;
        ope[num[i]%n]=num[i];
        que.push(num[i]%n);
    }
    while(!que.empty()){
        int u=que.front();
        que.pop();
        if(u==0) return true;
        if(ans.size()&&step[u]>ans.size()) return false;
        for(int i=0;i<m;i++){
            int v=(u*c+num[i])%n;
            if(!step[v]){
                step[v]=step[u]+1;
                ope[v]=num[i];
                pre[v]=u;
                que.push(v);
            }
        }
    }
    return false;
}
void slove(int k){
    if(pre[k]!=-1) slove(pre[k]);
    s+=(char)(ope[k]+'0');
}
bool cmp(string a,string b){
    if(b.size()==0) return true;
    if(a.size()>b.size()) return false;
    if(b.size()>a.size()) return true;
    return a<b;
}
int main(){
    while(cin>>n>>c){
        bool flag=false;ans="";
        for(int i=1;i<c;i++){
            num[0]=i;m=1;
            if(bfs()){
                flag=true;
                s="";
                slove(0);
                if(cmp(s,ans))
                    ans=s;
            }
        }
        if(!flag){
            for(int i=1;i<c;i++){
                for(int j=0;j<i;j++){
                    num[0]=j;num[1]=i;m=2;
                    if(bfs()){
                        s="";
                        slove(0);
                        if(cmp(s,ans))
                            ans=s;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
                    

                


