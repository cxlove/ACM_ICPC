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
struct Point {
    int x,y;
}p[N];
int n,X[N],Y[N];
int cntx,cnty,cx[N],cy[N],sx[N],sy[N];
LL dpx[N],dpy[N];
int Bin(int *a,int num,int m){
    int low=0,high=m-1,mid;
    while(low<=high){
        mid=(low+high)>>1;
        if(a[mid]==num)
            return mid;
        if(a[mid]<num)
            low=mid+1;
        else
            high=mid-1;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&p[i].x,&p[i].y);
            X[i]=p[i].x;
            Y[i]=p[i].y;
        }
        sort(X,X+n);
        sort(Y,Y+n);
        cntx=cnty=1;
        cy[0]=cx[0]=1;
        for(int i=1;i<n;i++){
            if(X[i]!=X[cntx-1]){
                X[cntx++]=X[i];
                cx[cntx-1]=1;
            }
            else
                cx[cntx-1]++;
            if(Y[i]!=Y[cnty-1]){
                Y[cnty++]=Y[i];
                cy[cnty-1]=1;
            }
            else
                cy[cnty-1]++;
        }
        sx[0]=cx[0];
        sy[0]=cy[0];
        for(int i=1;i<cntx;i++)
            sx[i]=sx[i-1]+cx[i];
        for(int i=1;i<cnty;i++)
            sy[i]=sy[i-1]+cy[i];
        dpx[0]=0;
        for(int i=0;i<cntx;i++)
            dpx[0]+=(LL)(X[i]-X[0])*cx[i];
        for(int i=1;i<cntx;i++)
            dpx[i]=dpx[i-1]+(LL)(sx[i-1]-sx[cntx-1]+sx[i-1])*(X[i]-X[i-1]);
        dpy[0]=0;
        for(int i=0;i<cnty;i++)
            dpy[0]+=(LL)(Y[i]-Y[0])*cy[i];
        for(int i=1;i<cnty;i++)
            dpy[i]=dpy[i-1]+(LL)(sy[i-1]-sy[cnty-1]+sy[i-1])*(Y[i]-Y[i-1]);
        LL ans=1ll<<60;
        //cout<<ans<<endl;
        for(int i=0;i<n;i++){
            int tx=Bin(X,p[i].x,cntx),ty=Bin(Y,p[i].y,cnty);
            ans=min(ans,(LL)dpx[tx]+dpy[ty]);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}