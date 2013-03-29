#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;
int a[3],n,m,t;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        a[0]=a[1]=a[2]=0;
        while(n--){
            scanf("%d",&m);
            a[m%3]++;
        }
        printf("%d\n",a[0]/2+min(a[1],a[2]));
    }
    //printf("%.6lf",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}