#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
void slove(int n,int *a,int times){
	if(n<=0)
		return;
	for(int i=1;i<=n%10;i++)
		a[i]+=times;
	int p=n/10;
	while(p>0){
		a[p%10]+=(n%10+1)*times;
		p=p/10;
	}
	for(int i=0;i<=9;i++)
		a[i]+=times*(n/10);
	times*=10;
	slove(n/10-1,a,times);
}
int main(){
	int a,b;
	int dig1[10],dig2[10];
	while(scanf("%d%d",&a,&b)!=EOF&&a+b){
		if(a>b)
			swap(a,b);
		memset(dig1,0,sizeof(dig1));
		memset(dig2,0,sizeof(dig2));
		slove(b,dig1,1);
		slove(a-1,dig2,1);
		for(int i=0;i<10;i++){
			printf("%d",dig1[i]-dig2[i]);
			if(i==9)
				printf("\n");
			else
				printf(" ");
		}
	}
	return 0;
}