#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>
#include <queue>
#include <cmath>
#define LL long long 
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define pii pair<int,int>
#define sqr(a) ((double)(a)*(a))
using namespace std;
struct Node{
    int u,v,w;
    Node(){}
    Node(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
    bool operator<(const Node n)const{
        return w<n.w;
    }
}e[2505*2505];
int n,m;
int way[4][2]={0,1,0,-1,1,0,-1,0};
char str[100][100];
int a[100][100],pre[2505];
int cnt,tot,ans;
int find(int x){
    return pre[x]=(pre[x]==x?x:find(pre[x]));
}
void fuck(int x,int y,int w){
    int ra=find(x),rb=find(y);
    if(ra!=rb){
        ans+=w;
        pre[ra]=rb;
    }
}
void spfa(int x,int y){
    int dist[55][55];
    queue<pii >que;
    que.push(mp(x,y));
    memset(dist,0x11,sizeof(dist));
    dist[x][y]=0;
    while(!que.empty()){
        pii u=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            pii v=u;
            v.first+=way[i][0];
            v.second+=way[i][1];
            if(v.first<0||v.second<0||v.first>=n||v.second>=m||a[v.first][v.second]<0)
                continue;
            if(dist[v.first][v.second]>dist[u.first][u.second]+1){
                dist[v.first][v.second]=dist[u.first][u.second]+1;
                que.push(v);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i!=x||j!=y){
                if(a[i][j]>0){
                    e[tot++]=Node(a[x][y],a[i][j],dist[i][j]);
                    //cout<<a[x][y]<<" "<<a[i][j]<<" "<<dist[i][j]<<endl;
                }
            }
        }
    }
}
char tmp[2332];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);
        gets(tmp);
        cnt=0;tot=0;
        for(int i=0;i<n;i++){
            gets(str[i]);
            for(int j=0;j<m;j++){
                if(str[i][j]=='A'||str[i][j]=='S')
                    a[i][j]=++cnt;
                else if(str[i][j]==' ')
                    a[i][j]=0;
                else a[i][j]=-1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]>0){
                    spfa(i,j);
                }
            }
        }
        for(int i=1;i<=cnt;i++)
            pre[i]=i;
        sort(e,e+tot);
        ans=0;
        for(int i=0;i<tot;i++){
            fuck(e[i].u,e[i].v,e[i].w);
        }
        printf("%d\n",ans);
    }
    return 0;
}