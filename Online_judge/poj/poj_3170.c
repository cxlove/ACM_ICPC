#include<stdio.h>
struct node
{
    int a;
     int flag;
}map[1001][1001];
struct point
{
   int x,y;
   int time,flag;
};
struct point que[1000005];
int w,h;
int head=0,tail=0;
int bfs(int i,int j,int mark,int t)
{
    if(i<0||i>=h||j<0||j>=w)  return 0;
    if(map[i][j].a==1)  return 0;
    if(map[i][j].a==3)  return mark;
    if(map[i][j].a==4)  mark=1;
    if(map[i][j].flag>mark)  return 0;
    map[i][j].flag++;
    que[tail].x=i;
    que[tail].y=j;
    que[tail].flag=mark;
    que[tail].time=t;
  //  printf("%d\n",t);
    tail++;
    return 0;
}    
int main()
{
    int i,j;
    struct point tt;
    scanf("%d%d",&w,&h);
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            scanf("%d",&map[i][j].a);
            map[i][j].flag=0;
            if(map[i][j].a==2)
            {
                tt.x=i;
                tt.y=j;
            }            
        }
    }
    tt.time=0;tt.flag=0;
    que[tail++]=tt;
    
     
    while(head<tail)
    {
         tt=que[head];head++; 
         if(bfs(tt.x,tt.y+1,tt.flag,tt.time+1)||bfs(tt.x,tt.y-1,tt.flag,tt.time+1)||bfs(tt.x-1,tt.y,tt.flag,tt.time+1)||bfs(tt.x+1,tt.y,tt.flag,tt.time+1))
              break;
    }
    printf("%d\n",tt.time+1);
   // system("pause");
    return 0;
}
    
    
    
    
    
