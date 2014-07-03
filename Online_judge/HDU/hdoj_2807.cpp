#include <cstdio>
#include <iostream>
#define NN 81
#define inf 100000000
using namespace std;

int n,m;
int matrix[NN][NN][NN];
int dis[NN][NN];

void init()
{
     for (int i=1; i<=n; i++)
       for (int j=1; j<=m; j++)
         for (int k=1; k<=m; k++)
              scanf("%d",&matrix[i][j][k]);
}

void get_dis()
{
     int temp[NN][NN];
     
     for (int a=1; a<=n; a++)
       for (int b=1; b<=n; b++)
            dis[a][b]=inf;
     
     for (int a=1; a<=n; a++)
       for (int b=1; b<=n; b++)
       {
           if(a==b) continue;
            for (int i=1; i<=m; i++)
              for (int j=1; j<=m; j++)
              {
                  temp[i][j]=0;
                  for (int k=1; k<=m; k++)
                    temp[i][j]+=matrix[a][i][k]*matrix[b][k][j];
              }
            for (int c=1; c<=n; c++)
            {
              if(a==c||b==c)  continue;
                int flag=1;
                for (int i=1; i<=m && flag; i++)
                  for (int j=1; j<=m && flag; j++)
                    if (temp[i][j]!=matrix[c][i][j]) flag=0;
                if (flag) dis[a][c]=1;
            }
       }
}

void Floyed()
{
     for (int k=1; k<=n; k++)
       for (int i=1; i<=n; i++)
         for (int j=1; j<=n; j++)
         {
             if (k==i || k==j || i==j) continue;
             if (dis[i][j]>dis[i][k]+dis[k][j])
                 dis[i][j]=dis[i][k]+dis[k][j];
         }
}

void Query()
{
     int t,x,y;
     scanf("%d",&t);
     while (t--)
     {
           scanf("%d%d",&x,&y);
           if (dis[x][y]>=inf) 
               printf("Sorry\n");
           else
               printf("%d\n",dis[x][y]);
     }
}

int main()
{
    while (scanf("%d%d",&n,&m)!=EOF && n!=0 && m!=0)
    {
          init();
          get_dis();
          Floyed();
          Query();
    }    return 0;
}