#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>
#define N 10005
#define abs(a) ((a)<0?-(a):(a))
using namespace std;
int n,a[N],m,t;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)  scanf("%d",&a[i]);
        sort(a,a+n);
        int ans=0;
        for(int i=0;i<min(n,m)&&a[i]<0;i++)
            ans+=a[i];
        printf("%d\n",-ans);
    }
    //printf("%.6lf",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}