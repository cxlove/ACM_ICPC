#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define LL long long 
using namespace std;
const int N = 1005;
int n,m;
int a[N],b[N],c[N];
double d[N];
bool cmp(int a,int b){
    return d[a]<d[b];
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(!n&&!m) break;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&b[i]);
        double ans,mid=0.5;
        while(true){
            ans=mid;
            double p=0.0,q=0.0;
            for(int i=0;i<n;i++)
                d[i]=(double)a[i]-mid*b[i],c[i]=i;
            sort(c,c+n,cmp);
            for(int i=m;i<n;i++)
                p+=a[c[i]],q+=b[c[i]];
            mid=p*1.0/q;
            if(fabs(mid-ans)<1e-5) break;
        }
        printf("%d\n",(int)(ans*100+0.5));
    }
    return 0;
}