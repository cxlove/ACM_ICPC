#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <climits>
#define H 1000000007
#define MOD 1217767
using namespace std;
const int N = 100005;
int n,k;
int s[N][30]={0},a[N];
int v[N][30];
pair<int,int> HASH[MOD];
int hash(int *v){
    int h=0;
    for(int i=0;i<k;i++){
        h=h*H+v[i];
    }
    return h;
}
void init(){
    for(int i=0;i<MOD;i++)
        HASH[i]=make_pair(INT_MAX,i);
}
void insert(int h,int id){
    int p=h%MOD;if(p<0)p=-p;
    while(HASH[p].first!=INT_MAX&&HASH[p].first!=h){
        p++;if(p>=MOD) p-=MOD;
    }
    if(HASH[p].first==INT_MAX) HASH[p]=make_pair(h,id);
}
int ans=0;
bool find(int h,int i){
    int p=h%MOD;if(p<0)p=-p;
    while(HASH[p].first!=INT_MAX&&HASH[p].first!=h){
        p++;if(p>=MOD) p-=MOD;
    }
    if(HASH[p].first==h) ans=max(HASH[p].second-i,ans);
    return HASH[p].first==h;
}
int main(){
    while(scanf("%d%d",&n,&k)!=EOF){
        init();
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            for(int j=0;j<k;j++){
                s[i][j]=s[i-1][j]+((a[i]&(1<<j))!=0);
                v[i][j]=(s[i][j]-s[i][0]);
            }
        }
        insert(hash(v[n]),n);
        for(int i=n-1;i>=0;i--){
            int h=hash(v[i]);
            if(!find(h,i)){
                insert(h,i);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}