#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[4][4]={{6,2,4,8},
             {1,3,9,7},
             {1,7,9,3},
             {1,9,1,9}};
int getsum(int n,int m){
    int ret=0;
    while(n){
         n/=m;
         ret+=n;
    }
    return ret;
}
int slove(int n,int m){
    if(n==0) return 0;
    return n/10+(n%10>=m)+slove(n/5,m);
}
int getsum2(int n,int m){
    if(n==0)  return 0;
    return getsum2(n/2,m)+slove(n,m);
}
int main(){
    int n,m;
    int num2,num5,num3,num7,num9;
    while(scanf("%d%d",&n,&m)!=EOF){
         num2=getsum(n,2)-getsum(n-m,2);
         num5=getsum(n,5)-getsum(n-m,5);
         num3=getsum2(n,3)-getsum2(n-m,3);
         num7=getsum2(n,7)-getsum2(n-m,7);
         num9=getsum2(n,9)-getsum2(n-m,9);
         if(num5>num2){
             printf("5\n");
             continue;
         }
         int ret=1;
         if(num2!=num5)
             ret=a[0][(num2-num5)%4];
         ret*=a[1][num3%4];
         ret*=a[2][num7%4];
         ret*=a[3][num9%4];
         printf("%d\n",ret%10);
    }
    return 0;
}
         
         
         
