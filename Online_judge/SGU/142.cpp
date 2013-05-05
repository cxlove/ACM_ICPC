#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 500005;
int n;
bool flag[1<<20];
char str[N];
void output(int m,int l){
    if(l>1) output(m/2,l-1);
    putchar(m%2==0?'a':'b');
}
int main(){
    scanf("%d%s",&n,str);
    for(int l=1;;l++){
        memset(flag,false,sizeof(flag));
        for(int i=0;i<n-l+1;i++){
            int t=0;
            for(int j=i;j<i+l;j++){
                t<<=1;
                if(str[j]=='b')
                    t|=1;
            }
            flag[t]=true;
        }
        for(int i=0;i<(1<<l);i++){
            if(flag[i]==false){
                printf("%d\n",l);
                output(i,l);puts("");
                return 0;
            }
        }
    }
    return 0;
}
