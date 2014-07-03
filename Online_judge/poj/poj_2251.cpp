#include<stdio.h>
#include<string.h>
typedef struct
{
    int z,x,y;
}node;
int way[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
char map[30][30][31];
int time[30][30][31];
int a,b,c;
int bfs(node s,node e)
{
    int i;
    node tt;
    node que[30*30*30];
    int head=0,tail=0;
    map[s.z][s.x][s.y]='#';
    que[tail++]=s;
    time[s.z][s.x][s.y]=0;
    while(head<tail)
    {
        s=que[head++];
        for(i=0;i<6;i++)
        {
            tt.z=s.z+way[i][0];
            tt.x=s.x+way[i][1];
            tt.y=s.y+way[i][2];
            if(tt.z>=0&&tt.z<a&&tt.x>=0&&tt.x<b&&tt.y>=0&&tt.y<c&&map[tt.z][tt.x][tt.y]!='#')
            {           
                time[tt.z][tt.x][tt.y]=time[s.z][s.x][s.y]+1;
                if(tt.z==e.z&&tt.x==e.x&&tt.y==e.y)
                {
                    return 0;
                }               
                que[tail++]=tt; 
                map[tt.z][tt.x][tt.y]='#';  
            }       
        }
    }
    return 1;
}
int main()
{
    int h,i,j;
    node s,e;
    while(scanf("%d%d%d",&a,&b,&c),a!=0||b!=0||c!=0)
    {
        for(h=0;h<a;h++)
        {
            for(i=0;i<b;i++)
            {
                scanf("%s",map[h][i]);
                for(j=0;j<c;j++)
                {
                    if(map[h][i][j]=='S')
                    {
                        s.z=h;s.x=i;s.y=j;
                    }
                    if(map[h][i][j]=='E')
                    {
                        e.z=h;e.x=i;e.y=j;
                    }
                }
 
            }
        }
         
        if(bfs(s,e))
        {
            printf("Trapped!\n");
        }
        else
        {
            printf("Escaped in %d minute(s).\n",time[e.z][e.x][e.y]);
        }
    }
    return 0;
}