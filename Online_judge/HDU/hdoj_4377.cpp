#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<ctime>
#include<sstream>
#include<cassert>
#define LL long long
#define eps 1e-7
#define zero(a) fabs(a)<eps
#define inf 1<<30
#define N 20
#define pi acos(-1.0)
#define pb(a) push_back(a)
using namespace std;
int ans[100005];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n==2){puts("1 2");continue;}
        int m=ceil(sqrt(n));
        if(m*m==n){
            for(int i=1;i<=m;i++)
               for(int j=m;j>=1;j--)
                  ans[(i-1)*m+m+1-j]=(i-1)*m+j;
        }
        else{
            int num=n;
            for(int j=m;j>=1;j--){
                if(j==2){
                    int up=num;
                  //  cout<<up-m-1<<endl;
                    for(int i=max(up-m+1,2);i<=up;i++)
                        ans[i]=num,num--;
                    for(int i=1;i<=max(1,up-m);i++)
                        ans[i]=num,num--;
                        break;
                }
                else{
                     int up=num;
                    for(int i=up-m+1;i<=up;i++)
                         ans[i]=num,num--;
                }
            }
        }
        for(int i=1;i<n;i++) printf("%d ",ans[i]);
        printf("%d\n",ans[n]);
    }
    return 0;
}
