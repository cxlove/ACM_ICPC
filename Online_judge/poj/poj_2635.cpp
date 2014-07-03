#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1000005;
char str[N];
int k,ans,b[N];
int flag[N]={0},prime[N],cnt=0;
void Init(){
    for(int i=2;i<N;i++){
        if(flag[i]) continue;
        prime[cnt++]=i;
        for(int j=2;j*i<N;j++)
            flag[i*j]=1;
    }
}
bool solve(){
    int l=strlen(str);
    int m=(l+2)/3;
    for(int t=m,i=l-1;i>=0;i-=3,t--){
        b[t]=0;
        for(int j=max(0,i-2);j<=i;j++)
            b[t]=b[t]*10+(str[j]-'0');
    }
    //for(int i=1;i<=m;i++)printf("%d ",b[i]);puts("");
    for(int i=0;i<cnt&&prime[i]<k;i++){
        ans=prime[i];
        int sum=0;
        for(int j=1;j<=m;j++)
            sum=(sum*1000+b[j])%ans;
        if(!sum) return true;
    }
    return false;
}
int main(){
    Init();
    while(scanf("%s%d",str,&k)!=EOF){
        if(strcmp(str,"0")==0&&k==0) break;
        if(solve()){
            printf("BAD %d\n",ans);
        }
        else{
            printf("GOOD\n");
        }
    }
    return 0;
}