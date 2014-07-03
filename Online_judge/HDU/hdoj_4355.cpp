#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define C    240
#define TIME 10
#define eps 1e-7
#define inf 1<<25
#define LL unsigned long long
using namespace std;
struct Node{
    double x;
    double w;
}a[50005];
int n;
double cal(double pos){
    double sum=0;
    for(int i=0;i<n;i++)
        sum+=fabs(a[i].x-pos)*fabs(a[i].x-pos)*fabs(a[i].x-pos)*a[i].w;
    return sum;
}
int main(){
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        double low=1000000,high=-1000000;
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&a[i].x,&a[i].w);
            low=min(low,a[i].x);
            high=max(high,a[i].x);
        }
        printf("Case #%d: ",++cas);
        double midd,mid=(low+high)/2;
        while(fabs(high-low)>=eps){
            mid=(low+high)/2;
            midd=(mid+high)/2;
            if(cal(mid)+eps<cal(midd))
                high=midd;
            else
                low=mid;
        }
        double dist=cal(low);
        printf("%.0f\n",dist);
    }
    return 0;

}
