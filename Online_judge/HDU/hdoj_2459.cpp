#include <iostream> 
#include <cstdio> 
#include <cstring> 
#include <cmath> 
  
using namespace std; 
  
const int maxn=200009; 
int  
n,r[maxn*3],sa[maxn*3],sa0[maxn],sa12[maxn],rank[maxn],h[maxn],tmp[maxn],cot[ 
maxn]; 
bool cmp(int *r,int a,int b,int k) 
{ 
     if(k==0) 
     { 
         for(int i=0; i<3; ++i) if(r[i+a]!=r[i+b]) return 0; 
         return 1; 
     } 
     else 
     { 
         for(int i=0; i<k; ++i) if(r[i+a]!=r[i+b]) return r[i+a]<r[i+b]; 
         return rank[a+k]<rank[b+k] ; 
     } 
} 
void count_sort(int *r,int *a,int n,int m) 
{ 
     for(int i=0; i<m; ++i) cot[i]=0; 
     for(int i=0; i<n; ++i) cot[r[a[i]]]++; 
     for(int i=1; i<m; ++i) cot[i]+=cot[i-1]; 
     for(int i=n-1; i>=0; --i) tmp[--cot[r[a[i]]]]=a[i]; 
     for(int i=0; i<n; ++i) a[i]=tmp[i]; 
} 
void dc3(int *r,int *sa,int n,int m) 
{ 
     r[n]=r[n+1]=0; 
     int n0=(n+2)/3,n1=(n+1)/3,n2=n/3,n12=n1+n2,i,j,p,*dr=r+n,*dsa=sa+n; 
     for(i=0,j=0; i<n; ++i) if(i%3) sa12[j++]=i; 
     for(i=2; i>=0; --i) count_sort(r+i,sa12,n12,m); 
#define F(x) (x/3+(x%3==1?0:n1)) 
#define G(x) (x<n1?(x*3+1):(x-n1)*3+2) 
     for(i=1,p=0,dr[F(sa12[0])]=p++; i<n12; ++i)  
dr[F(sa12[i])]=cmp(r,sa12[i],sa12[i-1],0)?p-1:p++; 
     if(p<n12) dc3(dr,dsa,n12,p); 
     else for(i=0; i<n12; ++i) dsa[dr[i]]=i; 
     for(i=0,j=0; i<n12; ++i) if(dsa[i]<n1) sa0[j++]=dsa[i]*3; 
     if(n%3==1) sa0[j++]=n-1; 
     count_sort(r,sa0,n0,m); 
     for(i=0; i<n12; ++i) rank[sa12[i]=G(dsa[i])]=i; 
     for(i=0,j=0,p=0; i<n12&&j<n0; ++p) sa[p]=cmp(r,sa12[i],sa0[j],sa12[i]%3)? 
sa12[i++]:sa0[j++]; 
     while(i<n12) sa[p++]=sa12[i++]; 
     while(j<n0) sa[p++]=sa0[j++]; 
} 
void make_height() 
{ 
     for(int i=0; i<n; ++i) rank[sa[i]]=i; 
     h[0]=0; 
     for(int i=0,k=0; i<n-1; ++i) 
     { 
         k=(k?k-1:0); 
         while(r[i+k]==r[sa[rank[i]-1]+k]) k++; 
         h[rank[i]]=k; 
     } 
} 
int f[maxn][21]; 
void make_rmq() 
{ 
     for(int i=0; i<n; i++) f[i][0]=h[i]; 
     for(int j=1; j<=20; j++) 
         for(int i=0; i+(1<<j)-1<n; i++) 
             f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]); 
} 
int query(int a,int b) 
{ 
     if(a>b) swap(a,b); 
     if(a==b) 
     { 
         cout << "ERROR" << endl; 
         return -1; 
     } 
     a++; 
     int k=log(double(b-a+1))/log(2.0); 
     return min(f[a][k],f[b-(1<<k)+1][k]); 
} 
char ans[maxn],s[maxn],cmps[maxn]; 
int rep; 
void solve() 
{ 
     n=0,rep=0; 
     int len=strlen(s); 
     for(int i=0; i<len; i++) r[n++]=s[i]; 
     r[n++]=300; 
     for(int i=len-1; i>=0; i--) r[n++]=s[i]; 
     r[n++]=0; 
     dc3(r,sa,n,400); 
     make_height(); 
     make_rmq(); 
     for(int i=1; i<=len; i++) 
     { 
         for(int j=0; j+i+i-1<len; j+=i) 
         { 
             int pb,pf,K,mod,tmp,t1,t2,k,o; 
             if(s[j]!=s[j+i]) continue; 
             pb=query(rank[j],rank[j+i]); 
             pf=query(rank[2*len-j],rank[2*len-(j+i)]); 
             if(j+pb-1<j+i-pf+1 && i!=1) continue; 
             K=(j+i+pb-1)-(j-pf+1)+1; 
             mod=K%i; 
             tmp=K/i; 
             if(rep<tmp) 
             { 
                 rep=tmp; 
                 for( o=j-pf+1,t1=0;o<=j-pf+1+i-1;o++)  
ans[t1++]=s[o];ans[t1]=0; 
                 for( k=1; k<=mod; k++) 
                 { 
                     for( o=j-pf+1+k,t1=0; o<=j-pf+1+k+i-1; o++)  
cmps[t1++]=s[o]; 
                     cmps[t1]=0; 
                     if(strcmp(ans,cmps)>0) strcpy(ans,cmps); 
                 } 
             } 
             else if(rep==tmp) 
             { 
                 for( k=0; k<=mod; k++) 
                 { 
                     for(o=j-pf+1+k,t1=0; o<=j-pf+1+k+i-1; o++)  
cmps[t1++]=s[o]; 
                     cmps[t1]=0; 
                     if(strcmp(ans,cmps)>0) strcpy(ans,cmps); 
                 } 
             } 
         } 
     } 
} 
int main() 
{ 
//    freopen("in","r",stdin); 
     int cas=1; 
     while(~scanf("%s",s) && s[0]!='#') 
     { 
         printf("Case %d: ",cas++); 
         solve(); 
         if(rep==0) 
         { 
             char ch='z'; 
             for(int i=0;s[i];i++) ch=min(ch,s[i]); 
             putchar(ch); 
             puts(""); 
             continue; 
         } 
         while(rep--) 
         printf("%s",ans); 
         puts(""); 
     } 
     return 0; 
} 