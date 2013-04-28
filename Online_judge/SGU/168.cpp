#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n,m;
int a[1005][1005];
int b[1005][1005];
int main(){
    scanf("%d%d",&n,&m);
    memset(b,0x11,sizeof(b));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int j=m;j;j--){
        for(int i=n;i;i--)
            b[i][j]=min(min(min(b[i][j+1],b[i+1][j]),b[i-1][j+1]),a[i][j]);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            printf("%d%c",b[i][j],(j==m?'\n':' '));
    return 0;
}
