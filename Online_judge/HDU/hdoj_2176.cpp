#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#define LL long long
#define N 1000000
#define inf 1<<20
using namespace std;
int main(){
    int n,a[200005];
    while(scanf("%d",&n)!=EOF&&n){
        int ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            ans^=a[i];
        }
        if(ans==0)
            puts("No");
        else{
            puts("Yes");
            for(int i=0;i<n;i++)
                if((ans^a[i])<=a[i])
                    printf("%d %d\n",a[i],a[i]^ans);
        }
    }
    return 0;
}