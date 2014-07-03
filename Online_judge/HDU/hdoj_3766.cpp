#include<stdio.h>
int main()
{
    int n,m,k;
    char c;
    scanf("%c",&c);
    while(c!='E')
    {
         n=0;
         if(c=='-')
         scanf("%c",&c);
         while(c!=' ')
         {
             n=n*10+c-48; scanf("%c",&c);
         }             
         scanf("%d",&m);
         if(n<0) n=-n;
         if(m<0) m=-m;
         if(n<m) {k=n;n=m;m=k;}
         if(n>m*2)
         {
                  k=n-m*2;
                  if(n==1&&m==0) printf("3\n");
                  else printf("%d\n",m+k%4+(k-k%4)/2);
         }
         else{
                  k=n+m;
                  if(n==1&&m==1) printf("2\n");
                  else if(n==2&&m==2) printf("4\n");
                  else  printf("%d\n",k/3+k%3);
             }
         getchar();
         scanf("%c",&c);
    }
}