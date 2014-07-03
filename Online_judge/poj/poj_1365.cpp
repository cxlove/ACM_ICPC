#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
using namespace std;
int a[100],b[100];
int prime[10000],count=0,cnt;
bool flag[1000005]={0};
int Pow(int x,int y){
	if(y==1) return x;
	return Pow(x,y-1)*x;
}
void Prime(){
	for(int i=2;i<=350;i++){
		if(flag[i]) continue;
		for(int j=2;j*i<=100000;j++)
			flag[i*j]=true;
	}
	for(int i=2;i<=100000;i++)
		if(!flag[i])
	    	prime[count++]=i;
}
void slove(int num){
	cnt=0;
	for(int i=count-1;i>=0;i--)
		if(num%prime[i]==0){
			a[cnt]=prime[i];
			b[cnt]=0;
			while(num%prime[i]==0){
				b[cnt]++;
				num/=prime[i];
			}
			cnt++;
			if(num==1) break;
		}
}int main(){
	char str1[10],str2[10];
	Prime();
	while(1){
		cnt=0;
		while(scanf("%s",str1)){
			if(strcmp(str1,"0")==0) return 0;
			scanf("%s",str2);
			a[cnt]=0;b[cnt]=0;
			for(int i=0;i<strlen(str1);i++)
				a[cnt]=a[cnt]*10+str1[i]-'0';
			for(int i=0;i<strlen(str2);i++)
				b[cnt]=b[cnt]*10+str2[i]-'0';
			char ch=getchar();cnt++;
			if(ch=='\n')
				break;
			
		}
		int sum=1;
		for(int i=0;i<cnt;i++)
			sum=sum*Pow(a[i],b[i]);
		slove(sum-1);
		printf("%d %d",a[0],b[0]);
		for(int i=1;i<cnt;i++)
			printf(" %d %d",a[i],b[i]);
		printf("\n");
	}
	return 0;
}