#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100000;
const int inf=(1<<28);
//有n*m的灯，最少几次可以把所有的灯点亮,每次可点周围5个 m<=20
int g[maxn],x[maxn],sum[1<<15];
int n,m;
int all;
int ans;
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
                //0暗 1亮
                int tmp;scanf("%d",&tmp);
                g[i]=(g[i]<<1)|tmp;
            }
        }
        all=(1<<m)-1;
        ans=inf;
        for(int i=0;i<=all;i++)//枚举第一行开灯情况1,change;0,stay
        {
            for(int j=0;j<n;j++) x[j]=g[j];//用memcpy会超时
            int cnt=sum[i];//开灯次数
            //press 0 i
            x[0]^=i,x[0]^=i<<1,x[0]^=i>>1;x[0]&=all;
            x[1]^=i;
            //2-n行已经确定
            for(int j=1;j<n;j++)
            {
                int k=x[j-1]^all;//上一行0的位置
                //press j,k
                x[j]^=k,x[j]^=k<<1,x[j]^=k>>1;x[j]&=all;
                x[j+1]^=k;
                //
                cnt+=sum[k];
            }
            if(x[n-1]==all) ans=min(ans,cnt);
        }
        if(ans==inf)printf("no solution\n");
        else printf("%d\n",ans);
    }
    return 0;
}



  
  
                
