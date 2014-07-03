#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long 
using namespace std;
const int N = 1005;
int n,m;
int a[N],b[N];
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(!n&&!m) break;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&b[i]);
        double low=0,high=1,mid;
        while((high-low)>1e-6){
            mid=(low+high)/2.0;
            double d[N],sum=0;
            for(int i=0;i<n;i++)
                d[i]=(double)a[i]-mid*b[i];
            sort(d,d+n);
            for(int i=m;i<n;i++)
                sum+=d[i];
            if(sum>0) low=mid;
            else high=mid;
        }
        printf("%.0f\n",(high*100));
    }
    return 0;
}