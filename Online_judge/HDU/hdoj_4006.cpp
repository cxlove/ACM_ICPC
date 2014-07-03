#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#define inf 110000000
#define M 10005
#define N 10005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define MOD 1000000007
using namespace std;
int n,m;
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        priority_queue<int,vector<int>,greater<int> >que;
        while(n--){
            char str[5];int k;
            scanf("%s",str);
            if(str[0]=='I'){
                scanf("%d",&k);
                que.push(k);
                if(que.size()>m)
                    que.pop();
            }
            else printf("%d\n",que.top());
        }
    }
    return 0;
}