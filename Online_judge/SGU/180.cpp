#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#define LL long long
#define Key_value ch[ch[root][1]][0]  
#define lowbit(x) (x&(-x))
using namespace std;
const int N=66666;
int a[N],n,m,s[N],b[N];
void add(int x,int val=1){
    for(int i=x;i<=m;i+=lowbit(i))
        s[i]+=val;
}
int sum(int x){
    int ret=0;
    for(int i=x;i;i-=lowbit(i))
        ret+=s[i];
    return ret;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    b[0]=-1;
    sort(b+1,b+1+n);
    LL ans=0;
    m=unique(b,b+1+n)-b-1;
    for(int i=1;i<=n;i++){
        int pos=lower_bound(b,b+m+1,a[i])-b;
        ans+=(LL)(i-1)-sum(pos);
        add(pos);
    }
    printf("%lld\n",ans);
    return 0;
}
