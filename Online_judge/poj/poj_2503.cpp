/*
ID:cxlove
PROB:poj 2503 Babelfish
DATA:2012.2.16
HINT:Trie树
*/
#include<iostream>
#include<cstdio>
using namespace std;
struct Trie{
	bool isword;
	char word[20];
	Trie *son[26];
};
char ans[20];
Trie *NewTrie(){
	Trie *temp=new Trie;
	temp->isword=false;
	for(int i=0;i<26;i++)
		temp->son[i]=NULL;
	return temp;
}
void insert(Trie *tree,char *s,int len,char w[20]){
	Trie *temp=tree;
	for(int i=0;i<len;i++){
		if(temp->son[s[i]-'a']==NULL)  temp->son[s[i]-'a']=NewTrie();
		temp=temp->son[s[i]-'a'];
	}
	temp->isword=true;
	strcpy(temp->word,w);
}
bool find(Trie *tree,char *s,int len){
	Trie *temp=tree;
	for(int i=0;i<len;i++){
		if(temp->son[s[i]-'a']==NULL) return false;
		temp=temp->son[s[i]-'a'];
	}
	if(temp->isword==false)
		return false;
	strcpy(ans,temp->word);
	return true;
}
int main(){
	char str[100];
	Trie *tree=NewTrie();
	while(gets(str)&&strcmp(str,"")!=0){
		char s1[20],s2[20];
		sscanf(str,"%s%s",s1,s2);
		insert(tree,s2,strlen(s2),s1);
	}
	while(scanf("%s",str)!=EOF){
		if(find(tree,str,strlen(str)))
			printf("%s\n",ans);
		else
			printf("eh\n");
	}
	return 0;
}