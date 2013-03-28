/*
ID:cxlove
Prob:C Code Lock
Algorithm:greedy
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
const int N = 1005;
char str[N];
int d[N],s[N];
int main(){
    while(scanf("%s",str+1)!=EOF&&str[1]!='*'){
        str[0]='a';
        int l=strlen(str);
        str[l]='a';
        for(int i=0;i<l;i++){
            d[i]=(str[i+1]-str[i]+26)%26;
        }
        sort(d,d+l);
        for(int i=0;i<l;i++){
            s[i]=(i==0?0:s[i-1])+d[i];
        }
        for(int i=0;i<l;ui++){
            if(s[i]==26*(l-i-1)-(s[l-1]-s[i])){
                printf("%d\n",s[i]);
                break;
            }
        }
    }
    return 0;
}