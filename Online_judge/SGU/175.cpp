#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define LL long long
using namespace std;
int n,q;
//f为1说明区间反转
int dfs(int n,int q,int f){
    if(n==1) return 1;
    int k=n/2;
    if(f==0){
        if(q>k) return dfs(n-k,q-k,1);
        else return n-k+dfs(k,q,1);
    } 
    else{
        if(q<=(n-k)) return dfs(n-k,q,0);
        else return n-k+dfs(k,q-(n-k),0); 
    }
}
int main(){
    cin>>n>>q;
    cout<<dfs(n,q,0)<<endl;
    return 0;
}
