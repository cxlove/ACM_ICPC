#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define eps 1e-10
#define N (1<<7)+5
#define inf 1<<20
#define zero(a) (fabs(a)<eps)
#define lson (step<<1)
#define rson (step<<1|1)
using namespace std;
struct Node{
    int x1,x2,y1,y2;
}a[100];
int x[205],y[205],cx,cy,tx,ty;
int c[205][205];
int R,C;
int find(int num,int *b,int n){
    int ans,low=0,high=n-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(b[mid]==num) return mid;
        if(b[mid]>num){high=mid-1;}
        else {low=mid+1;}
    }
  //  cout<<num<<" "<<mid<<endl;
    return -1;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF&&n){
        scanf("%d%d",&R,&C);
        tx=ty=0;
        x[tx++]=0;y[ty++]=0;
        for(int i=0;i<n;i++){
            scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
            x[tx++]=a[i].x1;x[tx++]=a[i].x2;
            y[ty++]=a[i].y1;y[ty++]=a[i].y2;
        }
        x[tx++]=R;y[ty++]=C;
        sort(x,x+tx);
        sort(y,y+ty);
        cx=1;cy=1;
        for(int i=1;i<tx;i++)
            if(x[i]!=x[cx-1]) x[cx++]=x[i];
        for(int i=1;i<ty;i++)
             if(y[i]!=y[cy-1]) y[cy++]=y[i];
   //     for(int i=0;i<cx;i++) cout<<x[i]<<endl;
    //    for(int i=0;i<cy;i++) cout<<y[i]<<endl;
        memset(c,0,sizeof(c));
        for(int i=0;i<n;i++){
         //   cout<<a[i].x1<<" "<<a[i].x2<<" "<<a[i].y1<<" "<<a[i].y2<<endl;
            int lx=find(a[i].x1,x,cx),rx=find(a[i].x2,x,cx)-1;
            int ly=find(a[i].y1,y,cy),ry=find(a[i].y2,y,cy)-1;
          //  cout<<lx<<" "<<rx<<" "<<ly<<" "<<ry<<endl;
            for(int j=lx;j<=rx;j++)
               for(int k=ly;k<=ry;k++)
                  c[j][k]++;
        }
        int ans=0;
        for(int i=0;i<cx-1;i++)
           for(int j=0;j<cy-1;j++)
               ans=max(ans,c[i][j]);
        int a1=0,a2=0;
        for(int i=0;i<cx-1;i++)
           for(int j=0;j<cy-1;j++)
               if(ans==c[i][j])
                   a1+=(x[i+1]-x[i])*(y[j+1]-y[j]);
               else if(c[i][j]==0)
                    a2+=(x[i+1]-x[i])*(y[j+1]-y[j]);
        printf("%d %d %d\n",a2,ans,a1);


    }
    return 0;
}