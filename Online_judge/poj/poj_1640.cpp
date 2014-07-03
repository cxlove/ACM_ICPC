#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 50;
int n,limit,k[N];
int delta[N],now[N];
int main(){
    int first=1;
    while(scanf("%d",&n)!=EOF&&n){
        if(!first) puts("");first=0;
        for(int i=0;i<n;i++){
            scanf("%d",&k[i]);
            now[i]=k[i];delta[i]=2*k[i]-3;
        }
        scanf("%d",&limit);
        for(int i=0;i<n;i++) while(now[i]<limit) now[i]+=delta[i],delta[i]+=k[i]-2;
        if(limit==1){
            printf("1:");
            for(int i=0;i<n;i++)
                printf("%d%c",k[i],(i==n-1)?'\n':' ');
        }
        for(int t=0;t<(limit==1?4:5);){
            int a[50],cnt=0,mn=(1<<30);
            for(int i=0;i<n;i++){
                if(now[i]<mn) mn=now[i],cnt=0,a[cnt++]=i;
                else if(now[i]==mn) a[cnt++]=i;
            }
            //cout<<t<<" "<<cnt<<" "<<mn<<endl;
            if(cnt==1) now[a[0]]+=delta[a[0]],delta[a[0]]+=k[a[0]]-2;
            else{
                printf("%d:",mn);
                for(int i=0;i<cnt;i++){
                    printf("%d%c",k[a[i]],i==cnt-1?'\n':' ');
                    now[a[i]]+=delta[a[i]],delta[a[i]]+=k[a[i]]-2;
                }
                t++;
            }
            //system("pause");
        }
    }
    return 0;
}