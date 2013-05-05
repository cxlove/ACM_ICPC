#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define LL long long
#define eps 1e-6
using namespace std;
int t,cas=0,m,n,a[1005];
int main(){
    //freopen("A-large.in","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int p=m,ans=n,temp=0;
        bool flag=true;
        for(int i=0;i<n;i++){
            while(p<=a[i]){
                if(p-1==0){
                    flag=false;
                    break;
                }
                p+=p-1;
                temp++;
            }
            if(!flag){break;}
            p+=a[i];
            ans=min(ans,temp+n-i-1);
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}