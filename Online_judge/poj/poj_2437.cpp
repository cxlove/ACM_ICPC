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
int n,d;
struct Node{
	int l,r;
}a[10000];
bool cmp(Node n1,Node n2){
	return n1.l<n2.l;
}
int main(){
	while(scanf("%d%d",&n,&d)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d%d",&a[i].l,&a[i].r);
		sort(a,a+n,cmp);
		int ans=0,pos=-inf;
		for(int i=0;i<n;i++){
			if(a[i].l>pos){
				ans+=(a[i].r-a[i].l+d-1)/d;
				pos=(a[i].r-a[i].l+d-1)/d*d+a[i].l;
			}
			else if(a[i].r>pos){
				ans+=(a[i].r-pos+d-1)/d;
				pos=(a[i].r-pos+d-1)/d*d+pos;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}