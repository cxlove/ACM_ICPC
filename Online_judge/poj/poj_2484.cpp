/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#define N 10005
#define LL long long
#define inf 1<<29
#define eps 1e-7
using namespace std;
vector<int>v[100005];
vector<int>root;
int get_sg(int u,int pre){
    int ret=0;
    for(int i=0; i<v[u].size(); i++)
        if(v[u][i]!=pre)
            ret^=(1+get_sg(v[u][i],u));
    return ret;
}
int main(){
    int t,n;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++)
            v[i].clear();
        root.clear();
        for(int i=1;i<=n;i++){
            int k;
            scanf("%d",&k);
            if(k==-1)
                root.push_back(i);
            else
                v[k].push_back(i);
        }
        int ret=0;
        for(int i=0;i<root.size();i++)
            ret^=get_sg(root[i],-1);
        if(ret)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
*/
#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n&&n){
        if(n<=2)
            cout<<"Alice"<<endl;
        else
            cout<<"Bob"<<endl;
    }
    return 0;
}
