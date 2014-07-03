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
using namespace std;
int main(){
    int t,cas=0,a[105],n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
            scanf("%d",&a[i]);
        sort(a,a+m);
        int sum=0,cnt=n/a[0];
        printf("Case #%d: ",++cas);
        puts(!(cnt&1)?"Alice":"Bob");
    }
}


