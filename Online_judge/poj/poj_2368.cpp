#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define C    240
#define TIME 10
#define inf 1<<25
#define LL long long
using namespace std;
int main(){
    int k;
    while(cin>>k){
        bool flag=true;
        for(int i=3;i*i<=k;i++)
            if(k%i==0){
                printf("%d\n",i-1);
                flag=false;
                break;
            }
        if(flag){
            if(k%2==0&&k/2-1>1)  printf("%d\n",k/2-1);
            else printf("%d\n",k-1);
        }
    }
    return 0;
}