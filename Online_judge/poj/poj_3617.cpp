/*
ID:cxlove
PROB:Best Cow Line
DATA:2012.3.8
HINT:贪心
*/
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	char str[30005],ch[5];
	int n;
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",ch);
		str[i]=ch[0];
	}
	int i=1,j=n,sum=0;
	while(i<=j){
		if(str[i]>str[j]){
			printf("%c",str[j]);
			j--;
		}
		else if(str[i]<str[j]){
			printf("%c",str[i]);
			i++;
		}
		else{
			int t1=i,t2=j;
			while(str[t1]==str[t2]&&t1<t2){
				t1++;t2--;
			}
			if(t1>=t2){
				printf("%c",str[i]);
				i++;
			}
			else if(str[t1]<str[t2]){
				printf("%c",str[i]);
				i++;
			}
			else if(str[t1]>str[t2]){
				printf("%c",str[j]);
				j--;
			}
		}
		sum++;
		if(sum%80==0)
			printf("\n");
	}
	if(sum%80!=0)
		printf("\n");
	return 0;
}