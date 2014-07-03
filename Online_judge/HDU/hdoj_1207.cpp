#include<stdio.h>

#include<math.h>

int main()

{

    int n,i,j,k,sum;

    int f;

    while(scanf("%d",&n)!=EOF)

    {

      k=2;

      for(i=1;i<=n;i++)

      {

        if(i==1)f=1,sum=1;

        else

        {

          for(j=k;sum<i;j++)sum+=j;

          k=j;

          f+=(int)pow(2,j-2);

        }

      }

      printf("%d\n",f);

    }

    return 0;

}  