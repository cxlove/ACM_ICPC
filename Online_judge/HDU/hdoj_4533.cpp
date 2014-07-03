#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define lson step<<1
#define rson step<<1|1 
using namespace std;
const int N=200000;
struct Seg_tree{
    int left,right;
    LL A,B,C;
    // area=A*t^2+B*t+C
}L[(N+5)<<2];
int n,q;
inline LL MIN(LL a,LL b){return a>b?b:a;}
inline LL MAX(LL a,LL b){return a>b?a:b;}
void bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].A=L[step].B=L[step].C=0;
    if(l==r) return ;
    int m=(l+r)>>1;
    bulid(lson,l,m);
    bulid(rson,m+1,r);
}
void push_down(int step){
    L[lson].A+=L[step].A;L[rson].A+=L[step].A;
    L[lson].B+=L[step].B;L[rson].B+=L[step].B;
    L[lson].C+=L[step].C;L[rson].C+=L[step].C;
    L[step].A=L[step].B=L[step].C=0;
}
LL query(int step,int pos){
    if(L[step].left==pos&&pos==L[step].right){
        return (LL)pos*pos*L[step].A+(LL)pos*L[step].B+L[step].C;
    }
    push_down(step);
    int m=(L[step].left+L[step].right)>>1;
    if(pos<=m) return query(lson,pos);
    else return query(rson,pos);
}
void update(int step,int l,int r,LL a,LL b,LL c){
    if(r<l) return;
    if(L[step].left==l&&L[step].right==r){
        L[step].A+=a;
        L[step].B+=b;
        L[step].C+=c;
        return ;
    }
    int m=(L[step].left+L[step].right)>>1;
    if(r<=m) update(lson,l,r,a,b,c);
    else if(l>m) update(rson,l,r,a,b,c);
    else{
        update(lson,l,m,a,b,c);
        update(rson,m+1,r,a,b,c);
    }
}
void slove(int x1,int y1,int x2,int y2){
    // area = (x2-x1)*(y2-y1)
    update(1,MAX(x2,y2)+1,N,0LL,0LL,(LL)(x2-x1)*(y2-y1));
    // area = (t-x1) * (t-y1)
   // cout<<MAX(x1,y1)+1<<" "<<MIN(MAX(x1,y1),MAX(x2,y2))<<endl;
    update(1,MAX(x1,y1)+1,MIN(x2,y2),1LL,(LL)-(x1+y1),(LL)x1*y1);
    if(y2>x2)
        //area= (t-y1) * (x2-x1)
        update(1,MAX(MIN(x2,y2),MAX(x1,y1))+1,MAX(x2,y2),0LL,(LL)(x2-x1),(LL)-y1*(x2-x1));
    else
        //area= (t-x1) * (y2-y1)
        update(1,MAX(MIN(x2,y2),MAX(x1,y1))+1,MAX(x2,y2),0LL,(LL)(y2-y1),(LL)-x1*(y2-y1));
}
int main(){
    //freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        bulid(1,1,N);
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            slove(x1,y1,x2,y2);
        }
        scanf("%d",&q);
        while(q--){
            int t;
            scanf("%d",&t);
            printf("%I64d\n",query(1,t));
        }
    }
    return 0;
}