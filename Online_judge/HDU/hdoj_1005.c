#include<stdio.h>
int main()
{
    int j,i,a,b,n,f[1000],m,qd,zd,flag;
    
    while(scanf("%d%d%d",&a,&b,&n),a!=0||b!=0||n!=0)
    {f[1]=1;
    f[2]=1;
    flag=0;
        for(i=3;i<=50;i++)    
        {    
            
            f[i]=(f[i-1]*a+f[i-2]*b)%7;        
            for(j=1;i<i;j++)
            {
                if(f[i-1]==f[j]&&f[i]==f[j+1])
                {
                    flag=1;break;
                }
            }
            if(flag) break;
        }
        qd=j;zd=i-2;
        if(n<qd)
            printf("%d\n",f[n]);
        else
        {
            m=(n-j+1)%(i-2-j+1);
            if(m==0)
                printf("%d\n",f[i-2]);
            else
                printf("%d\n",f[j+m-1]);
        }

    }
    return 0;
}


        

