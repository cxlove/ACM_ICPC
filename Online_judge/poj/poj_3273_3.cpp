#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int money[100005];

int main()
{
    int i,m,n,num,mid,sum,left,right;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
          left=right=0;
          for(i=0;i<n;i++)
          {
              scanf("%d",&money[i]);
              right+=money[i];
              left=max(left,money[i]);
          }
          while(left<right)
          {
               sum=num=0;
               mid=(left+right)/2;
               for(i=0;i<n;i++)
               {
                   sum+=money[i];
                   if(sum>mid)
                   {
                      num++;
                      sum=money[i];
                   }
               }
               if(num<m)
                   right=mid;
               else
                   left=mid+1;
          }
          printf("%d\n",left);
    }
    return 0;
}

