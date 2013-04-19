#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#define LL long long
#define Key_value ch[ch[root][1]][0]  
#define lowbit(x) (x&(-x))
using namespace std;
char str[10005];
int main(){
    scanf("%s",str);
    int l=strlen(str);
    int left=l/2,right=l/2,pos=-1;
    for(int i=l-1;i>=0;i--){
        if(str[i]=='(') left--;
        else right--;
        if(str[i]=='('){
            if(left>right){
                str[i]=')';
                right++;
                pos=i+1;
                while(left<l/2){
                    str[pos++]='(';
                    left++;
                }
                while(right<l/2){
                    str[pos++]=')';
                    right++;
                }
                break;
            }
        }
    }
    if(pos==-1) 
        puts("No solution");
    else{
        puts(str);
    }
    return 0;
}
