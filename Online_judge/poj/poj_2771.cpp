#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;

struct People                                                          
{
       int h;
       char sex;
       char music[105];
       char sport[105];
}boy[505],girl[505];

bool usedif[505];
bool mat[505][505];
int link[505];
int bn,gn;

bool can(int t)                                                     
{
    int i;
    for(i=0;i<gn;i++)
    {
       if(!usedif[i]&&mat[t][i])
       {
            usedif[i]=true;
            if(link[i]==-1||can(link[i]))
            {
                link[i]=t;
                return true;
            }
       }
    }
    return false;
}

int MaxMatch()                                                      
{
    int i,num=0;
    memset(link,-1,sizeof(link));
    for(i=0;i<bn;i++)
    {
        memset(usedif,0,sizeof(usedif));
        if(can(i))
           num++;
    }
    return num;
}

int main()
{
    int i,j,t,n,ans;
    People p;
    scanf("%d",&t);
    while(t--)
    {
         scanf("%d",&n);
         bn=gn=ans=0;
         for(i=0;i<n;i++)
         {
             scanf("%d %c %s %s",&p.h,&p.sex,p.music,p.sport);
             if(p.sex=='M')                                     
                  boy[bn++]=p;
             else if(p.sex=='F')
                  girl[gn++]=p;
         }
         memset(mat,0,sizeof(mat));
         for(i=0;i<bn;i++)                                           
           for(j=0;j<gn;j++)
              if(abs(boy[i].h-girl[j].h)<=40&&strcmp(boy[i].music,girl[j].music)==0&&strcmp(boy[i].sport,girl[j].sport)!=0)
                 mat[i][j]=true;                                        
         ans=n-MaxMatch();                                      
         printf("%d\n",ans);
    }
    system("pause");
    return 0;
}

