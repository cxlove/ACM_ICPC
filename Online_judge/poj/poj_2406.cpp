#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#define N 1000005
#define eps 1e-8
#define inf 1<<30
#define zero(a) fabs(a)<eps
#define pb(a) push_back(a)
using namespace std;
char str[N];
int nxt[N];
void get_next(char *s,int l){
	nxt[0]=-1;
	int i=0,j=-1;
	while(i<l){
		if(j==-1||s[i]==s[j]){
			i++;j++;
			if(s[i]==s[j]) nxt[i]=nxt[j];
			else nxt[i]=j;
		}
		else j=nxt[j];
	}
}
int main(){
	while(scanf("%s",str)!=EOF&&strcmp(str,".")){
		int l=strlen(str);
		get_next(str,l);
		int t=l-nxt[l];
		printf("%d\n",l%t?1:l/t);
	}
	return 0;
}