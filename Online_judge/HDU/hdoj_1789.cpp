#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<string>
#include<vector>
#define eps 1e-10
#define LL long long
#define LD long double
#define pi acos(-1.0)
#define inf 1LL<<60
using namespace std;
struct Node{
    int d,p;
}a[1000];
bool cmp(Node n1,Node n2){
    return n1.p>n2.p;
}
int n,t;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i].d);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i].p);
        sort(a,a+n,cmp);
        int ans=0;
        bool flag[10000];
        memset(flag,false,sizeof(flag));
        for(int i=0;i<n;i++){
            int j;
            for(j=a[i].d;j>=1;j--)
                if(flag[j]==false){
                    flag[j]=true;
                    break;
                }
            if(j==0)
                ans+=a[i].p;
        }
        printf("%d\n",ans);
    }
    return 0;
}