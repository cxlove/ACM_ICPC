#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#define pb(a) push_back(a)
using namespace std;
int n,a,b;
bool win(){
    int t=b,m=n/2+1;
    vector<int>v;
    if(a>=m){
        for(int i=0;i<m;i++)
            v.pb(a/m);
        for(int i=0,j=v.size()-1;i<(a%m);i++,j--)
            v[j]++;
    }
    else{
        if(a>b) return true;
        else return false;
    }
    int c1=0,c2=0;
    for(int i=0;i<v.size()&&c1+c2<n;i++){
        if(t>v[i]){
            t-=v[i]+1;
            i--;
            c2++;
        }
        else if(v[i]) c1++;
    }
    while(c1+c2<n&&t){
        if(t) c2++;
        t--;
    }
    return c1>c2;
}
bool tie(){
    int t=b,m=(n+1)/2;
    vector<int>v;
    if(a>=m){
        for(int i=0;i<m;i++)
            v.pb(a/m);
        for(int i=0,j=v.size()-1;i<(a%m);i++,j--)
            v[j]++;
    }
    else{
        if(b==a) return true;
        return false;
    }
    int c1=0,c2=0;
    for(int i=0;i<m&&c1+c2<n;i++){
        if(t>v[i]){
            t-=v[i]+1;
            i--;
            c2++;
        }
        else if(v[i]) c1++;
    }
    while(c1+c2<n&&t){
        if(t) c2++;
        t--;
    }
    return c1>=c2;
}
int main(){
     //freopen("input.txt","r",stdin);
     //freopen("output.txt","w",stdout);
    while(scanf("%d%d%d",&n,&a,&b)!=EOF){
        if(n==0){
            puts("0");
            continue;
        }
        if(win()) puts("1");
        else if(tie()) puts("0");
        else puts("-1");
    }
    return 0;
}