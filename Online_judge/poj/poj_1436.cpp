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
#define N 8005
#define pi acos(-1.0)
#define pb(a) push_back(a)
#define lson step<<1
#define rson step<<1|1
using namespace std;
struct SegmentTree{
    int left,right,mid;
    int col;
}L[N*2*4];
struct Node{
    int x,y1,y2;
}a[8005];
vector<int>v[8005];
bool cmp(Node n1,Node n2){
    return n1.x<n2.x;
}
void Push_Down(int step){
    if(L[step].col!=-1){
        L[lson].col=L[rson].col=L[step].col;
        L[step].col=-1;
    }
}
void Bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].mid=(l+r)/2;
    L[step].col=0;
    if(l==r) return;
    Bulid(lson,l,L[step].mid);
    Bulid(rson,L[step].mid+1,r);
}
void Update(int step,int l,int r,int c){
    if(l==L[step].left&&r==L[step].right){
        L[step].col=c;
        return;
    }
    Push_Down(step);
    if(r<=L[step].mid) Update(lson,l,r,c);
    else if(l>L[step].mid) Update(rson,l,r,c);
    else{Update(lson,l,L[step].mid,c);Update(rson,L[step].mid+1,r,c);}
}
bool flag[8005];
void Query(int step,int l,int r,int c){
    if(L[step].col!=-1){
        if(L[step].col&&!flag[L[step].col]) v[c].pb(L[step].col);
        flag[L[step].col]=true;
        return ;
    }
    Push_Down(step);
    if(r<=L[step].mid) Query(lson,l,r,c);
    else if(l>L[step].mid) Query(rson,l,r,c);
    else{Query(lson,l,L[step].mid,c);Query(rson,L[step].mid+1,r,c);}
}
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        int m=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            v[i].clear();
            scanf("%d%d%d",&a[i].y1,&a[i].y2,&a[i].x);
            m=max(m,a[i].y2);
        }
        sort(a+1,a+1+n,cmp);
        Bulid(1,0,2*m);
        for(int i=1;i<=n;i++){
            memset(flag,false,sizeof(flag));
            Query(1,2*a[i].y1,2*a[i].y2,i);
            Update(1,2*a[i].y1,2*a[i].y2,i);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<v[i].size();j++){
                for(int k=0;k<v[v[i][j]].size();k++)
                    for(int r=0;r<v[i].size();r++)
                        if(v[i][r]==v[v[i][j]][k]) ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}



