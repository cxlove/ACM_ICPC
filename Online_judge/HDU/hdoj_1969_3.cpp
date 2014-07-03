#include<iostream>
#include<cstdio>
#include<cmath>
#define pi acos(-1.0)
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,f;
        int a[10001];
        cin>>n>>f;
        for(int i=0;i<n;i++)
            cin>>a[i];
        double high=10000*10000*pi;
        double low=0;
        double mid;
        while(high-low>0.0000001)
        {
            mid=(high+low)/2;
            int count=0;
            for(int i=0;i<n;i++)
                count+=(int)((a[i]*a[i])*pi/mid);
            if(count>=f+1)
                low=mid;
            else
                high=mid;
        }
        printf("%.4lf\n",mid);
    }
    return 0;
}



