#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<string>
#include<vector>
#define eps 1e-6
#define LL long long
#define LD __int64
#define pi acos(-1.0)
#define inf 1<<29
using namespace std;
struct monster{
    int cost,val;
}mon[55];
struct Node{
    int cost,val;
    bool operator<(const Node n1)const{
        return n1.val!=val?val<n1.val:cost>n1.cost;
    }
}s,e;
vector<monster>group[55];
int cnt,n,m,ans;
bool mat[55][55],flag[55];
void dfs(int u){
    flag[u]=true;
    group[cnt].push_back(mon[u]);
    for(int i=1;i<=n;i++)
        if(!flag[i]&&mat[u][i])
            dfs(i);
}
void divid_group(){
    cnt=0;
    memset(flag,false,sizeof(flag));
    for(int i=1;i<=n;i++)
        if(!flag[i]){
            cnt++;
            group[cnt].clear();
            dfs(i);
        }
}
void slove(){
    ans=inf;
    priority_queue<Node>que1,que2;
    for(int i=1;i<=cnt;i++){
        while(!que1.empty()) que1.pop();
        while(!que2.empty()) que2.pop();
        s.cost=s.val=0;
        que1.push(s);
        for(int j=0;j<group[i].size();j++){
            while(!que1.empty()){
                s=que1.top();
                que1.pop();
                que2.push(s);
                s.cost+=group[i][j].cost;
                s.val+=group[i][j].val;    
                if(s.val>=m){
                    ans=min(ans,s.cost);
                    continue;
                }
                if(s.cost>=ans)
                    continue;
                que2.push(s);
            }
            int mincost=inf;
            while(!que2.empty()){
                s=que2.top();
                que2.pop();
                if(s.cost<mincost)
                    que1.push(s),mincost=s.cost;
            }
        }
    }
}
void scanf_(int &num){ 
    char in;      
    while((in=getchar())>'9'||in<'0');  
    num=in-'0';      
    while(in=getchar(),in>='0'&&in<='9')    
        num*=10,num+=in-'0';
} 
void printf_(int num){     
    int ans[10],top=0;   
    while(num!=0){   
        ans[top++]=num%10;   
        num/=10;   
    }    
    if(top==0)     
        putchar('0');  
    for(int i=top-1;i>=0;i--){  
        char ch=ans[i]+'0';     
        putchar(ch);    
    }
} 
int main(){
    int t,cas=0;
    scanf_(t);
    while(t--){
        scanf_(n);scanf_(m);
        memset(mat,false,sizeof(mat));
        for(int i=1;i<=n;i++){
            int k,u;
            scanf_(mon[i].cost);scanf_(mon[i].val);scanf_(k);
            while(k--){
                scanf_(u);
                mat[i][u]=true;
            }
        }
        divid_group();
        slove();
        printf("Case %d: ",++cas);
        if(ans==inf)
            puts("Poor Magina, you can't save the world all the time!");
        else{
            printf_(ans);
            puts("");
        }
    }
    return 0;
}