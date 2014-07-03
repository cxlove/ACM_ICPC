#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>
#include <queue>
#include <cmath>
#define LL long long 
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define pii pair<int,int>
#define sqr(a) ((double)(a)*(a))
using namespace std;
const int N = 2005;
struct Edge{
    int u,v,w;
    Edge(){}
    Edge(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
    bool operator<(const Edge n)const {
        return w<n.w;
    }
}e[N*N];
int n,m,pre[N],ans;
char str[N][10];
int find(int x){
    return pre[x]=(pre[x]==x?x:find(pre[x]));
}
void fuck(int a,int b,int c){
    int ra=find(a),rb=find(b);
    if(ra!=rb){
        pre[ra]=rb;
        ans+=c;
    }
}
int main(){
    while(scanf("%d",&n)!=EOF&&n){
        m=0;
        for(int i=0;i<n;i++)
            pre[i]=i;
        for(int i=0;i<n;i++)
            scanf("%s",str[i]);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cnt=0;
                for(int k=0;k<7;k++)
                    if(str[i][k]!=str[j][k])
                        cnt++;
                e[m++]=Edge(i,j,cnt);
            }
        }
        sort(e,e+m);
        ans=0;
        for(int i=0;i<m;i++){
            fuck(e[i].u,e[i].v,e[i].w);
        }
        printf("The highest possible quality is 1/%d.\n",ans);
    }
    return 0;
}