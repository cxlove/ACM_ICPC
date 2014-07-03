#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int c[30][30];
	char str[100];
	for(int i=1;i<=26;i++){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	while(scanf("%s",str)!=EOF){
		int j,l=strlen(str);
		long long ans=0;
		for(j=0;j<l-1;j++)
			if(str[j]>=str[j+1])
				break;
		if(j<l-1){
			printf("0\n");
			continue;
		}
		for(int i=1;i<l;i++)
			ans+=c[26][i];
		for(int i=0;i<l;i++){
			char ch=(i==0?'a':str[i-1]+1);
			for(;ch<str[i];ch++)
				ans+=c['z'-ch][l-i-1];
		}
		printf("%I64d\n",++ans);
	}
	return 0;
}