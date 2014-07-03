//#include<iostream>
//#include<cstdio>
//#include<cstring>
//using namespace std;
//int n,a[230][230],ans[230];
//char str[20][20];
//void gauss(){
//
//}
//int main(){
//	int t;
//	scanf("%d",&t);
//	while(t--){
//		scanf("%d",&n);
//		memset(ans,0,sizeof(ans));
//		for(int i=0;i<n;i++)
//			scanf("%s",str[i]);
//		for(int i=0;i<n;i++){
//			for(int j=0;j<n;j++)
//				if(str[i][j]=='y')
//					a[i*n+j][n*n]=0;
//				else
//					a[i*n+j][n*n]=1;
//		}
//		for(int i=0;i<n*n;i++){
//			a[i][i]=1;
//			if(i%n!=0)
//				a[i-1][i]=1;
//			if(i%n!=(n-1))
//				a[i+1][i]=1;
//			if(i>=n)
//				a[i+n][i]=1;
//			if(i<=n*(n-1))
//				a[i-n][i]=1;
//		}
//		gauss();
//	}
//}
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
using namespace std;
int a[31][31];  //系数矩阵
int ans[31];
void gauss(){
	for(int i=0;i<30;i++){
		int k=i;
		for(;k<30;k++)
			if(a[k][i]!=0)
				break;
		for(int j=0;j<=30;j++)
			swap(a[i][j],a[k][j]);
		for(int j=0;j<30;j++)
			if(i!=j&&a[j][i])
				for(int k=0;k<=30;k++)
					a[j][k]=a[i][k]^a[j][k];
	}
}
int main(){
	int t,tt=0;
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));
		for(int i=0;i<30;i++){
			scanf("%d",&a[i][30]);
			ans[i]=0;
		}
		for(int i=0;i<30;i++){
			a[i][i]=1;
			if(i%6!=0)
				a[i-1][i]=1;
			if(i%6!=5)
				a[i+1][i]=1;
			if(i>5)
				a[i-6][i]=1;
			if(i<24)
				a[i+6][i]=1;
		}
		gauss();
		/*for(int i=0;i<30;i++){
		for(int j=0;j<=30;j++)
		printf("%d ",a[i][j]);
		printf("\n");
		}*/
		for(int j=0;j<30;j++)  
			ans[j]=a[j][30];
			/*if(a[j][30]){  
				for(int k=0;k<30&&!a[j][k];k++);    
				ans[j]=a[j][30];  
			} */
			printf("PUZZLE #%d\n",++tt);
			for(int i=0;i<30;i++){
				printf("%d",ans[i]);
				if(i%6==5)
					printf("\n");
				else
					printf(" ");
			}
	}
	return 0;
}