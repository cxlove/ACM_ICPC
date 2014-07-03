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
    int l,r,t;
    char c;
    Node(){}
    Node(int tl,int tr,int tt,char tc){l=tl;r=tr;t=tt;c=tc;}
}a[1000];
struct NN{
    int t;char c;
    void Init(int tt,char tc){
        t=tt;c=tc;
    }
}b[1000];
int x[205],cx,tx;
int R,C;
int find(int num,int *b,int n){
    int ans,low=0,high=n-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(b[mid]==num) return mid;
        if(b[mid]>num){high=mid-1;}
        else {low=mid+1;}
    }
    return -1;
}
int l,r,t,n;
char ch[5];
char str[100];
int main(){
    while(gets(str)!=NULL){
        if(strcmp(str,"END")==0) break;
        cx=0;tx=1;
        n=0;
        while(scanf("%d",&l)&&l){
            scanf("%d%s%d",&r,ch,&t);
            x[cx++]=l;x[cx++]=r;
            a[n++]=Node(l,r,t,ch[0]);
        }
        getchar();
        puts(str);
        sort(x,x+cx);
        for(int i=1;i<cx;i++)
           if(x[i]!=x[tx-1])
               x[tx++]=x[i];
        for(int i=0;i<2*tx-1;i++) b[i].t=-1;
        for(int i=0;i<n;i++){
            int ll=find(a[i].l,x,tx)*2,rr=find(a[i].r,x,tx)*2;
            for(int j=ll;j<=rr;j++)
               b[j].Init(a[i].t,a[i].c);
        }
      /*  for(int i=0;i<tx*2-1;i++){
            int l,r;
            if(i&1) l=x[i/2]+1;else l=x[i/2];
            if(i&1) r=x[i/2+1]-1;else r=x[i/2];
            printf("%d %d %c %d\n",l,r,b[i].c,b[i].t);
        }
*/
        int qd=0,zd=0;
        for(int i=1;i<tx*2-1;i++){
          //  if(b[i].t==-1) continue;
            if(b[i].t!=b[qd].t||b[i].c!=b[qd].c){
                if(qd==-1){
                    if(b[i].t!=-1)
                       qd=i;
                    continue;
                }
                if(i%2==1&&x[i/2+1]==x[i/2]+1) continue;
                int l,r;
                if(qd&1) l=x[qd/2]+1;else l=x[qd/2];
                if(zd&1) r=x[zd/2+1]-1;else r=x[zd/2];
                printf("%d %d %c %d\n",l,r,b[qd].c,b[qd].t);
                qd=i;zd=i;
                if(b[i].t==-1) qd=-1;
            }
            else  zd=i;
        }
        if(qd!=-1){
            int l,r;
            if(qd&1) l=x[qd/2]+1;else l=x[qd/2];
            if(zd&1) r=x[zd/2+1]-1;else r=x[zd/2];
            printf("%d %d %c %d\n",l,r,b[qd].c,b[qd].t);
        }
    }
    return 0;
}