#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#define inf 110000000
#define M 10005
#define N 10005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define MOD 1000000007
using namespace std;
int l,n,m,a[500005];
int main(){
    while(scanf("%d%d%d",&l,&n,&m)!=EOF){
        a[0]=0;a[n+1]=l;
        int low=0,ans,high=l,mid;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a,a+n+2);
        for(int i=1;i<=n+1;i++)
        low=max(low,a[i]-a[i-1]);
        while(low<=high){
            mid=(low+high)/2;
            int cnt=1,k=0;
            for(int i=1;i<=n;i++){
                if(a[i]-a[k]>mid){
                    cnt++;
                    k=i-1;
                    i--;
                }
            }
            if(a[n+1]-a[k]>mid) cnt++;
        //    cout<<mid<<" "<<cnt<<endl;
            if(cnt<=m) {ans=mid;high=mid-1;}
            else low=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}

