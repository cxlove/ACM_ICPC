#include"stdio.h"
int n,a[100005],i,pre[100005],next[100005];

__int64 max,tem_max;

int main()
{
while(scanf("%ld",&n),n)
{
   for(i=1;i<=n;i++)
   {
    scanf("%d",&a[i]);
    next[i]=pre[i]=i;
   }
   for(i=2;i<=n;i++)
   {
    while(pre[i]>1 && a[pre[i]-1]>=a[i])   /*也到DP的地方*/
     pre[i]=pre[pre[i]-1];
   }
   for(i=n-1;i>0;i--)
   {
    while(next[i]<n && a[next[i]+1]>=a[i])
     next[i]=next[next[i]+1];
   }
   max=0;
   for(i=1;i<=n;i++)
   {
    tem_max=(__int64)(next[i]-pre[i]+1)*a[i];
    if(max<tem_max)
     max=tem_max;
   }
   printf("%I64d\n",max);
}
return 0;
}
 

