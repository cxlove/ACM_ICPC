#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define LL long long
#define eps 1e-6
using namespace std;
double l;
int n;
int main(){
    scanf("%lf%d",&l,&n);
    int p=0,L=(int)(l*10000+0.001);
    for(int i=0;i<n;i++){
        int t,v;
        cin>>t>>v;
        p=((LL)p+(LL)t*v*10000)%L;
    }
    printf("%.4f\n",min((p/10000.0),l-(p/10000.0)));
    return 0;
}
