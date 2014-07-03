#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100000;
const int inf=(1<<28);
int g[maxn],x[maxn],sum[1<<15];
int n,m;
int all;
int ans;
void scanf_(int &num){   
       char in;    
          while((in=getchar())>'9'||in<'0'); 
              num=in-'0';       
               while(in=getchar(),in>='0'&&in<='9')   
                        num*=10,num+=in-'0'; 
                        }  

int main()
{
    sum[1]=1;
     for(int i=2;i<(1<<15);i++)
      sum[i]=sum[i>>1]+(i&1);
    while(scanf("%d%d",&n,&m)==2)
    {
        memset(g,0,sizeof(g));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int tmp;scanf_(tmp);
                g[i]=(g[i]<<1)|tmp;
            }
        }
        all=(1<<m)-1;
        ans=inf;
        for(int i=0;i<=all;i++)
        {
            for(int j=0;j<n;j++) x[j]=g[j];
            int cnt=sum[i];
            x[0]^=i,x[0]^=i<<1,x[0]^=i>>1;x[0]&=all;
            x[1]^=i;
            for(int j=1;j<n;j++)
            {
                int k=x[j-1]^all;
                x[j]^=k,x[j]^=k<<1,x[j]^=k>>1;x[j]&=all;
                x[j+1]^=k;
                cnt+=sum[k];
            }
            if(x[n-1]==all) ans=min(ans,cnt);
        }
        if(ans==inf)printf("no solution\n");
        else printf("%d\n",ans);
    }
    return 0;
}



  
  
                
