#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 100005
#define inf 1<<29
#define MOD 2007
#define LL long long
using namespace std;
struct Node{
    int val;//循环中的最小值
    int cnt;//循环节长度
}a[N];
int n,m[N],tot,t[N];
bool flag[N];
void dfs(int u){
    for(int i=0;i<n;i++){
        if(t[i]==u&&!flag[i]){
            flag[i]=true;
            a[tot].cnt++;
            a[tot].val=min(a[tot].val,t[i]);
            dfs(m[i]);
        }
    }
}
int main(){
    while(scanf("%d",&n)!=EOF){
        int sum=0,mmin=1<<30;
        for(int i=0;i<n;i++){
            scanf("%d",&m[i]);
            sum+=m[i];
            t[i]=m[i];
            mmin=min(mmin,m[i]);
        }
        sort(m,m+n);
        tot=0;
        for(int i=0;i<n;i++){
            if(flag[i])  continue;
            a[tot].val=t[i];
            a[tot].cnt=1;
            flag[i]=true;
            dfs(m[i]);
            tot++;
        }
        for(int i=0;i<tot;i++)
            sum+=min(a[i].val*(a[i].cnt-2),mmin*(a[i].cnt+1)+a[i].val);
        printf("%d\n",sum);
    }
    return 0;

}

