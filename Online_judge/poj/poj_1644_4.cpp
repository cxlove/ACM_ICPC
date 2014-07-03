#include<memory.h>   
#include<stdio.h>   
#include<math.h>   
#define M 55   
#define T 44   
#define NIL 999999   
int is[M],m,t;  
double dp[M][M];  
void input()  
{  
    char s[100];  
    scanf("%d%d",&m,&t);  
    //重要的初始化   
    is[0] = is[m+1] = is[m+2] = 0;  
    for(int i = 1; i <= m ;i++)  
        //如果下一个不是数字(也就是L的时候)   
        if(!scanf("%d",&is[i])) {  
            scanf("%s",s);  
            is[i] = NIL;  
        }  
}  
double f()  
{  
    memset(dp,0,sizeof(dp));  
    dp[0][0]=1.0;  
    for(int i = 0;i < t; i++)  
        for(int j = 0;j <= m; j++)   {  
            if(is[j+1] == NIL)  
                dp[i+2][j+1] += dp[i][j]*0.5;  
            else  
                dp[i+1][j+1+is[j+1]] += dp[i][j]*0.5;  
            if(is[j+2] == NIL)  
                dp[i+2][j+2] += dp[i][j]*0.5;  
            else  
                dp[i+1][j+2+is[j+2]] += dp[i][j]*0.5;  
        }  
    double res(0);  
    for(int i = 0; i <= t; i++)  
        res += dp[i][m+2]+dp[i][m+1];  
    return res;  
}  
int type(double x)  
{  
    //如果用下面注释掉的这个判断条件就会错   
    //if(fabs(x-0.5)<10e-7)   
    if(x==0.5)  
        return 1;  
    if(x > 0.5)  
        return 0;  
    return 2;  
}  
int main()  
{  
    int time;  
    scanf("%d",&time);  
    while(time--)   {  
        input();  
        double res;  
        res = f();  
        switch (type(res))  {  
            case 1:  
                printf("Push. 0.5000\n");  
                break;  
            case 0:  
                printf("Bet for. %.4f\n",res);  
                break;  
            default:  
                printf("Bet against. %.4f\n",res);  
        }  
    }  
    return 0;  
}  
