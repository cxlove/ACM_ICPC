#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a,b;
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ans=0,cnt=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            if(a>=2)
                cnt++;
            ans^=a;
        }
        if(cnt){
            if(ans==0)
                printf("Brother\n");
            else
                printf("John\n");
        }
        else{
            if(!(n&1))
                printf("John\n");
            else
                printf("Brother\n");
        }
    }
    return 0;
}