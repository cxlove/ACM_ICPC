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
#include<ctime>
#include<sstream>
#include<cassert>
#define LL long long
#define eps 1e-7
#define zero(a) fabs(a)<eps
#define inf 1<<30
#define N 20
#define pi acos(-1.0)
#define pb(a) push_back(a)
using namespace std;
struct Point{
    double x,y;
}p[700];
int n;
double angle[700];
LL cal(int n,int m){
    LL ret=1;
    for(int i=n;i>n-m;i--) ret=(LL)(ret*i);
    for(int i=1;i<=m;i++) ret/=i;
    return ret;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        LL ans=cal(n,4)-n*cal(n-1,3);
        for(int i=0;i<n;i++){
            int m=0,k=1;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                angle[m++]=atan2(p[j].y-p[i].y,p[j].x-p[i].x);
                if(angle[m-1]<eps) angle[m-1]+=2*pi;
            }
            sort(angle,angle+m);
            for(int j=m;j<2*m;j++)
                angle[j]=angle[j-m]+2*pi;
            for(int j=0;j<m&&k<2*m;j++){
                while(k<2*m&&angle[k]-angle[j]<pi) k++;
                if(k-j-1>1) ans+=cal(k-j-1,2);
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

