#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[105];
int main(){
    while(scanf("%d",&n)!=EOF&&n){
        int ans=0,t;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            ans^=a[i];
        }
        int cnt=0;
        if(ans){
            for(int i=0;i<n;i++)
                if(a[i]>=(a[i]^ans))
                    cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}


