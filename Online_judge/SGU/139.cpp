#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define LL long long
#define eps 1e-6
using namespace std;
int a[4][4],b[16];
bool check(){
    int r=0;
    for(int i=0;i<16;i++)
        for(int j=i+1;j<16;j++)
            if(b[i]==0||b[j]==0) 
                continue;
            else if(b[i]>b[j])
                r++;
    for(int i=1;i<=15;i++){
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
                if(a[j][k]==i)
                    r+=abs(j-(i-1)/4);
    }
    return r%2==0;
}
int main(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>a[i][j];
            b[i*4+j]=a[i][j];
        }
    }
    if(check()) puts("YES");
    else puts("NO");
    return 0;
}
