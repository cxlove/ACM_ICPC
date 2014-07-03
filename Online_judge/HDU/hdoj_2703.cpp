#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
int c[25],t[25];
int on[25],wait[25],tim[25];
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0&&m==0) break;
        n=-n;
        memset(on,0,sizeof(on));
        memset(wait,0,sizeof(wait));
        int remain=m;
        for(int i=0;i<n;i++) scanf("%d%d",&c[i],&t[i]);
        wait[0]=m;
        int ans=0;
        while(remain>0){
            for(int i=n-1;i>=0;i--){
                if(on[i]){
                    tim[i]--;
                    if(tim[i]==0){
                        wait[i+1]+=on[i]; if(i+1==n) remain-=on[i];
                        on[i]=0;

                    }
                }
                else{
                    on[i]=min(c[i],wait[i]);
                    tim[i]=t[i]-1;
                    wait[i]-=on[i];
                    if(tim[i]==0){
                        wait[i+1]+=on[i];
                        if(i+1==n) remain-=on[i];
                        on[i]=0;
                    }
                }
            }
            ans++;
        }
        printf("%d\n",ans);
    }
}