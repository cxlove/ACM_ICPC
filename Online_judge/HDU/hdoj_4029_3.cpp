#include <stdio.h>
 #include <string.h>
 #include <algorithm>
 #define MAXN 130
 #define MAXL 130*130
 typedef unsigned long long ULL;
 typedef unsigned int UINT;
 const ULL BASE1=419,BASE2=131;
 struct HASH{
     UINT h1,h2;
     HASH(){}
     HASH(UINT _h1,UINT _h2):h1(_h1),h2(_h2){}
     bool operator ==(const HASH& hh)const{return h1==hh.h1&&h2==hh.h2;}
     bool operator <(const HASH& hh)const{return h1<hh.h1||h1==hh.h1&&h2<hh.h2;}
 }h[MAXN][MAXN],st[MAXL];
 char mz[MAXN][MAXN];
 int cas,n,m,len;
 int wa[MAXL],wb[MAXL],wv[MAXL],ws[MAXL],r[MAXL],ord[MAXL],sa[MAXL];
 int cmp(int *r,int a,int b,int l)
 {return r[a]==r[b]&&r[a+l]==r[b+l];}
 void da(int *r,int *sa,int n,int m)
 {
      int i,j,p,*x=wa,*y=wb,*t;
      for(i=0;i<m;i++) ws[i]=0;
      for(i=0;i<n;i++) ws[x[i]=r[i]]++;
      for(i=1;i<m;i++) ws[i]+=ws[i-1];
      for(i=n-1;i>=0;i--) sa[--ws[x[i]]]=i;
      for(j=1,p=1;p<n;j*=2,m=p)
      {
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) ws[i]=0;
        for(i=0;i<n;i++) ws[wv[i]]++;
        for(i=1;i<m;i++) ws[i]+=ws[i-1];
        for(i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
        x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
      }
      return;
 }
 int rank[MAXL],height[MAXL];
 void calheight(int *r,int *sa,int n)
 {
      int i,j,k=0;
      for(i=0;i<=n;i++) rank[sa[i]]=i;
      for(i=0;i<n;height[rank[i++]]=k)
      for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
      return;
 }
 bool cmpp(int a,int b){
     return st[a]<st[b];
 }
 int main(){
     //freopen("test.in","r",stdin);
     scanf("%d",&cas);
     for(int ca=1;ca<=cas;ca++){
         scanf("%d%d",&n,&m);
         for(int i=0;i<n;i++)scanf("%s",mz[i]);
         for(int i=0;i<n;i++)for(int j=0;j<m;j++)h[i][j].h1=h[i][j].h2=0ULL;
         unsigned long long ans=0;
         for(int w=1;w<=m;w++){
             //memset(rank,-1,sizeof rank);
             for(int i=0;i<n;i++){
                 for(int j=w-1;j<m;j++){
                     h[i][j+1-w].h1=h[i][j+1-w].h1*BASE1+mz[i][j];
                     h[i][j+1-w].h2=h[i][j+1-w].h2*BASE2+mz[i][j];
                 }
             }
             len=0;
             for(int j=0;j+w<=m;j++){
                 for(int i=0;i<n;i++)st[len++]=h[i][j];
                 st[len++]=HASH(0,0);
             }
             for(int i=0;i<len;i++)ord[i]=i;
             std::sort(ord,ord+len,cmpp);
             r[ord[0]]=0;
             for(int i=1;i<len;i++){
                 if(st[ord[i]]==st[ord[i-1]]&&st[ord[i]].h1)r[ord[i]]=r[ord[i-1]];
                 else r[ord[i]]=r[ord[i-1]]+1;
             }
             da(r,sa,len,r[ord[len-1]]+1);
             calheight(r,sa,len-1);
             ULL tmp=(1+n)*n/2*(m-w+1);
             for(int i=m-w+1;i<len;i++)tmp-=height[i];
             ans+=tmp;
         }
         printf("Case #%d: %I64u\n",ca,ans);
     }
     return 0;
 }