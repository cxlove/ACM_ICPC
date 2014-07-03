#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 2000005;
//以下为倍增算法求后缀数组  
int wa[maxn],wb[maxn],wv[maxn],Ws[maxn];  
int cmp(int *r,int a,int b,int l)  
{return r[a]==r[b]&&r[a+l]==r[b+l];}  
void da(const char *r,int *sa,int n,int m){  
    int i,j,p,*x=wa,*y=wb,*t;   
    for(i=0;i<m;i++) Ws[i]=0;   
    for(i=0;i<n;i++) Ws[x[i]=r[i]]++;   
    for(i=1;i<m;i++) Ws[i]+=Ws[i-1];   
    for(i=n-1;i>=0;i--) sa[--Ws[x[i]]]=i;   
    for(j=1,p=1;p<n;j*=2,m=p){   
        for(p=0,i=n-j;i<n;i++) y[p++]=i;   
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;   
        for(i=0;i<n;i++) wv[i]=x[y[i]];   
        for(i=0;i<m;i++) Ws[i]=0;   
        for(i=0;i<n;i++) Ws[wv[i]]++;   
        for(i=1;i<m;i++) Ws[i]+=Ws[i-1];   
        for(i=n-1;i>=0;i--) sa[--Ws[wv[i]]]=y[i];   
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)   
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;   
    }   
    return;   
}  
int sa[maxn],Rank[maxn],height[maxn];  
//求height数组  
void calheight(const char *r,int *sa,int n){  
    int i,j,k=0;  
    for(i=1;i<=n;i++) Rank[sa[i]]=i;  
    for(i=0;i<n;height[Rank[i++]]=k)  
        for(k?k--:0,j=sa[Rank[i]-1];r[i+k]==r[j+k];k++);  
    return;  
}  
int n , p[maxn] , l , pos;
char str[maxn];

bool check (int len) {
    int vis[60];
    for (int i = 1 ; i <= l ; i ++) {
        memset (vis , 0 , sizeof(vis));
        int mx = 1 << 30;
        vis[p[sa[i]]] = 1;
        for (int j = i ; j >= 1 ; j --) {
            mx = min (mx , height[j]);
            if (mx >= len) 
                vis[p[sa[j - 1]]] = vis[p[sa[j]]] = 1;
            else break;
        }
        mx = 1 << 30;
        for (int j = i + 1 ; j <= l ; j ++) {
            mx = min (mx , height[j]);
            if (mx >= len) 
                vis[p[sa[j - 1]]] = vis[p[sa[j]]] = 1;
            else break;
        }
        bool ok = true;
        for (int j = 0 ; j < n ; j ++) {
            if (vis[j] == 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            pos = sa[i];
            return true;
        }
    }
    return false;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int t ;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d" , &n);
        l = 0;
        int maxlen = 1 << 20;
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%s" , str + l);
            maxlen = min (maxlen , (int)strlen(str) - l);
            for (int j = l ; j < strlen(str) ; j ++) 
                p[j] = i;
            l = strlen(str);
            str[l ++] = 'T' + i + 1;
        }
        str[l] = '\0';
        da (str , sa , l + 1 , 200);
        calheight (str , sa , l);
        int low = 1 , high = maxlen , mid , ans = -1;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (check(mid)) low = mid + 1 , ans = mid;
            else high = mid - 1;
        } 
        if (ans < 3)  puts("no significant commonalities");
        else {
            for (int i = pos ; i < pos + ans ; i ++)
                printf ("%c" , str[i]);
            puts("");
        }
    }
    return 0;
}