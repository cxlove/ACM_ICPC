#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int SG[1005];
int getSG(int x){
    if(SG[x]!=-1) return SG[x];
    int visit[100]={0};
    for(int i=1;i<=x;i*=2){
        int temp=x-i;
        if(temp<0) break;
        if(SG[temp]==-1)
            SG[temp]=getSG(temp);
        visit[SG[temp]]=1;
    }
    for(int i=0;;i++)
        if(visit[i]==0) return i;
}
int n;
int main(){
    memset(SG,-1,sizeof(SG));
    SG[0]=0;
    while(scanf("%d",&n)!=EOF){
        if(SG[n]==-1)
            SG[n]=getSG(n);
        if(SG[n])
            printf("Kiki\n");
        else
            printf("Cici\n");
    }
    return 0;
}


        