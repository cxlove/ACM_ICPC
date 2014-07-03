#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 30
#define inf 1<<29
#define MOD 2007
#define LL long long
using namespace std;
int n,a[1005];
bool flag[1005];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(flag,false,sizeof(flag));
        int ans=1;
        for(int i=1;i<=n;i++){
            if(flag[i])  continue;
            flag[i]=true;
            int cnt=1,j=i;
            while(!flag[a[j]]){
                flag[a[j]]=true;
                j=a[j];
                cnt++;
            }
            ans=ans*cnt/gcd(ans,cnt);
        }
        printf("%d\n",ans);
    }
    return 0;
}



