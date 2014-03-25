#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
typedef long long LL;
const int N = 1000005;
int jump[N];
int n , k;
LL x[N] , y[N];
vector <int> e[N];
int d[N] , p[N][20];
const int POW = 18;  
void dfs(int u,int fa){  
    d[u]=d[fa]+1;  
    p[u][0]=fa;  
    for(int i=1;i<POW;i++) p[u][i]=p[p[u][i-1]][i-1];  
    int sz=e[u].size();  
    for(int i=0;i<sz;i++){  
        int v=e[u][i];  
        if(v==fa) continue;  
        dfs(v,u);  
    }  
}  
int lca( int a, int b ){  
    if( d[a] > d[b] ) a ^= b, b ^= a, a ^= b;  
    if( d[a] < d[b] ){  
        int del = d[b] - d[a];  
        for( int i = 0; i < POW; i++ ) if(del&(1<<i)) b=p[b][i];  
    }  
    if( a != b ){  
        for( int i = POW-1; i >= 0; i-- )   
            if( p[a][i] != p[b][i] )   
                 a = p[a][i] , b = p[b][i];  
        a = p[a][0], b = p[b][0];  
    }  
    return a;  
}  
LL xmul (int i , int j , int k) {
	return (x[j] - x[i]) * (y[k] - y[i]) - (y[j] - y[i]) * (x[k] - x[i]);
}
	int que[N] , cnt = 0;
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
#endif
	scanf ("%d" , &n);
	k = 1;
	for (int i = 1 ; i <= n ; i ++) {
		scanf ("%I64d %I64d" , &x[i] , &y[i]);
	}
	que[cnt ++] = n;que[cnt ++] = n - 1;
	e[n].push_back (n - 1);
	for (int i = n - 2 ; i >= 1 ; i --) {
		while (cnt > 1 && xmul (que[cnt - 2] , que[cnt - 1] , i) < 0) {
			cnt --;
		}
		e[que[cnt - 1]].push_back (i);
		// cout << que[cnt - 1] << " " << i << endl;
 		que[cnt ++] = i;
	}
	dfs (n , -1);
	int q;
	scanf ("%d" , &q);
	while (q --) {
		int u , v;scanf ("%d %d" , &u , &v);
		// u --;v --;
		printf ("%d\n" , lca (u , v));
	}
	return 0;
}