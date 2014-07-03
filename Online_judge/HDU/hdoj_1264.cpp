/*
ID:cxlove
PROB:Counting Squares 
DATA:2012.2.22
HINT:线段树+离散化
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct line{
    int left,right,mid;
    int sum,cnt;
}L[1000000];
struct segment{
    int lx,rx,y;
    int kind;
}s[1000000];
int x[2000000],xcount;
bool cmp(segment s1,segment s2){
    return s1.y<s2.y;
}
int find(int xx){
    int low=0,high=xcount-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(x[mid]==xx)
            return mid;
        if(x[mid]<xx)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}
void bulid(int step, int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].mid=(l+r)/2;
    L[step].sum=L[step].cnt=0;
    if(l==r)
        return;
    bulid(2*step,l,(l+r)/2);
    bulid(2*step+1,(l+r)/2+1,r);
}
void update(int step){
    if(L[step].cnt)
        L[step].sum=x[L[step].right+1]-x[L[step].left];
    else{
        if(L[step].right==L[step].left)
            L[step].sum=0;
        else
            L[step].sum=L[2*step].sum+L[2*step+1].sum;
    }
}
void insert(int step,int l,int r,int k){
    if(L[step].left==l&&L[step].right==r)
        L[step].cnt+=k;
    else if(r<=L[step].mid)
        insert(2*step,l,r,k);
    else if(l>L[step].mid)
        insert(2*step+1,l,r,k);
    else{
        insert(2*step,l,L[step].mid,k);
        insert(2*step+1,L[step].mid+1,r,k);
    }
    update(step);
}        
int main(){
    int m=0;
    int x1,x2,y1,y2;
    while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2)!=EOF)
        if(x1<0&&x2<0){
            sort(x,x+m);
            sort(s,s+m,cmp);
            xcount=0;
            for(int i=0;i<m;i++)
                if(i==0||x[i]!=x[i-1])
                    x[xcount++]=x[i];
            bulid(1,0,xcount-2);
            int ans=0;
            for(int i=0;i<m-1;i++){
                int l=find(s[i].lx);
                int r=find(s[i].rx)-1;
                insert(1,l,r,s[i].kind);
                ans+=(s[i+1].y-s[i].y)*L[1].sum;
            }
            printf("%d\n",ans);
            m=0;
            if(x1==-2&&y1==-2)
                break;
        }
        else{
            int X1=min(x1,x2),X2=max(x1,x2);
            int Y1=min(y1,y2),Y2=max(y1,y2);
            s[m].lx=s[m+1].lx=x[m]=X1;
            s[m].kind=1;s[m].y=Y1;
            s[m].rx=s[m+1].rx=x[m+1]=X2;
            s[m+1].kind=-1;s[m+1].y=Y2;
            m+=2;
        }
    return 0;
}
/*
5 8 7 10
6 9 7 8
6 8 8 11
-1 -1 -1 -1
0 0 100 100
50 75 12 90
39 42 57 73
-2 -2 -2 -2
*/