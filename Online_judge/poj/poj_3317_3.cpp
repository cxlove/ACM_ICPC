#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf=(1<<30);
const int N=25;
int pw2[25],pw3[25];
map<int,int>rpw2;

struct point {
    int x,y;
}pt[N];
int n,m;
char g[N][N];
int ansx,ansy,score;
int ans[N],ct;
int HASH[555555];
bool vis[10][10];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int tt;
void dfs(int x,int y,char ch)
{
    if(vis[x][y]) return ;
    vis[x][y]=true;tt++;
    for(int i=0;i<4;i++)
    {
        int pi=x+dir[i][0];int pj=y+dir[i][1];
        if(pi<0||pi>=n||pj<0||pj>=n) continue;
        if(g[pi][pj]==ch)
        dfs(pi,pj,ch);
    }
}
int check()
{
    memset(vis,false,sizeof(vis));
    int c1=0,c2=0;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        tt=0;
        if(!vis[i][j])
        dfs(i,j,g[i][j]);
        if(g[i][j]=='0') c1=max(c1,tt);
        else c2=max(c2,tt);
    }
    return c1-c2;
}
int maxmin(int state,int who,int now,int alpha,int beta,int dep) {
    if(state==0)
    {
        for(int i=0;i<dep;i++)
        {
            int x=ans[i];
            g[pt[x].x][pt[x].y]=(i&1)+'0';
        }
        int tep=check();
        return tep;///
    }
    if(HASH[now]!=-inf) return HASH[now];
    int maxval=-inf,minval=inf,val;
    for(int st=state;st;st-=st&(-st))
    {
        int i=st&(-st),x=rpw2[i];
        ans[dep]=x;///
        val=maxmin(state-i,who^1,now+(who+1)*pw3[x],maxval,minval,dep+1);
        if(who==0&&val>beta) return val;
        if(who==1&&val<alpha) return val;
        maxval=max(maxval,val);
        minval=min(minval,val);

        if(dep==0) {
            if(maxval>score||(maxval==score&&(ansx>pt[x].x||(ansx==pt[x].x&&ansy>pt[x].y)))) {
                score=maxval;
                ansx=pt[x].x; ansy=pt[x].y;
            }
        }
    }
    if(who==0) return HASH[now]=maxval;
    else return HASH[now]=minval;
}
void init() {
    pw2[0]=pw3[0]=1;
    for(int i=0;i<20;i++) pw2[i]=1<<i,rpw2[1<<i]=i;
    for(int i=1;i<20;i++) pw3[i]=pw3[i-1]*3;
}

int main()
{
    int i,j,t,cas=0;
    int st,ct1,ct2;
    init();
    while(scanf("%d",&n)&&n)
    {
        ct1=ct2=m=0;
        for(i=0;i<n;i++) {
            scanf("%s",g[i]);
            for(j=0;j<n;j++) {
                if(g[i][j]=='.')pt[m].x=i,pt[m++].y=j;
                else if(g[i][j]=='0') ct1++;
                else ct2++;
            }
        }
        if(ct1>ct2)
        {
            for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            if(g[i][j]=='0') g[i][j]='1';
            else if(g[i][j]=='1') g[i][j]='0';
        }
        st=pw2[m]-1; //111111
        score=-inf;///
        for(i=0;i<pw3[m];i++) HASH[i]=-inf;
        //ansx=inf;///
        int ret=maxmin(st,0,0,-inf,inf,0);
        //if(ret==0) puts("#####");
        printf("(%d,%d) %d\n",ansx,ansy,score);
    }
    return 0;
}

/*
4
01.1
00..
.01.
...1
4
0.01
0.01
1..0
.1..
0
*/
