#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define inf 0x3f3f3f3f
#define lson (step<<1)
#define rson (step<<1|1)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
using namespace std;
const int N=1005;
struct Node{
    int x,len;
    Node(){}
    Node(int _x,int _l):x(_x),len(_l){}
    bool operator<(const Node n)const{
        return len>n.len;
    }
};
vector<pair<int,int> >e[N];
int vis[1005][1005];
int n,m,k,s;
char str[N];
int ans,idx;
void bfs(){
    priority_queue<Node>que;
    que.push(Node(s,0));
    mem(vis,0);
    vis[s][0]=1;
    while(!que.empty()){
        Node pre=que.top(),cur;
        que.pop();
        int u=pre.x;
        for(int i=0;i<e[u].size();i++){
            int v=e[u][i].first,w=e[u][i].second;
            cur.x=v;cur.len=w+pre.len;
            if(vis[cur.x][cur.len%k]) continue ;
            if(cur.len%k==0&&str[cur.x]=='P'){
                if(cur.len<ans||(cur.len==ans&&cur.x<idx)){
                    ans=cur.len;
                    idx=cur.x;
                }
                continue;
            }
            vis[cur.x][cur.len%k]=1;
            que.push(cur);
        }
    }
}
int main(){
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        ans=idx=inf;
        scanf("%d%d%d%d",&n,&m,&s,&k);
        s--;
        scanf("%s",str);
        for(int i=0;i<m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            u--;v--;
            e[u].pb(mp(v,w));
            //e[v].pb(mp(u,w));
        }
        for(int i=0;i<n;i++)
            sort(e[i].begin(),e[i].end());
        bfs();
        if(ans==inf) ans=-1,idx=-1;
        else idx++;
        printf("Case %d: %d %d\n",++cas,ans,idx);
        for(int i=0;i<n;i++)
            e[i].clear();
    }
    return 0;
}