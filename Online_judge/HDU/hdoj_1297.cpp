#include<stdio.h>

#define c 31

#define d 100000000

int main()

{

    int n,i,j;

    int f[1000][c]={0};

    f[0][0]=1;

    f[1][0]=2;

    f[2][0]=4;

    f[3][0]=7;

    for(i=4;i<1000;i++)

    {

      for(j=0;j<c;j++)

        f[i][j]=f[i-1][j]+f[i-2][j]+f[i-4][j];

      for(j=0;j<c-1;j++)

        if(f[i][j]>d)

        {

          f[i][j+1]+=f[i][j]/d;

          f[i][j]%=d;

        }

    }

    while(scanf("%d",&n)!=EOF)

    {

      for(i=c-1;i>0;i--)if(f[n-1][i]!=0)break;

      printf("%d",f[n-1][i]);

      for(j=i-1;j>=0;j--)printf("%08d",f[n-1][j]);

      printf("\n");

    }

    return 0;

}  