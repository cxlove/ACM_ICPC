#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n,k,m,a[1005];
int main(){
    cin>>n>>k;
    m=k%n;
    int p;
    for(p=1;(k*p+1)%n;p++);
    //cout<<p<<endl;
    for(int i=n-1,j=0;j<m;j++,i=(i-p+n)%n)
        a[i+1]=1;
    for(int i=1;i<=n;i++)
        cout<<a[i]+k/n<<(i==n?'\n':' ');
    return 0;
}
