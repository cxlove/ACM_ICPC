  #include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char str[10005];
int cnt;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        while(n--){
            scanf("%s",str);
            cnt=1;
            for(int i=1;str[i];i++){
                if(str[i]!=str[i-1]){
                    if(cnt==1)
                        printf("%c",str[i-1]);
                    else
                        printf("%d%c",cnt,str[i-1]);
                    cnt=1;
                }
                else
                    cnt++;
            }
            if(cnt==1)
                printf("%c",str[strlen(str)-1]);
            else
                printf("%d%c",cnt,str[strlen(str)-1]);
            printf("\n");
        }
    }
    return 0;
}
