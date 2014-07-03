#include<stdio.h>
#include<string.h>
int a[25][1050];
int getmax(int x,int y)
{
  return x>y? x:y;
}

int main()
{
  int t;
  int n,m;
  int i,j,k;
  int max;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d",&n,&m);
    memset(a,0x8f,sizeof(a));
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=m;j++)
      {
        if(i==1&&1==j) continue; 
        max=getmax(a[i-1][j],a[i][j-1]);
        for(k=1;k<j;k++)
          if(j%k==0)
          max=getmax(max,a[i][k]);
        a[i][j]=a[i][j]+max;
      }
    }
    printf("%d\n",a[n][m]);
  }
  return 0;
}
