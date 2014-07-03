#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a,b;
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        int ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            ans^=a%(b+1);
        }    
        if(ans)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}