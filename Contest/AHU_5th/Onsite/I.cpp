#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
#include<iostream>
#include<string>
using namespace std;
int a[2],b[2],n,m,t;
int main(){
    cin>>t;
    while(t--){
        a[0]=a[1]=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>m;
            a[m%2]++;
            b[m%2]=i+1;
        }
        cout<<(a[0]==1?b[0]:b[1])<<endl;
    }
    return 0;
}