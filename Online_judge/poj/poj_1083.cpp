#include<cstdio>  
#include<cstring>  
int num[210];  
int cal(int x)  
{  
    if(x&1)  x=(x/2)+1;  
    else x=x/2;  
    return x;  
}  
int main()  
{  
    int cas;  
    scanf("%d",&cas);  
    while(cas--)  
    {  
        int n,a,b;  
        scanf("%d",&n);  
        memset(num,0,sizeof(num));  
        for(int i=1;i<=n;i++)  
        {  
            scanf("%d%d",&a,&b);  
            a=cal(a);//计算要占用哪块走廊  
            b=cal(b);  
            if(a>b)  
            {  
                a=a^b;//交换a,b  
                b=a^b;  
                a=a^b;  
            }  
            for(int j=a;j<=b;j++)  num[j]++;  
        }  
        int maxn=-1;  
        for(int i=1;i<=200;i++)  if(num[i]>maxn) maxn=num[i];  
        printf("%d\n",maxn*10);  
    }  
    return 0;  
}  