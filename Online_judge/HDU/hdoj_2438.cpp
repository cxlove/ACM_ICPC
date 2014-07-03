#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define eps 1e-7
using namespace std;
double x,y,l,w;
double cal(double a){
    return (x-l*sin(a)-w/cos(a))/tan(a);
}
int main(){
    while(scanf("%lf%lf%lf%lf",&x,&y,&l,&w)!=EOF){
        double low=0,high=acos(-1.0)/2,mid,midd;
        while(fabs(high-low)>eps){
            mid=(low+high)/2;
            midd=(mid+high)/2;
            if(cal(mid)<cal(midd))
                high=midd;
            else
                low=mid;
        }
        if(cal(low)<-y||x<w||y<w)  puts("no");
        else puts("yes");
    }
    return 0;
}
