#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 10005
#define LL long long
#define inf 1<<29
#define eps 1e-7
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){    
        int k,cnt=0,ans=0;
        while(n--){
            scanf("%d",&k);
            if(k>1)
                cnt++;
            ans^=k;
        }
        if(cnt){
            if(ans==0)
                puts("No");
            else
                puts("Yes");
        }
        else{
            if(ans==0)
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}