#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#define LL long long
#define Key_value ch[ch[root][1]][0]  
using namespace std;
int n,k;
int a[10005];
int main(){
    cin>>n>>k;
    if(n==1&&k==1) cout<<1<<endl;
    else{
        for(int i=1;i<n;i++)
            a[i]=1;
        a[n]=0;
        int m=1;
        for(int i=0;i<k;i++){
            for(int j=1;j<=n;j++){
                if(n-j-a[j]<=m){
                    cout<<n-(n-j-a[j])<<" ";
                    m=max(m,n-j);
                    a[j]=n-j;
                }
                else{
                    cout<<n-m<<" ";
                    a[j]+=m;
                }
            }
            cout<<endl;
        }
    }
    return 0;
}