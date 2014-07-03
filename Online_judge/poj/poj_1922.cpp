#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<string>
#include<vector>
#define eps 1e-6
#define LL long long
#define LD long double
#define pi acos(-1.0)
#define inf 1<<30
using namespace std;
struct Node {
	int v,t,need;
}a[10000];
int n;
int main(){
	while(scanf("%d",&n)!=EOF&&n){
		for(int i=0;i<n;i++)
			scanf("%d%d",&a[i].v,&a[i].t);
		for(int i=0;i<n;i++){
			if(a[i].t<0)
				a[i].need=inf;
			else{
				a[i].need=(int)((4500*3.6)/a[i].v+a[i].t);
				if((int)(4500*3.6)%a[i].v)
					a[i].need++;
			}
		}
		int ans=a[0].need;
		for(int i=1;i<n;i++)
			ans=min(ans,a[i].need);
		printf("%d\n",ans);
	}
	return 0;
}