#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include<iostream>
using namespace std;
int main()
{
    int r[2000],i,j,s,k,m,n;
    double c[2000],f[2000],t,sum;
    while(scanf("%d%d",&m,&n))
    {
        if(m==-1&&n==-1)break;
        for(i=0;i<n;i++)
        {
            scanf("%lf%d",&f[i],&r[i]);
            c[i]=f[i]/r[i];
        }
        for(i=0;i<n-1;i++)
        {
            k=i;
            for(j=i+1;j<n;j++)
                if(c[k]<c[j])k=j;
            
            swap(c[i],c[k]);
            swap(r[i],r[k]);
            swap(f[i],f[k]);
        }
        sum=0;
        for(i=0;i<n;i++)
        {
            if(m>r[i])
            {
                sum+=f[i];
                m-=r[i];
            }
            else
               {
                  sum+=m*c[i];
                  break;
               }
        }
        printf("%.3f\n",sum);
    }
    return 0;
}