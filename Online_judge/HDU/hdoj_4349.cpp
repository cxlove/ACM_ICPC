#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cstdlib>
#include<vector>
#define C    240
#define TIME 10
#define LL long long
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int cnt=0;
        while(n){
            if(n&1)
               cnt++;
            n>>=1;
        }
        printf("%d\n",1<<cnt);
    }
    return 0;
}
