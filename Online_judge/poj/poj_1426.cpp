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
int n;
struct Node{
    int m;
    string s; 
}s,u,v;
bool flag[1000];
void bfs(){
    s.m=1;s.s="1";
    queue<Node>que;
    que.push(s);
    memset(flag,false,sizeof(flag));
    while(!que.empty()){
        u=que.front();
        que.pop();
        if(u.s.size()>=100) continue;
        for(int i=0;i<2;i++){
            v=u;
            v.m=(v.m*10+i)%n;
            v.s+=(char)(i+'0');
            if(v.m==0){
                cout<<v.s<<endl;
                return ;
            }
            if(flag[v.m]==false){
                flag[v.m]=true;
                que.push(v);
            }
        }
    }

}
int main(){
    while(cin>>n&&n){
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        bfs();
    }
    return 0;
}