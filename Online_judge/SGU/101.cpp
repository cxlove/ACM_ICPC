#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
struct Node{
    int a,b;
}d[1000],ans[1000];
int n,tot=0;
int dep[10][10],out[10];
void dfs(int u){
    for(int i=0;i<7;i++){
        if(dep[u][i]){
            dep[u][i]--;
            dep[i][u]--;
            dfs(i);
            ans[tot].a=u;
            ans[tot].b=i;
            tot++;
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>d[i].a>>d[i].b;
        dep[d[i].a][d[i].b]++;
        dep[d[i].b][d[i].a]++;
        out[d[i].a]++;
        out[d[i].b]++;
    }
    int st=-1,cnt=0;
    for(int i=0;i<7;i++)
        if(out[i]&1)
            cnt++,st=i;
        else if(out[i]&&st==-1)
            st=i;
    if(cnt>2) puts("No solution");
    else{
        dfs(st);
        if(tot<n){
            puts("No solution");
            return 0;
        }
        for(int i=tot-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(ans[i].a==d[j].a&&ans[i].b==d[j].b){
                    printf("%d +\n",j+1);
                    d[j].a=-1;
                    break;
                }
                else if(ans[i].b==d[j].a&&ans[i].a==d[j].b){
                    printf("%d -\n",j+1);
                    d[j].a=-1;
                    break;
                }
            }
        }
    }
    return 0;
}
