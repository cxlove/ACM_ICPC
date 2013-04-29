//列出方程，消元
//n分奇偶讨论，如果为偶数，要么无解，要么无穷多解
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N = 100005;
int n;
double x[N],y[N];
double ax[N],ay[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&x[i],&y[i]);
    }
    double tx=0,ty=0;
    for(int i=n;i>1;i-=2){
        tx+=2*x[i];ty+=2*y[i];
        tx-=2*x[i-1];ty-=2*y[i-1];
    }
    if(n%2==0){
        if(tx!=0||ty!=0){
            puts("NO");
            return 0;
        }
        ax[1]=x[1]-0.5;ay[1]=y[1]-0.5;
    }
    else{
        tx+=2*x[1];ty+=2*y[1];
        ax[1]=tx/2.0;ay[1]=ty/2.0;
    }
    for(int i=1;i<n;i++)
        ax[i+1]=2*x[i]-ax[i],ay[i+1]=2*y[i]-ay[i];
    puts("YES");
    for(int i=1;i<=n;i++)
        printf("%.3f %.3f\n",ax[i],ay[i]);
    return 0;
}
