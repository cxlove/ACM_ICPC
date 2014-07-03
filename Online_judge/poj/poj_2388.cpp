#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,a[10000];
int main(){
    while(cin>>n){
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        cout<<a[n/2]<<endl;
    }
    return 0;
}