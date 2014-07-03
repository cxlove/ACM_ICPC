#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <string>
#define MAGIC 157
#define eps 1e-8
#define LL long long
#define Test puts("END")
using namespace std;
const int MOD = 1000000007;
const int INF = 1000000000;
const int N = 2000100;
const int M = 1000100;

char s[N];
int fac[N],hash[N],reHash[N],length;

void make_hash(){
    hash[0] = s[0];
    for(int i = 1;i < length;i ++)
        hash[i] = hash[i - 1] * MAGIC + s[i];
    reHash[0] = s[length - 1];
    for(int i = length - 2;i >= 0;i --)
        reHash[length - 1 - i] = reHash[length - 2 - i] * MAGIC + s[i];
}

int getHash(int l,int r){
    if(l == 0) return hash[r];
    else return hash[r] - hash[l - 1] * fac[r - l + 1];
}

int getReHash(int l,int r){
    int L = l;
    l = length - 1 - r;
    r = length - 1 - L;
    if(l == 0) return reHash[r];
    else return reHash[r] - reHash[l - 1] * fac[r - l + 1];
}

bool check(int limit){
    for(int i = 0;i + limit - 1 < length;i ++){
        int a = getHash(i,i + limit - 1);
        int b = getReHash(i,i + limit - 1);
        if(a == b) return true;
    }
    return false;
}

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("my.txt","w",stdout);
    fac[0] = 1;
    for(int i = 1;i < N;i ++)
        fac[i] = fac[i - 1] * MAGIC;
    int cas = 1;
    while(scanf("%s",s)  && s[0] != 'E'){
        length = strlen(s);
        make_hash();
        int l = 1,r = (length + 1) / 2;//odd 
        int ans = -1;
        // printf("check:%d\n",check(13));
        while(l <= r){
            int mid = (l + r) >> 1;
            int num = (mid << 1) - 1;
            // printf("mid:%d check:%d\n",mid,check(mid));
            if(check(num)){
                ans = max(ans,num);
                l = mid + 1;
            }
            else r = mid - 1;
        }
        l = 1 , r = length / 2;//even
        while(l <= r){
            int mid = (l + r) >> 1;
            int num = mid << 1;
            if(check(num)){
                ans = max(ans,num);
                l = mid + 1;
            }
            else r = mid - 1;
        }
        printf("Case %d: %d\n",cas ++,ans);
    }
    return 0;
}