#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
#include<cassert>
#define LL long long
#define eps 1e-6
#define inf 1ll<<50
#define zero(a) fabs(a)<eps
#define N 20005
using namespace std;
struct Node{
    int l,r,h;
    int level;
}a[50005];
int n;
double cal(double height){
    double sum=0;
    for(int i=0;i<n;i++)
        if(height>a[i].level)
            sum+=a[i].l*a[i].r*min(height-a[i].level,(double)a[i].h);
    return sum;
}
int main(){
    int t,v;
    //freopen("f.in","r",stdin);
    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        int sum=0;
        int mmax=0;
        for(int i=0;i<n;i++){
            scanf("%d%d%d%d",&a[i].level,&a[i].h,&a[i].r,&a[i].l);
            sum+=a[i].l*a[i].r*a[i].h;
            mmax=max(mmax,a[i].level+a[i].h);
        }
        scanf("%d",&v);
        if(sum<v){
            puts("OVERFLOW");
            continue;
        }
        if(sum==v){
            printf("%d.00\n",mmax);
            continue;
        }
        double low=0,mid,high=mmax;
        while(fabs(high-low)>eps){
            mid=(low+high)/2.0;
            double tmp=cal(mid);
        //    cout<<mid<<" "<<tmp<<endl;
            if(tmp+eps>v) high=mid;
            else low=mid;
        }
        printf("%.2f\n",mid);
    }
    return 0;
}


