#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#define eps 1e-10
#define LL long long
#define LD long double
#define pi acos(-1.0)
#define inf 1LL<<60
using namespace std;
struct Node{
	int p,d;
}a[10000];
bool cmp(Node n1,Node n2){
	return n1.p>n2.p;
}
int n;
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d%d",&a[i].p,&a[i].d);
		sort(a,a+n,cmp);
		int ans=0;
		bool flag[10005];
		memset(flag,false,sizeof(flag));
		for(int i=0;i<n;i++){
			if(flag[a[i].d]==false){
				flag[a[i].d]=true;
				ans+=a[i].p;
			}
			else{
				for(int t=a[i].d-1;t>0;t--){
					if(flag[t]==false){
						ans+=a[i].p;
						flag[t]=true;
						break;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}