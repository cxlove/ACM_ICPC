#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 10005
#define LL long long
#define inf 1<<29
#define eps 1e-7
using namespace std;
int n,m;
char str[55][55];
bool change(int i,int j){
    if(str[i][j]=='0'&&str[i-1][j-1]=='0'&&str[i-1][j]=='0'&&str[i][j-1]=='0'){
        str[i][j]=str[i-1][j]=str[i][j-1]=str[i-1][j-1]='1';
        return true;
    }
    return false;
}
void recover(int i,int j){
    str[i][j]=str[i-1][j]=str[i][j-1]=str[i-1][j-1]='0';
}
bool dfs(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(change(i,j)){
                if(!dfs()){
                    recover(i,j);
                    return true;
                }
                recover(i,j);
            }
    return false;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(str,0,sizeof(str));
        for(int i=1;i<=n;i++)
            scanf("%s",str[i]+1);
        if(dfs())
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}