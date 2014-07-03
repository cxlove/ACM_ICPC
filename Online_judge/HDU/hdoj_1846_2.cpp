#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a,b;
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        if(a%(b+1)==0)
            printf("second\n");
        else
            printf("first\n");
    }
    return 0;
}