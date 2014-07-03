#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 100005
#define inf 1<<29
#define MOD 9973
#define LL long long
#define eps 1e-7
#define zero(a) fabs(a)<eps
#define equal(a,b) zero(a-b)
using namespace std;
struct Node{
    int d,h;
}a[20];
int n;
bool cmp(Node n1,Node n2){
    return n1.d*n2.h>n2.d*n1.h;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        int sum=0;
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i].d,&a[i].h);            
            sum+=a[i].d;
        }
        sort(a,a+n,cmp);
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=a[i].h*sum;
            sum-=a[i].d;
        }
        printf("%d\n",ans);
    }
    return 0;
}        