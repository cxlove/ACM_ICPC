#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <cstdio>
#include <climits>
#define H 1000000007
#define MOD 1217767
using namespace std;
const int N = 100005;
int vis[N<<1]={0};
int n,k;
int bfs(){
    queue<int>que;
    que.push(n);
    vis[n]=1;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        if(u==k) return vis[k]-1;
        if(u>0&&!vis[u-1]){
            vis[u-1]=vis[u]+1;
            que.push(u-1);
        }
        if(u<=200000&&!vis[u+1]){
            vis[u+1]=vis[u]+1;
            que.push(u+1);
        }
        if(2*u<=200000&&!vis[u*2]){
            vis[u*2]=vis[u]+1;
            que.push(2*u);
        }
    }
    return -1;
}
int main(){
    cin>>n>>k;
    cout<<bfs()<<endl;
    return 0;
}