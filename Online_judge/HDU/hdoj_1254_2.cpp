#include<stdio.h>
#include<string.h>
struct node
{
    int x,y; //记录箱子的位置。
    int pi,pj; //记录人的位置
    int step;
}c[1000000];
int map[30][30];
bool hash[30][30][4];
bool hash1[30][30];
int n,m,si,sj,di,dj,pi,pj,ii,b,t,flag;
int dir[4][4]={{-1,0,1,0},{1,0,-1,0},{0,-1,0,1},{0,1,0,-1}}; 
void dfs(int ai,int bi) //人的位置到  推箱子时人站的位置的DFS。
{
    int i;
    if(map[ai][bi]==1)
        return ;
    if(ai<=0||bi<=0||ai>n||bi>m)
        return ;
    if(ai==c[b].x+dir[ii][2] && bi==c[b].y+dir[ii][3]) //这是推箱子是人站的位置。
        flag=1;
    if(flag)
        return ;
    for(i=0;i<4;i++)
        if(map[ ai + dir[i][1] ][ bi + dir[i][0] ]!=1 && hash1[ai + dir[i][1]][bi + dir[i][0]]==1 )
        {
            hash1[ai + dir[i][1]][bi + dir[i][0]]=0;
            dfs(ai + dir[i][1],bi + dir[i][0]);
        }
    return;
}
int bfs()
{
    int xi,yi;
    c[0].x=si; c[0].y=sj; c[0].step=0;
    c[0].pi=pi; c[0].pj=pj;
    t=1; b=0;
    while(b<t)
    {
        for(ii=0;ii<4;ii++)
        {
            if(map[c[b].x+dir[ii][2]][c[b].y+dir[ii][3]]==1) //如果人站的位置是墙。
                continue;

            xi=c[b].x+dir[ii][0];
            yi=c[b].y+dir[ii][1];

            if(xi<=0||yi<=0||xi>n||yi>m) //超出地图。
                continue;

            if(map[xi][yi]==1 || hash[xi][yi][ii]==0) //是墙或者走过了。
                continue;

            memset(hash1,1,sizeof(hash1)); //DFS的 hash 初始
            hash1[c[b].pi][c[b].pj]=0; //人的位置标记掉。
            hash1[c[b].x][c[b].y]=0; //箱子的位置标记掉。
            flag=0;
            dfs(c[b].pi,c[b].pj);
            if(flag==0)
                continue;
            else
            {
                if(xi==di&&yi==dj) //到达。
                    return c[b].step+1;

                c[t].x=xi; c[t].y=yi;
                c[t].step=c[b].step+1;

                c[t].pi=c[b].x; c[t].pj=c[b].y; //此时人的位置也就是 上一步箱子的位置。

                hash[xi][yi][ii]=0; //标记掉。
                t++;
            }
        }
        b++;
    }
    return -1;

}
int main()
{
    int h,k,i,j;
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                scanf("%d",&map[i][j]);
                for(h=0;h<4;h++)
                    hash[i][j][h]=1;
                if(map[i][j]==2)
                {
                    si=i; sj=j;
                }
                else if(map[i][j]==4)
                {
                    pi=i; pj=j;
                }
                else if(map[i][j]==3)
                {
                    di=i; dj=j;
                }
            }
        printf("%d\n",bfs());
    }
    return 0;
}