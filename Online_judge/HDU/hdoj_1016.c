#include<stdio.h>
int pri[40]={0},n,flag[20];
void dfs(int num,int j,int a[20])
{
    int k,i;
    if(j==n&&pri[num+1]==1)
    {
        printf("1");
        for(k=1;k<j;k++)
        {
            printf(" %d",a[k]);
        }
        printf("\n");
        return ;
    }
    for(i=2;i<=n;i++)
    {
        if(pri[num+i]==1&&flag[i]==0)
        {
            flag[i]=1;
            a[j]=i;            
            dfs(i,1+j,a);
            flag[i]=0;
        }
    }
}

int main()
{
    int i,t=0,j,a[20];
    pri[2]=pri[3]=pri[5]=pri[7]=pri[11]=pri[13]=pri[17]=pri[19]=pri[23]=pri[29]=pri[31]=pri[37]=1;
    while(scanf("%d",&n)!=EOF)
    {
        memset(flag,0,sizeof(flag));
        t++;
        printf("Case %d:\n",t);
        dfs(1,1,a);
        printf("\n");
    }
    return 0;
}




    
