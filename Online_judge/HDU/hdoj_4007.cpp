#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#define inf 110000
#define N 1005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define eps 1e-9
#define zero(a) fabs(a)<eps
#define LL long long
#define lson (step<<1)
#define rson (step<<1|1)
#define MOD 1000000007
using namespace std;
struct Node{
    int left,right,mid,cover,val;
}L[N*2*4];
struct Seg{
    int y,x1,x2;
    int flag;
    Seg(){}
    Seg(int _y,int _x1,int _x2,int _flag):y(_y),x1(_x1),x2(_x2),flag(_flag){}
    bool operator<(const Seg s)const{
        return s.y==y?s.flag<flag:s.y>y;
    }
}seg[N*2];
int n,r,x[N*2],m;
int BinSearch(int num){
    int low=0,high=m-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(x[mid]==num) return mid;
        if(x[mid]<num) low=mid+1;
        else high=mid-1;
    }
}
void Bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].mid=(l+r)/2;
    L[step].cover=L[step].val=0;
    if(l==r) return;
    Bulid(lson,l,L[step].mid);
    Bulid(rson,L[step].mid+1,r);
}
void Push_Down(int step){
    if(L[step].cover){
        L[lson].cover+=L[step].cover;
        L[rson].cover+=L[step].cover;
        L[lson].val+=L[step].cover;
        L[rson].val+=L[step].cover;
        L[step].cover=0;
    }
}
void Push_Up(int step){
    L[step].val=max(L[lson].val,L[rson].val);
}
void Update(int step,int l,int r,int c){
    if(L[step].left==l&&L[step].right==r){
        L[step].cover+=c;
        L[step].val+=c;
        return;
    }
    Push_Down(step);
    if(r<=L[step].mid) Update(lson,l,r,c);
    else if(l>L[step].mid) Update(rson,l,r,c);
    else{
        Update(lson,l,L[step].mid,c);
        Update(rson,L[step].mid+1,r,c);
    }
    Push_Up(step);
}
int main(){
    while(scanf("%d%d",&n,&r)!=EOF){
        for(int i=0;i<n;i++){
            int X,Y;
            scanf("%d%d",&X,&Y);
            x[i*2]=X;x[i*2+1]=X+r+1;
            seg[i*2]=Seg(Y,X,X+r+1,1);
            seg[i*2+1]=Seg(Y+r+1,X,X+r+1,-1);
        }
        sort(x,x+2*n);
        sort(seg,seg+2*n);
        m=1;
        for(int i=1;i<2*n;i++)
            if(x[i]!=x[m-1])
                x[m++]=x[i];
        Bulid(1,0,m-1);
        int ans=0;
        for(int i=0;i<2*n;i++){
            int left=BinSearch(seg[i].x1),right=BinSearch(seg[i].x2);
            Update(1,left,right,seg[i].flag);
            if(L[1].val>ans) ans=L[1].val;
        }
        printf("%d\n",ans);
    }
    return 0;
}

            
