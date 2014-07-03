#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#define N 10005
#define LL long long
#define inf 1<<29
#define eps 1e-7
using namespace std;
int main(){
    LL n;
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        LL sum=0,ans;
        for(LL i=1;;i++){
            if((i*i)-(i-1)*(i-1)-1>=n){
                ans=(i-1)*(i-1)+1+n-1;
                sum+=(i-1)*(n+1);
                break;
            }
            sum+=(i*i-(i-1)*(i-1))*(i-1);
            n-=(i*i-(i-1)*(i-1)-1);
        }
        cout<<ans<<" "<<sum<<endl;
    }
    return 0;

}
        