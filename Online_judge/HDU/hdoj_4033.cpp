#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define eps 1e-9
#define zero(a) (fabs(a)<eps)
#define pi acos(-1.0)
#define inf 20000
using namespace std;
double d[105];
int main(){
    int t,cas=0,i,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lf",&d[i]);
        d[n]=d[0];
        double low=0,high=inf,mid;
        while(!zero(high-low)){
            mid=(high+low)/2.0;
            double tmp=0;
            for(i=0;i<n;i++){
                if(mid>d[i]+d[i+1]){tmp=3*pi;break;}
                if(mid<fabs(d[i]-d[i+1])){tmp=0;break;}
                tmp+=acos((d[i]*d[i]+d[i+1]*d[i+1]-mid*mid)/(2*d[i]*d[i+1]));
            }
            if(tmp>2*pi) high=mid;
            else low=mid;
        }
        double tmp=0;
        for(i=0;i<n;i++){
            if(mid>d[i]+d[i+1]){tmp=3*pi;break;}
            if(mid<fabs(d[i]-d[i+1])){tmp=0;break;}
            tmp+=acos((d[i]*d[i]+d[i+1]*d[i+1]-mid*mid)/(2*d[i]*d[i+1]));
        }
        printf("Case %d: ",++cas);
    //    cout<<tmp<<" "<<2*pi<<endl;
        if(zero(tmp-2*pi)) printf("%.3f\n",mid);
        else printf("impossible\n");
        
    }
    return 0;
}


