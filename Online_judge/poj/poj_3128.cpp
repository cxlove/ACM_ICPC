//#include<iostream>
//#include<cstdio>
//#include<cstring>
//using namespace std;
//int main(){
//	int n,s,idx=1,cnt=1,k=1;
//	int a[1000],b[1000];
//	scanf("%d%d",&n,&s);
//	for(int i=1;i<=n;i++)
//		scanf("%d",&a[i]);
//	b[1]=1;
//	while(a[idx]!=1)
//		idx=b[++cnt]=a[idx];
//	for(int i=1;i<=s;i++){
//		k*=2;
//		if(k>n) k-=n;
//	}
//	a[1]=1;idx=1;
//	for(int i=2;i<=n;i++){
//		idx+=k;
//		if(idx>n)  idx-=n;
//		a[idx]=b[i];
//	}
//	for(int i=1;i<n;i++)
//		b[a[i]]=a[i+1];
//	b[a[n]]=1;
//	for(int i=1;i<=n;i++)
//		printf("%d\n",b[i]);
//	return 0;
//}
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int t;
	char str[30];
	bool flag[30];
	int a[30];
	scanf("%d",&t);
	while(t--){
		scanf("%s",str);
		memset(flag,false,sizeof(flag));
		memset(a,0,sizeof(a));
		int cnt=0;
		for(int i=0;i<26;i++){
			if(!flag[i]){
				int temp=1,idx=i;
				flag[i]=true;
				while(str[idx]-'A'!=i){
					idx=str[idx]-'A';
					flag[idx]=true;
					temp++;
				}
		        a[temp]++;
			}
		}
		int i;
		for(i=0;i<26;i+=2)
			if(a[i]&1)
				break;
		if(i==26)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}