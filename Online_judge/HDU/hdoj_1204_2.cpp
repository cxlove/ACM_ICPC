#include <iostream>
#include<cstdio>
 using namespace std;
 double g[105]={0,1};
 int n,m;
 double p,q;
 double solve(){
     if(n==0)    return 0;
     if(m==0)    return 1;
     if(p==0&&q==1)    return 0;
     if(p==1&&q==0)    return 1;
     int i;
     double a=(p-1)*q/(p*(1-q)),b=(p+q-2*p*q)/(p*(1-q));
     for(i=2;i<=n+m;i++)
         g[i]=a*g[i-2]+b*g[i-1];
     return g[n]/g[n+m];
 }
 int main(){
     //freopen("in.txt","r",stdin);
     while (~scanf("%d %d %lf %lf",&n,&m,&p,&q)){
         printf("%.2lf\n",solve());
     }
     return 0;
 }
