#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int count;
bool vis[26];
int a[26],b[27];
void dfs(int k){
	if(!vis[k]){
		count++;
		vis[k]=true;
		dfs(a[k]);
	}
}
int main(){
	int t;	
	scanf("%d",&t);
	char str[30];
	while(t--){
		scanf("%s",str);
		for(int i=0;i<26;i++)
			a[i]=str[i]-'A';
		memset(vis,false,sizeof(vis));
		memset(b,0,sizeof(b));
		for(int i=0;i<26;i++){
			if(!vis[i]){
				count=1;
				vis[i]=true;
				dfs(a[i]);
				b[count]++;
			}
		}
		int i;
		for(i=2;i<=26;i+=2)
			if(b[i]%2!=0)
				break;
		if(i==28)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}



		
