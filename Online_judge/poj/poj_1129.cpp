#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
int mat[26][26];
int col[26];
char str[100];
int main(){
    while(scanf("%d",&n)!=EOF&&n){
        memset(mat,0,sizeof(mat));
        for(int i=0;i<n;i++){
            scanf("%s",str);
            for(int j=2;str[j];j++)
                mat[i][str[j]-'A']=1;
        }
        memset(col,0,sizeof(col));
        int ans=1;
        for(int i=0;i<3;i++){
            for(int j=0;j<n;j++){
                if(col[j]==i){
                    for(int k=0;k<n;k++){
                        if(col[k]==col[j]&&mat[j][k]){
                            col[k]++;
                            ans=max(ans,i+2);
                        }
                    }
                }
            }
        }
        printf("%d channel%s needed.\n",ans,ans==1?"":"s");
    }
    return 0;
}