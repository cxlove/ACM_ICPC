#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#define LL long long
#define db puts("BEGIN");
#define de puts("END");
#define inf 2000000000LL
#define Key_value ch[ch[root][1]][0]  
using namespace std;
int n,a[100];
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int mx=1,t=1;
    for(int i=1;i<n;i++)
        if(a[i]==a[i-1]) t++;
        else mx=max(mx,t),t=1;
    mx=max(mx,t);
    if(mx>(n+1)/2) puts("NO");
    else puts("YES");
    return 0;
}
