#include<stdio.h>

int main()

{

       int f,n;

       while(scanf("%d",&n)!=EOF)

       {

              f=1;

              while(n!=1)f=2*(f+1),n--;

              printf("%d\n",f);

       }

       return 0;

}  