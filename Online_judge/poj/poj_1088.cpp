#include<iostream>
#include<stdio.h>
int maxtri[110][110];
int opt[110][110];
int r,c;
int add[4][2]={-1,0,0,-1,0,1,1,0};//访问规则

bool ok(int rx,int cx)
{
  if(rx>=1&&rx<=r&&cx>=1&&cx<=c) return true;
  return false;
}
int dp(int i,int j)
{
  int k,tr,tc,m=1;
  if(opt[i][j]>1)return opt[i][j];
  for(k=0;k<4;k++)
  {
      tr=i+add[k][0];
   tc=j+add[k][1];
   if(ok(tr,tc)&&maxtri[i][j]>maxtri[tr][tc])
   {
     opt[i][j]=dp(tr,tc)+1;
  if(m<opt[i][j])m=opt[i][j];
   }
  }
  opt[i][j]=m;
  return opt[i][j];

}
int main()
{
   int i,j,max=0;
   scanf("%d%d",&r,&c);
   for(i=1;i<=r;i++)
     for(j=1;j<=c;j++)
  {
    scanf("%d",&maxtri[i][j]);
    opt[i][j]=1;
  }
   for(i=1;i<=r;i++)
     for(j=1;j<=c;j++)
  {
     if(max<dp(i,j))max=dp(i,j);
  }
  printf("%d\n",max);
    return 0;
}
