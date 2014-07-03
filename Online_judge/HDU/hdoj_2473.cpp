#include<iostream>  
#include<cstdio>  
#include<map>  
#include<cstring>  
#include<cmath>  
#include<vector>  
#include<stack>
#include<algorithm>  
#include<set>  
#include<string>  
#include<queue>  
#define inf 1600005  
#define M 1000005  
#define N 100005
#define maxn 2000005  
#define eps 1e-7
#define zero(a) fabs(a)<eps  
#define Min(a,b) ((a)<(b)?(a):(b))  
#define Max(a,b) ((a)>(b)?(a):(b))  
#define pb(a) push_back(a)  
#define mp(a,b) make_pair(a,b)  
#define mem(a,b) memset(a,b,sizeof(a))  
#define LL long long  
#define MOD 1000000007
#define lson step<<1
#define rson step<<1|1
#define sqr(a) ((a)*(a))  
#define Key_value ch[ch[root][1]][0]  
#define test puts("OK");
#define pi acos(-1.0)
#define lowbit(x) ((x)&(-(x)))
#pragma comment(linker, "/STACK:1024000000,1024000000")  
#define vi vector<int> 
using namespace std;
int n,m;
int pre[N*2+M];
int find(int x){
    return pre[x]=(pre[x]==x?x:find(pre[x]));
}
int main(){
    int cas=0;
    while(scanf("%d%d",&n,&m)!=EOF&&n+m){
        int tot=n+n;
        for(int i=0;i<n;i++) pre[i]=i+n;
        for(int i=n;i<n+n+m;i++) pre[i]=i;
        while(m--){
            char str[5];
            int u,v;
            scanf("%s",str);
            if(str[0]=='M'){
                scanf("%d%d",&u,&v);
                int ra=find(u),rb=find(v);
                if(ra!=rb) pre[ra]=rb;
            }
            else{
                scanf("%d",&u);
                pre[u]=tot++;
            }
        }
        int root[N];
        for(int i=0;i<n;i++) root[i]=find(i);
        sort(root,root+n);
        printf("Case #%d: %d\n",++cas,unique(root,root+n)-root);
    }
    return 0;
}