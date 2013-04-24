#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#define test puts("OK");
using namespace std;
char s[100];
int n,m;
int main(){
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d\n",&n,&m);//getchar();
        for(int i=0;i<n;i++) gets(s);  
        for(int i=0;i<m;i++) gets(s); 
        printf("Case %d: %.6f\n",++cas,pow(1.0/n,m*1.0));
    }
    return 0;
}