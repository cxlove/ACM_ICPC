#include<string.h>
#include<iostream>
using namespace std;
int d[201][201],v[201],m[201],p,n;
bool dfs(int k)
{
     for(int i=1;i<=n;i++)
          if(!v[i]&&d[k][i])
          {
               v[i]=1;
               if(m[i]==0||dfs(m[i]))
               {
                    m[i]=k;
                    return true;
               }
          }
     return false;
}
int main()
{
    //int ncase;
    //scanf("%d",&ncase);
    while(cin>>p>>n)
    {
         int i,j,temp,a;
         //scanf("%d%d",&p,&n);
         memset(d,0,sizeof(d));
         memset(m,0,sizeof(m));
         for(i=1;i<=p;i++)
         {
              cin>>temp;
              for(j=1;j<=temp;j++)
              {
                    cin>>a;
                    d[i][a]=1;
              }
         }
         int sum=0;
         for(i=1;i<=p;i++)
         {
               memset(v,0,sizeof(v));           
               if(dfs(i))  sum++;
         }
         cout<<sum<<endl;
    }
    return 0;
}                           