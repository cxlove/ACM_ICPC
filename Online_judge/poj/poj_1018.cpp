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
#define inf 1LL<<60
using namespace std;
struct Node{
	int b,p;
}a[400][400];
int t,m[400],B[160000],cnt,n;
bool cmp(Node n1,Node n2){
	return n1.p<n2.p;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		cnt=0;
		for(int i=0;i<n;i++){
			scanf("%d",&m[i]);
			for(int j=0;j<m[i];j++){
				scanf("%d%d",&a[i][j].b,&a[i][j].p);
				B[cnt++]=a[i][j].b;
			}
			sort(a[i],a[i]+m[i],cmp);
		}
		sort(B,B+cnt);
		int CNT=1;
		for(int i=1;i<cnt;i++)
			if(B[i]!=B[CNT-1])
				B[CNT++]=B[i];
		double ans=0;
		for(int k=0;k<CNT;k++){
			int ptmp=0,flag=1;
			for(int i=0;i<n;i++){
				int j;
				for(j=0;j<m[i];j++)
					if(a[i][j].b>=B[k])
						break;
				if(j==m[i]){
					flag=0;
					break;
				}
				ptmp+=a[i][j].p;
			}
			if(flag)
				ans=max(ans,B[k]*1.0/ptmp);
		}
		printf("%.3f\n",ans);
	}
	return 0;
}

