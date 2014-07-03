#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define eps 1e-10
#define N (1<<7)+5
#define inf 1<<20
#define zero(a) (fabs(a)<eps)
#define lson (step<<1)
#define rson (step<<1|1)
using namespace std;
char str[100];
int main(){
    while(scanf("%s",str)!=EOF&&strcmp(str,"#")){
        int one=0,l=strlen(str);
        for(int i=0;i<strlen(str)-1;i++)
            if(str[i]=='1') one++;
        if(str[l-1]=='o'){
            if(one&1) str[l-1]='0';
            else str[l-1]='1';
        }
        else {
            if(one&1) str[l-1]='1';
            else str[l-1]='0';
        }
        printf("%s\n",str);
    }
    return 0;
}
