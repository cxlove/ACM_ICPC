#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

const double eps=0.0000001;
int id,t,m,n,a[110],i;

double ans;
int main()
{
 scanf("%d",&t);
 for (id=1;id<=t;id++)
 {
  scanf("%d",&m);
  n=0;
  for (i=0;i<m;i++)
  {
   scanf("%d",&a[i]);
   n+=a[i];
  }
  ans=a[0];
  ans/=n;

  printf("Case %d: %0.6f\n",id,ans);
 }
 return 0;
}