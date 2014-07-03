#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
#include <deque>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int a[4][4]={2,3,1,1,1,2,3,1,1,1,2,3,3,1,1,2};
int main(){
    int t,mat[4][4],ans[4][4];
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++){
                scanf("%X",&mat[i][j]);
            }
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                ans[i][j]=0;
                for(int k=0;k<4;k++){
                    int tmp=mat[k][j];
                    if(a[i][k]!=2)
                        ans[i][j]^=tmp;
                    if(a[i][k]!=1){
                        if(tmp&(1<<7))
                            ans[i][j]^=27;
                        ans[i][j]^=(tmp<<1)&255;
                    }
                }
            }
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++)
                printf("%02X ",ans[i][j]);
            printf("%02X\n",ans[i][3]);
        }
        if(t) puts("");
    }
    return 0;
}