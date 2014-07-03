#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t;
char str[1000005];
void add(){
    int l=strlen(str);
    str[l-1]++;
    for(int i=l-1;i>=0;i--){
        if(str[i]>'9'){
            str[i-1]++;
            str[i]-=10;
        }
        else break;
    }
}
bool check(){
    int ret=0;
    for(int i=0;str[i];i++){
        ret+=str[i]-'0';
    }
    return ret%10==0;
}
int main(){
    scanf("%d",&t);
    while(t--){
        int ret=0;
        scanf("%s",str+1);
        str[0]='0';
        while(true){
            add();
            if(check()) break;
        }
        if(str[0]=='0') puts(str+1);
        else puts(str);
    }
    return 0;
}    