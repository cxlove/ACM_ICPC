#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100005;
int n,m,dep[N];
bool bus(){
    if(m!=n-1) return false;
    int s=0,e=0,m=0;
    for(int i=0;i<n;i++){
        if(dep[i]==1) s++;
        else if(dep[i]==2) m++;
    }
    if(s==2&&m==n-2) return true;
    return false;
}
bool ring(){
    if(m!=n) return false;
    for(int i=0;i<n;i++)
        if(dep[i]!=2)
            return false;
    return true;
}
bool star(){
    if(m!=n-1) return false;
    for(int i=0;i<n;i++)
        if(dep[i]==1||dep[i]==n-1);
        else return false;
    return true;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;u--;v--;
        dep[u]++;dep[v]++;
    }
    if(bus()) puts("bus topology");
    else if(ring()) puts("ring topology");
    else if(star()) puts("star topology");
    else puts("unknown topology");
    return 0;
}