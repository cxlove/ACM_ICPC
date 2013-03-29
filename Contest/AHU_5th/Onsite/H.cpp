#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
#include<iostream>
#include<string>
#define N 100005
#define pb(a) push_back(a)
using namespace std;
int t;
int n,m,k;
vector<int>v[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<n;i++){
            int num;
            scanf("%d",&num);
            v[num].pb(i);
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            for(int l=0,r=0;l<v[i].size();l++){
                while(r<v[i].size()&&v[i][r]-v[i][l]-(r-l)<=k) 
                    r++;
                ans=max(ans,r-l);
            }
        }
        printf("%d\n",ans);
        for(int i=1;i<=m;i++) v[i].clear();
    }
    return 0;
}