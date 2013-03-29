#include<ctime>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<bitset>
using namespace std;
int t,cas=0,n;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        int cnt=0;
        for(int i=0;i<31;i++){
            if( (1<<i)&n ){
                if( !((1<<(i+1))&n) ){
                    n+=1<<i;
                    n+=(1<<cnt)-1;
                    break;
                }
                else n-=1<<i,cnt++;
            }
        }
        cout<<n<<endl;
    }
    return 0;
}