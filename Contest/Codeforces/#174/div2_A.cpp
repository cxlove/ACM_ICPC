#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<ctime>
using namespace std;
int eular(int n){
    int ret=1;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ret*=i-1;
            n/=i;
            while(n%i==0){
                n/=i;
                ret*=i;
            }
        }
    }
    if(n>1) ret*=n-1;
    return ret;
}
int n;
int main(){
    cin>>n;
    cout<<eular(n-1);
    return 0;
}