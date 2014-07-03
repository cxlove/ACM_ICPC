#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 100005
#define maxn 100005
using namespace std;
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
int dp[maxn][20];
void Rmq_Init(int n){
	int m=floor(log(n+0.0)/log(2.0));
	for(int i=1;i<=n;i++) dp[i][0]=height[i];
	for(int i=1;i<=m;i++){
		for(int j=n;j;j--){
			dp[j][i]=dp[j][i-1];
			if(j+(1<<(i-1))<=n)
				dp[j][i]=min(dp[j][i],dp[j+(1<<(i-1))][i-1]);
		}
	}
}
int Rmq_Query(int l,int r){
	int a=Rank[l],b=Rank[r];
	if(a>b) swap(a,b);
	a++;
	int m=floor(log(b-a+1.0)/log(2.0));
	return min(dp[a][m],dp[b-(1<<m)+1][m]);
}
char str[maxn];
int main(){
	int cas=0;
	while(scanf("%s",str)!=EOF&&str[0]!='#'){
		int n=strlen(str);
		da(str,sa,n+1,130);
		calheight(str,sa,n);
		Rmq_Init(n);
		int cnt=0,mmax=0,a[maxn];
		for(int l=1;l<n;l++){
			for(int i=0;i+l<n;i+=l){
				int r=Rmq_Query(i,i+l);
				int step=r/l+1;
				int k=i-(l-r%l);
				if(k>=0&&r%l)
			    	if(Rmq_Query(k,k+l)>=r) 
						step++;
				if(step>mmax){
					mmax=step;
					cnt=0;
					a[cnt++]=l;
				}
				else if(step==mmax)
					a[cnt++]=l;
			}
		}
		int len=-1,st;
		for(int i=1;i<=n&&len==-1;i++){
			for(int j=0;j<cnt;j++){
				int l=a[j];
				if(Rmq_Query(sa[i],sa[i]+l)>=(mmax-1)*l){
					len=l;
					st=sa[i];
					break;
				}
			}
		}
		printf("Case %d: ",++cas);
		for(int i=st,j=0;j<len*mmax;j++,i++) printf("%c",str[i]);
		printf("\n");
	}
	return 0;
}
/*
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int nMax =1000012;

int  num[nMax];
int sa[nMax], Rank[nMax], height[nMax];
int wa[nMax], wb[nMax], wv[nMax], wd[nMax];

int cmp(int *r, int a, int b, int l){
    return r[a] == r[b] && r[a+l] == r[b+l];
}

void da(int *r, int n, int m){          //  倍增算法 r为待匹配数组  n为总长度 m为字符范围
    int i, j, p, *x = wa, *y = wb, *t;
    for(i = 0; i < m; i ++) wd[i] = 0;
    for(i = 0; i < n; i ++) wd[x[i]=r[i]] ++;
    for(i = 1; i < m; i ++) wd[i] += wd[i-1];
    for(i = n-1; i >= 0; i --) sa[-- wd[x[i]]] = i;
    for(j = 1, p = 1; p < n; j *= 2, m = p){
        for(p = 0, i = n-j; i < n; i ++) y[p ++] = i;
        for(i = 0; i < n; i ++) if(sa[i] >= j) y[p ++] = sa[i] - j;
        for(i = 0; i < n; i ++) wv[i] = x[y[i]];
        for(i = 0; i < m; i ++) wd[i] = 0;
        for(i = 0; i < n; i ++) wd[wv[i]] ++;
        for(i = 1; i < m; i ++) wd[i] += wd[i-1];
        for(i = n-1; i >= 0; i --) sa[-- wd[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i ++){
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p - 1: p ++;
        }
    }
}

void calHeight(int *r, int n){           //  求height数组。
    int i, j, k = 0;
    for(i = 1; i <= n; i ++) Rank[sa[i]] = i;
    for(i = 0; i < n; height[Rank[i ++]] = k){
        for(k ? k -- : 0, j = sa[Rank[i]-1]; r[i+k] == r[j+k]; k ++);
    }
}

int Log[nMax];
int best[20][nMax];
void initRMQ(int n) {//初始化RMQ
	for(int i = 1; i <= n ; i ++) best[0][i] = height[i];
	for(int i = 1; i <= Log[n] ; i ++) {
		int limit = n - (1<<i) + 1;
		for(int j = 1; j <= limit ; j ++) {
			best[i][j] = min(best[i-1][j] , best[i-1][j+(1<<i>>1)]);
		}
	}
}
int lcp(int a,int b) {//询问a,b后缀的最长公共前缀
	a = Rank[a];    b = Rank[b];
	if(a > b) swap(a,b);
	a ++;
	int t = Log[b - a + 1];
	return min(best[t][a] , best[t][b - (1<<t) + 1]);
}

char str[nMax];
int ans[nMax];

int main(){
    int i,j,n,cas=0;
	Log[0] = -1;
	for(int i=1;i<=nMax;i++){
		Log[i]=(i&(i-1))?Log[i-1]:Log[i-1] + 1 ;
	}
    while(scanf("%s",str)!=EOF&&str[0]!='#'){
        n=strlen(str);
        for(i=0;i<n;i++){
            num[i]=str[i]-'a'+1;
        }num[n]=0;
        da(num, n + 1,30);
        calHeight(num,n);
        initRMQ(n);
        int l,r,t,k,maxx=-1,a;
        for(l=1;l<n;l++){     //枚举长度
            for(i=0;i+l<n;i+=l){
                k=lcp(i,i+l);
				cout<<k<<endl;
                r=k/l+1;
                t=l-k%l;
                t=i-t;
                if (t>=0&&k%l!=0){
                    if(lcp(t,t+l)>=k) r++;
                }
                if(r>maxx){
                    a=0;
                    maxx=r;
                    ans[a++]=l;
                }
                if(a==maxx){
                    ans[a++]=l;
                }
            }
        }
        int start,b=0,c;
        for(i=1;i<=n&&!b;i++){  //sa数组是保证字典序的神器啊 Orz
            for(j=0;j<a;j++){
                int tl=ans[j];
                if(lcp(sa[i],sa[i]+tl)>=(maxx-1)*tl){
                    start=sa[i];
                    l=tl*maxx;
                    b=1;
                    break;
                }
            }
        }
        printf("Case %d: ",++cas);
        for (int i=0;i<l;i++) printf("%c",str[start+ i]);
        printf("\n");
    }
    return 0;
}
*/