#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cctype>
#include <map>
#include <iomanip>
                   
using namespace std;
                   
#define eps 1e-8
#define pi acos(-1.0)
#define inf 1<<30
#define linf 1LL<<60
#define pb push_back
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define ll long long

int k,s;

void solve(int s,int k) {
    if (k%2==1) printf("%d\n",s%2);
    else {
        if (s%(k+1)==k) printf("%d\n",k);
        else printf("%d\n",(s%(k+1))%2);
    }
    return ;
}

int main() 
{
    int T;
    scanf("%d",&T);
    while (T--){
          scanf("%d%d",&s,&k);
          solve(s,k);            
    }
    return 0;
}
