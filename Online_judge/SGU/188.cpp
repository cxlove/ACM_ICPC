#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#define LL long long
#define mp(a,b) make_pair(a,b)
using namespace std;
const int N = 25;
int n,t;
int l[N],v[N];
int ans[N]={0};
bool check(int l1,int r1,int l2,int r2){
    if(l1<l2&&r1<l2) return false;
    if(l2<l1&&r2<l1) return false;
    return true;  
}
int main(){
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;i++)
        scanf("%d",&l[i]);
    for(int j=1;j<=n;j++)
        scanf("%d",&v[j]);
    for(int i=1;i<=t;i++){
        for(int j=1;j<=n;j++){
            if(v[j]<0) continue;
            int l1=l[j],r1=l[j]+v[j];
            for(int k=1;k<=n;k++){
                if(v[k]>0) continue;
                int r2=l[k],l2=l[k]+v[k];
                int flag=0;
                if(l1==r2) continue;
                if(check(l1,r1,l2,r2))
                    ans[j]++,ans[k]++;
                else if(check(l1+1000,r1+1000,l2,r2))
                    ans[j]++,ans[k]++;
                else if(check(l1-1000,r1-1000,l2,r2))
                    ans[j]++,ans[k]++;
            }
        }
        for(int j=1;j<=n;j++)
            l[j]=(l[j]+v[j]+1000)%1000;
    }
    for(int j=1;j<=n;j++)
        printf("%d%c",ans[j],j==n?'\n':' ');
    return 0;
}
