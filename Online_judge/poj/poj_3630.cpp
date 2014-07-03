#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct Trie{
	bool isword;
	int num;
	int son[10];
}Trie_Node[100001];
int idx;
bool insert(char *s,int len){
	int p=0;
	for(int i=0;i<len;i++){
		if(Trie_Node[p].son[s[i]-'0']==NULL)
			Trie_Node[p].son[s[i]-'0']=++idx;	
		p=Trie_Node[p].son[s[i]-'0'];
		Trie_Node[p].num++;
     	if(Trie_Node[p].isword)
			return false;
	}
	Trie_Node[p].isword=true;
	if(Trie_Node[p].num>1)
		return false;
	return true;
}
int main(){
	int t,n;
	char str[15];
	scanf("%d",&t);
	while(t--){
		memset(Trie_Node,0,sizeof(Trie_Node));
		bool flag=true;
		idx=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%s",str);
			if(flag)
				flag=insert(str,strlen(str));
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}