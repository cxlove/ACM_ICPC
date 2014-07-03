/*
ID:cxlove
PROB:poj 2001 Shortest Prefixes
DATA:2012.2.16
HINT:trie树
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct trie{
	int num;
	struct trie *son[26];
};
trie *newtrie(){
	trie *temp=new trie;
	temp->num=1;
	for(int i=0;i<26;i++)
		temp->son[i]=NULL;
	return temp;
}
void insert(trie *tree,char *s,int len){
	trie *temp=tree;
	for(int i=0;i<len;i++){
		if(temp->son[s[i]-'a']!=NULL) temp->son[s[i]-'a']->num++;
		else temp->son[s[i]-'a']=newtrie();
		temp=temp->son[s[i]-'a'];
	}
}
void deletetrie(trie *tree){
	if(tree!=NULL){
		for(int i=0;i<26;i++)
			deletetrie(tree->son[i]);
		delete tree;
		tree=NULL;
	}
}
int find(trie *tree,char *s,int idx,int len){
	if(tree->son[s[idx]-'a']->num==1){
		tree->son[s[idx]-'a']->num=0;
		return idx;
	}
	if(idx==len-1)
		return len;
	find(tree->son[s[idx]-'a'],s,idx+1,len);
}
int main(){
	int n=0;
	char str[1000][25];
	trie *tree=newtrie();
	while(scanf("%s",str[n])!=EOF){
		insert(tree,str[n],strlen(str[n]));
		n++;
	}
	for(int i=0;i<n;i++){
		printf("%s ",str[i]);
		int pos=find(tree,str[i],0,strlen(str[i]));
		str[i][pos+1]='\0';
		printf("%s\n",str[i]);
	}
	deletetrie(tree);
	return 0;
}