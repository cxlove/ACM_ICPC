#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a,b;
int main(){
    int t,n;
    while(scanf("%d",&n)!=EOF){        
        int ans=0,cnt=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            if(a>=2)
                cnt++;
            ans^=a;
        }
        if(cnt){
            if(ans==0)
                printf("No\n");
            else
                printf("Yes\n");
        }
        else{
            if(!(n&1))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}