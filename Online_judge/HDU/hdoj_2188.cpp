#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[105],t;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);
        if(m<=n)
            printf("Grass\n");
        else if(m%(n+1)==0)
            printf("Rabbit\n");
        else
            printf("Grass\n");
    }
    return 0;
}