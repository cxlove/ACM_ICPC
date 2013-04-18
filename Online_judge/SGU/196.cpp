#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#define LL long long
#define MOD 1000000007
#define inf 2000000000LL
#define Key_value ch[ch[root][1]][0]  
using namespace std;
const int N= 100005;
int n,m;
int u[N],v[N],in[N];
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u[i]>>v[i];
        in[u[i]]++;
        in[v[i]]++;
    }
    int ans=0;
    for(int i=0;i<m;i++){
        ans+=in[u[i]]+in[v[i]];
    }
    cout<<ans<<endl;
    return 0;
}
