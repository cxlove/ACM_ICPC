#include<iostream>
#include<cstdio>
#include<cstring>
#define LL __int64
using namespace std;
LL c[30]={1};
void Init(){
	for(int i=1;i<=25;i++){
		c[i]=c[i-1]*(4*i-2)/(i+1);
	}
}
void slove(int k,int cnt){
	if(k==1){
		printf("X");
		return;
	}
	if(cnt<=c[k-1]){
		printf("X");
		printf("(");
		slove(k-1,cnt);
		printf(")");
	}
	else if(cnt>c[k]-c[k-1]){
		printf("(");
		slove(k-1,cnt-(c[k]-c[k-1]));
		printf(")");
		printf("X");
	}
	else{
		int t=k-1,m;
		for(int i=t;i>=0;i--){
			if(c[i]*c[t-i]<cnt)
				cnt-=c[i]*c[t-i];
			else{
				m=i;
				break;
			}
		}
		printf("(");
		slove(t-m,cnt/c[m]+(cnt%c[m]!=0));
		printf(")X(");
		slove(m,(cnt-1)%c[m]+1);
		printf(")");
	}
}
int main(){
	int n,m;
	Init();
	while(scanf("%d",&n)!=EOF&&n){
		for(int i=1;;i++){
			if(n>c[i])
				n-=c[i];
			else{
				m=i;
				break;
			}
		}
		slove(m,n);
		printf("\n");
	}
	return 0;
}