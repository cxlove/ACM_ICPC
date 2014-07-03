#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define C    240
#define TIME 10
#define inf 1<<25
#define LL long long
using namespace std;
int main(){
    int n,a[100];
    while(scanf("%d",&n)!=EOF){
        int ret=0,k;
        if(n==0){
            puts("Yes");
            continue;
        }
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        int len=1;
        for(int i=1;i<n;i++)
            if(a[i]!=a[len-1])
                a[len++]=a[i];
        for(int i=0;i<len;i++){
            int k=a[i];
            int cnt=0,t=2*k;
            while(k){
                if(k&1)
                   cnt++;
                k>>=1;
            }
            if(cnt%2==0)
                ret^=t+1;
            else
                ret^=t;
        }
        puts(ret?"No":"Yes");
    }
    return 0;
}


