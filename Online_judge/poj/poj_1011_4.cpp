#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 70

int n,a[SIZE];
int v[SIZE];
int cmp(void const * a,void const * b)
{
    return *(int *)b-*(int *)a;
}
int dfs(int i,int amount,int left,int len)
{
    if(amount==0&&left==0) return 1;
    else
    {
        if(left==len||left==0) left=len,i=0;
        else i++;
        for(;n-i>0;i++)
        {
            if(v[i]==0&&a[i]<=left)
            {
                if(i>0&&a[i-1]==a[i]&&v[i-1]==0) continue;
                v[i]=1;
                if(dfs(i,amount-1,left-a[i],len)) return 1;
                v[i]=0;
                if(a[i]==left||len==left) return 0;
            }
        }
        return 0;
    }
}
int main()
{

    while(scanf("%d",&n),n)
    {
        int sum=0;
        for(int i=0;n-i>0;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        qsort(a,n,sizeof(int),cmp);
        bool ok=0;
        memset(v,0,sizeof(v));
	//	printf("%d\n",dfs(0,n,sum,sum));
        for(int i=a[0];sum/2-i>=0;i++)
        {
            if(sum%i==0&&dfs(0,n,i,i))
            {
                printf("%d\n",i);
                ok=1;
                break;
            }
        }
        if(ok==0) printf("%d\n",sum);
    }
    return 0;
}
