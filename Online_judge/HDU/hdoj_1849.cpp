#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int main(){
    while(scanf("%d",&n)!=EOF&&n){
        int ans=0,t;
        for(int i=0;i<n;i++){
            scanf("%d",&t);
            ans^=t;
        }
        if(ans==0)
            printf("Grass Win!\n");
        else
            printf("Rabbit Win!\n");
    }
    return 0;
}


