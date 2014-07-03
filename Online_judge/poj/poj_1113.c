/*
#include<stdio.h>
struct node
{  
 int x;  int y;   //箱子的位置 
 int pi; int pj;  //人的位置
 int step;        //步数
}c[10000];
int flag[10][10][10][10];
int ip[10][10];
int Flag,n,m;
int ii;
char map[10][10];
int head,tail;
int bi,bj,ti,tj,wi,wj;  //指定的位置
int way[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
void dfs(ai,aj)
{
	int i,xi,xj;
	if(map[ai][aj]=='#')  return;
	if(ai==c[head].x-way[ii][0]&&aj==c[head].y-way[ii][1])  
	{
		Flag=1;
		return ;
	}
	if(Flag) return;
	for(i=0;i<4;i++)
	{
		xi=ai+way[i][1];
		xj=aj+way[i][0];
		if(xi>=0&&xi<n&&xj>=0&&xj<m&&map[xi][xj]!='#'&&ip[xi][xj]==0)
		{
			ip[xi][xj]=1;
			dfs(xi,xj);
		}
	}
	return ;
}
int bfs()
{
	int i;
	int x1,y1,x2,y2;
	tail=1;
	head=0;
	c[0].x=bi;
	c[0].y=bj;
	c[0].pi=wi;
	c[0].pj=wj;
	c[0].step=0;
	while(head<tail)
	{
		for(ii=0;ii<4;ii++)
		{
			x1=c[head].x+way[ii][0];
			y1=c[head].y+way[ii][1];
			x2=c[head].x-way[ii][0];
			y2=c[head].y-way[ii][1];
			if(x1>=0&&x1<n&&y1>=0&&y1<m&&x2>=0&&x2<n&&y2>=0&&y2<m&&map[x1][y1]!='#'&&map[x2][y2]!='#'&&flag[x1][y1][way[ii][0]][way[ii][1]]==0)
			{
				memset(ip,0,sizeof(ip));
				Flag=0;
				ip[c[head].pi][c[head].pj]=1;
				ip[c[head].x][c[head].y]=1;
				dfs(c[head].pi,c[head].pj);
				if(Flag==0)  continue;  
				flag[x1][y1][way[ii][0]][way[ii][1]]=1;
				c[tail].x=x1;c[tail].y=y1;
				c[tail].pi=x2;c[tail].pj=y2;
				c[tail].step=c[head].step+1;				
				if(x1==ti&&y1==tj)
				{
					return c[tail].step;
				}
				tail++;
			}
		}
		head++;
	}
	return -1;
}
int main()
{     
	int i,j;  
	while(scanf("%d%d",&n,&m)!=EOF)  
	{     
		memset(flag,0,sizeof(flag));
		for(i=0;i<n;i++)       
		{                   
			scanf("%s",map[i]);    
			for(j=0;j<m;j++)          
			{                
				if(map[i][j]=='t')         
				{                           
					ti=i;tj=j;                 
				}       
				if(map[i][j]=='b')                   
				{                         
					bi=i;bj=j;                     
				}            
				if(map[i][j]=='w')                
				{                     
					wi=i;wj=j;                                      
				}        
			}           
		}          
		printf("%d\n",bfs());      
	}    
	return 0;
}

		
*/
#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 
int n,dis,head,num,t,mt,min=99999;
double ans=0; 
struct points
{
       int x;
       int y;
       double k; 
} ;
struct points point[2000],zhan[2000],tempp;

int chacheng(int x,int y,int z)
{
    int x1,x2,y1,y2,anss;
    x1 = zhan[y].x - zhan[x].x;
    y1 = zhan[y].y - zhan[x].y;
    x2 = point[z].x - zhan[y].x;
    y2 = point[z].y - zhan[y].y;
    anss = x1*y2 - x2*y1;
    return anss; 
} 

float diss(int x, int y)
{
      double d;
      d = sqrt((point[y].x-point[x].x) * (point[y].x-point[x].x) + (point[y].y-point[x].y) * (point[y].y-point[x].y)) ;
      return d; 
} 

float diss2(int x, int y)
{
      double d;
      d = sqrt((zhan[y].x-zhan[x].x) * (zhan[y].x-zhan[x].x) + (zhan[y].y-zhan[x].y) * (zhan[y].y-zhan[x].y)) ;
      return d; 
}

void sort(int low,int high)   
{ 
     int i=low,j=high;   
     tempp=point[low];   
     while(i<j)   
     {   
         while(i<j&&tempp.k<=point[j].k)j--;   
         if(i<j)   
         {   
             point[i]=point[j];   
             i++;   
         }       
         while(i<j&&point[i].k<tempp.k)i++;   
         if(i<j)   
         {   
             point[j]=point[i];   
             j--;   
         }   
     }   
     point[i]=tempp;   
     if(low<i)sort(low,i-1);   
     if(i<high)sort(j+1,high);           
}

void Qsort()
{
     int i,j;
     double k; 
     point[0] = point[num];
     point[num] = point[1];
     point[1] = point[0];
     for (i=2;i<=n;i++)
     {
         k =- ( (point[i].x - point[1].x)*1.0/diss(i,1)); 
         point[i].k=k;       
     }
     sort(2,n);
     for (i=3;i<=n;i++)
     {
         if (point[i].k - point[i-1].k >= -0.00001 && point[i].k - point[i-1].k <= 0.00001) 
         {
               if (diss(i-1,1)>diss(i,1))         
               point[i]=point[i-1]; 
               else point[i-1]= point[i]; 
         } 
     } 
      
} 
int main()
{
    int i,j;
    scanf("%d%d", &n, &dis); 
    min = 90000;
    ans = 0;
    for (i=1;i<=n;i++)
    {
        
        scanf("%d%d", &point[i].x, &point[i].y); 
        if (point[i].y < min) 
        {
              min = point[i].y;
              num = i; 
        }
        else if (point[i].y ==min && point[i].x<point[num].x)
        {
              num = i;  
        } 
    } 
    Qsort(); 
    zhan[1] =point[1];
    zhan[2] =point[2];
    head =2 ; 
    mt = 2;
    for (i=3;i<=n;i++)
    {
        if (point[i].k== point[i-1].k) continue;
        t = chacheng(head-1,head,i);
        if (t>=0)
        {
           head++;
           zhan[head] = point[i]; 
        } 
        else {head--;i=mt;} 
        mt = i;
    } 
    for (i=2;i<=head;i++)
    {
        ans+= diss2(i,i-1); 
    }
    ans+= diss2(head,1);
    ans+=2*3.141592653*dis; 
    printf("%d\n", (int)(ans+0.5)); 
 
 
}






