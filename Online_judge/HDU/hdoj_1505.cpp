/*
ID;cxlove
PROB:City Game
DATA:2012.3.7
HINT:DP
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char ch[5];
int a[1005],l[1005]={0},r[1005]={0};
int n,m;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int ans=-1;
        memset(a,0,sizeof(a));
        a[0]=-1;a[m+1]=-1;
        for(int i=0;i<n;i++){
            for(int j=1;j<=m;j++){
                scanf("%s",ch);
                if(ch[0]=='R')
                    a[j]=0;
                else
                    a[j]++;
                l[j]=r[j]=j;
            }
            
            for(int j=2;j<=m;j++)
                while(a[l[j]-1]>=a[j])
                    l[j]=l[l[j]-1];
            for(int j=m-1;j>0;j--)
                while(a[r[j]+1]>=a[j])
                    r[j]=r[r[j]+1];
            for(int j=1;j<=m;j++)
                ans=max(ans,(r[j]-l[j]+1)*a[j]);
        }
        printf("%d\n",ans*3);
    }
    return 0;
}




