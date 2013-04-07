#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <algorithm>
#define LL long long

using namespace std;
int n;
int id(int x,int y){
    return (x-1)*n+y;
}
int main(){
    cin>>n;
    cout<<n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i-1+j-1>n)
                cout<<" "<<id(i,j);
    cout<<endl;
    int dis=n;
    int now=n;
    while(dis>0){
        now++;
        if(!(now&1))
            now++;
        cout<<now;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i-1+j-1==dis)
                    cout<<" "<<id(i,j);
        cout<<endl;
        dis--;
    }
    return 0;
}
