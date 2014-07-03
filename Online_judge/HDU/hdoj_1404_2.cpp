#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int sg[1000005];
int getlen(int n){
    if(n/100000) return 6;
    if(n/10000) return 5;
    if(n/1000) return 4;
    if(n/100) return 3;
    if(n/10) return 2;
    return 1;
}
void getsg(int x){
    int len=getlen(x);
    for(int i=1;i<=len;i++){
        int bit=x,base=1;
        for(int j=1;j<i;j++)
            base*=10;
        for(int j=1;j<i;j++)
            bit/=10;
        bit=bit%10;
        for(int j=bit+1;j<=9;j++)
            sg[x-bit*base+j*base]=1;
    }
    if(len!=6){
        sg[x*10]=1;
        for(int i=len+2,base=10;i<=6;i++,base*=10){
            int t=x*10*base;
            for(int j=0;j<base;j++)
                sg[t+j]=1;
        }
    }
}
int main(){
    memset(sg,0,sizeof(sg));
    sg[0]=1;
    for(int i=1;i<1000000;i++)
        if(sg[i]==0)
            getsg(i);
    int n;
    while(scanf("%d",&n)!=EOF){
        if(sg[n])
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
        
