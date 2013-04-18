#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#define LL long long
#define MOD 1000000007
#define inf 2000000000LL
#define Key_value ch[ch[root][1]][0]  
using namespace std;
const int N=100005;
struct Node{
    int s,w,idx;
    bool operator<(const Node n)const{
        return s!=n.s?s<n.s:w>n.w;
    }
}a[N];
int n;
int ans[N],tot=0,pre[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        a[i].idx=i;
        scanf("%d%d",&a[i].s,&a[i].w);
    }
    sort(a+1,a+1+n);
    ans[++tot]=1;
    for(int i=2;i<=n;i++){
        if(a[i].w>a[ans[tot]].w)
            ans[++tot]=i,pre[i]=ans[tot-1];
        else{
            int low=1,high=tot,mid,ret=1;
            while(low<=high){
                mid=(low+high)>>1;
                if(a[i].w<=a[ans[mid]].w)
                    ret=mid,high=mid-1;
                else
                    low=mid+1;
            }
            ans[ret]=i;
            pre[i]=ans[ret-1];
        }
    }
    printf("%d\n",tot);
    for(int i=ans[tot];i;i=pre[i])
        printf("%d%c",a[i].idx,pre[i]==0?'\n':' ');
    return 0;
}
