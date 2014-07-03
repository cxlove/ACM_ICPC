#include<cstdio>

int main ()
{
    long long n,i,phi;
    while(scanf("%lld",&n)!=EOF)
    {
        phi=1;
        for(i=2;i*i<=n;++i)             
        {   
            if(n%i!=0)
                continue;
            long long p=0,t=1;   
            while(n%i==0)   
            {
                n=n/i;
                p++;
                t*=i;
            }
            phi*=p*(t-t/i)+t;    //F[P^k]=k×(P^k-P^(k-1))+P^k (P为质数)       

        }
        if(n!=1)   
            phi*=2*n-1;              
        printf("%lld\n",phi);       
    }
    return 0;
}
