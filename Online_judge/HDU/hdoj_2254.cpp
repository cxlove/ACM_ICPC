/************************************************************************
     整整花了一天的时间在A这题，刚刚开始连续5次RE，后来发现二分求和的时候

     一直在传参，数据量很大，得定义为全局的，都不用传参来做，不要绝对溢栈

     改完后，又发现WA。。。原来有一点我没注意到~~~

     假如输入两次1 2，意思是1到2有两条路可走，而我做的时候都是赋值1，这样就错了

     最后我改成出现就q..martix[1][2]++;这样就AC了~  终于不用再纠结了。。。

     
    【主要解题思路：】
    
     这题的矩阵下标是<2^32，所以要处理下，变成30以内的下标，不然做不下去

     我们可以得出这样一个式子：sum=Slove(t2)-Slove(t1-1);这就是最后答案

     当然要注意判断t1和t2有没有为0的情况
   

************************************************************************/
#include <iostream>
using namespace std;
#define N 30

struct Mat
{
    int martix[N][N];
};

Mat res,q,init,temp_q,tp1,tp2,tp3,tp4,tp5;
int mod;
int city[100];
int city_len;


void er_fun(int x)
{
    int i,j,k;
    bool flag=0;
    tp1=q;
    tp2=res;
    while (x)
    {
        if(x&1)
        {
            flag=1;
            tp3=init;
            for (i=0;i<city_len;i++)
            {
                for (j=0;j<city_len;j++)
                {
                    for (k=0;k<city_len;k++)
                    {
                        tp3.martix[i][j]+=(tp2.martix[i][k]*tp1.martix[k][j])%mod;
                        tp3.martix[i][j]%=mod;
                    }
                }
            }
        }
        tp4=init;
        for (i=0;i<city_len;i++)
        {
            for (j=0;j<city_len;j++)
            {
                for (k=0;k<city_len;k++)
                {
                    tp4.martix[i][j]+=(tp1.martix[i][k]*tp1.martix[k][j])%mod;
                    tp4.martix[i][j]%=mod;
                }
            }
        }
        tp1=tp4;
        if(flag)
            tp2=tp3;
        x>>=1;
    }
}

void Slove(int p)
{
    int i,j,k;
    if(p==1) return;
    else if(p&1)
    {
        Slove(p-1);
        er_fun(p);
        for(i=0;i<city_len;i++)
        {
            for (j=0;j<city_len;j++)
            {
                temp_q.martix[i][j]=(temp_q.martix[i][j]+tp3.martix[i][j])%mod;
            }
        }
    }
    else
    {
        Slove(p>>1);
        er_fun(p>>1);
        for (i=0;i<city_len;i++)
        {
            for (j=0;j<city_len;j++)
            {
                tp5.martix[i][j]=(tp3.martix[i][j]+res.martix[i][j])%mod;
            }
        }
        tp1=temp_q;
        temp_q=init;
        for (i=0;i<city_len;i++)
        {
            for (j=0;j<city_len;j++)
            {
                for (k=0;k<city_len;k++)
                {
                    temp_q.martix[i][j]+=(tp1.martix[i][k]*tp5.martix[k][j])%mod;
                    temp_q.martix[i][j]%=mod;
                }
            }
        }
    }
}

int find(int x)
{
    int i,len;
    for (i=0;i<city_len;i++)
    {
        if(city[i]==x)
        {
            return i;
        }
    }
    len=city_len;
    city[city_len++]=x;
    return len;
}

int main()
{
    int n,m,i,j,t1,t2,v3,v4,x,y,v1,v2,sum;
    bool flag;
    memset(init.martix,0,sizeof(init.martix));
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            res.martix[i][j]=(i==j);
        }
    }
    mod=2008;
    while (scanf("%d",&n)!=EOF)
    {
        city_len=0;
        q=init;
        while (n--)
        {
            scanf("%d%d",&x,&y);
            q.martix[find(x)][find(y)]++;
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d%d%d",&v1,&v2,&t1,&t2);
            flag=0;
            for (i=0;i<city_len;i++)
            {
                if(city[i]==v1)
                {
                    flag=1;
                    v3=i;
                    break;
                }
            }
            if(!flag)
            {
                printf("0\n");
                continue;
            }
            flag=0;
            for (i=0;i<city_len;i++)
            {
                if(city[i]==v2)
                {
                    flag=1;
                    v4=i;
                    break;
                }
            }
            if(!flag)
            {
                printf("0\n");
                continue;
            }
            if(t1>t2)
            {
                int temp=t1;
                t1=t2;
                t2=temp;
            }
            if(t1==0 && t2==0)
            {
                printf("0\n");
                continue;
            }
            temp_q=q;
            Slove(t2);
            sum=temp_q.martix[v3][v4]%mod;
            if(t1>1)
            {
                temp_q=q;
                Slove(t1-1);
                sum=sum-(temp_q.martix[v3][v4])%mod;
            }
            if(sum<0)
                sum+=mod;
            printf("%d\n",sum%mod);
        }
    }
    return 0;
}