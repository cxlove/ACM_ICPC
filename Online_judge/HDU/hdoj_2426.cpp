#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=505;
const int INF=1<<25;
int map[MAXN][MAXN];
int lx[MAXN],ly[MAXN];
int mapch[MAXN];
int stack[MAXN];
bool sy[MAXN],sx[MAXN];
int N,M,e;
int find (int u){
    int v,t;
    sx[u]=1;
    for(v=1;v<=M;v++){
        if(sy[v]) continue;
        t=lx[u]+ly[v]-map[u][v];
        if(t==0){
            sy[v]=1;
            if(mapch[v]==-1||find(mapch[v])){
                mapch[v]=u;
                return 1;
            }
        }
        else if(t<stack[v]) stack[v]=t;
    }
    return 0;
}
int KM(){
    int i,j,k,d,cnt=0,sum=0;
    for(i=1;i<=M;i++)
        ly[i]=0;
    memset(mapch,-1,sizeof(mapch));
    for(i=1;i<=N;i++){
        lx[i]=-INF;
        for(j=1;j<=M;j++)
            if(map[i][j]>lx[i])
                lx[i]=map[i][j];
    }
    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++)
            stack[j]=INF;
        while(1){
            for(k=1;k<=M;k++) sy[k]=0;
            for(k=1;k<=N;k++) sx[k]=0;
            if(find(i)) break;
            d=INF;
            for(k=1;k<=M;k++)
                if(!sy[k]&&stack[k]<d)
                    d=stack[k];
            for(k=1;k<=N;k++)
                if(sx[k]) lx[k]-=d;
            for(k=1;k<=M;k++)
                if(sy[k]) ly[k]+=d;
                else stack[k]-=d;
        }
    }
    for(i=1;i<=M;i++)
        if(mapch[i]!=-1&&map[mapch[i]][i]!=INF){
            sum+=map[mapch[i]][i];
            cnt++;
        }
        if(cnt==N) return sum;
        else return -1;
}
int main(){
    int i,j;
    int x,y,z;
    int cas=0;
    while(scanf("%d%d%d",&N,&M,&e)!=EOF){
        for(i=1;i<=N;i++)
            for(j=1;j<=M;j++)
                map[i][j]=-INF;
        while(e--){
            scanf("%d%d%d",&x,&y,&z);
            if(z>=0)
                map[x+1][y+1]=z;
        }
        printf("Case %d: ",++cas);
        printf("%d\n",KM());
    }
    return 0;
}
