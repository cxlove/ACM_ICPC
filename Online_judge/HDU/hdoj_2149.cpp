#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int main(){
    while(scanf("%d%d",&m,&n)!=EOF&&n){
        if(m<=n){
            printf("%d",m);
            for(int i=m+1;i<=n;i++)
                printf(" %d",i);
            printf("\n");
        }
        else if(m%(n+1)==0)
            printf("none\n");
        else
            printf("%d\n",m%(n+1));
    }
    return 0;
}