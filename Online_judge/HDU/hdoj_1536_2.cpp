#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int s[100],k,SG[10010];
int getSG(int x){
    if(SG[x]!=-1) return SG[x];
    int visit[100]={0};
    for(int i=0;i<k;i++){
        int temp=x-s[i];
        if(temp<0) break;
        if(SG[temp]==-1)
            SG[temp]=getSG(temp);
        visit[SG[temp]]=1;
    }
    for(int i=0;;i++)
        if(visit[i]==0) return i;
}
int main(){
    while(scanf("%d",&k)!=EOF&&k){
        for(int i=0;i<k;i++)
            scanf("%d",&s[i]);
        sort(s,s+k);
        int q;
        memset(SG,-1,sizeof(SG));
        scanf("%d",&q);
        while(q--){
            int n,t;
            scanf("%d",&n);
            int ans=0;
            for(int i=0;i<n;i++){
                scanf("%d",&t);
                if(SG[t]==-1)
                    SG[t]=getSG(t);
                ans^=SG[t];
            }
            if(ans==0)
                printf("L");
            else
                printf("W");
        }
        printf("\n");
    }
}

