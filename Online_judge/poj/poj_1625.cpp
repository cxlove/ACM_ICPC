/*
ID:cxlove
PROB:poj 1625 Censored
DATA:2012.2.18
HINT:高精度+DP+AC自动机
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct Trie{
	int isword,kind;
	Trie *fail,*son[50];
};
struct BigNum{
	int a[20];
}dp[55][1005];
Trie *que[1000001],vec[10000];
int n,m,q,idx,id[1000];
Trie *NewTrie(){
	Trie *temp=&vec[idx];
	temp->fail=NULL;
	for(int i=0;i<n;i++)
		temp->son[i]=NULL;
	temp->kind=idx;
	temp->isword=false;
	idx++;
	return temp;
}
void insert(Trie *root,char *s,int len){
	Trie *temp=root;
	for(int i=0;i<len;i++){
		if(temp->son[id[s[i]+200]]==NULL)
			temp->son[id[s[i]+200]]=NewTrie();
		temp=temp->son[id[s[i]+200]];
	}
	temp->isword=true;
}
void DeleteTrie(Trie *root){
	if(root!=NULL){
		for(int i=0;i<n;i++)
			DeleteTrie(root->son[i]);
		delete root;
		root=NULL;
	}
}
void bulid_fail(Trie *root){
	int head=0,tail=0;
	que[tail++]=root;
	while(head<tail){
		Trie *temp=que[head++];
		for(int i=0;i<n;i++)
			if(temp->son[i]!=NULL){
				if(temp==root) temp->son[i]->fail=root;
				else{
					Trie *p=temp->fail;
					while(p!=NULL){
						if(p->son[i]!=NULL){
							temp->son[i]->fail=p->son[i];
							if(p->son[i]->isword)
								temp->son[i]->isword=true;
							break;
						}
						p=p->fail;
					}
					if(p==NULL)
						temp->son[i]->fail=root;
				}
				que[tail++]=temp->son[i];
			}
	}
}
BigNum add(BigNum n1,BigNum n2){
	BigNum ans;
	memset(ans.a,0,sizeof(ans.a));
	int l=max(n1.a[0],n2.a[0]);
	int mod=1000000000;
	int c=0;
	for(int i=1;i<=l;i++){
		int temp=c;
		if(n1.a[0]>=i) temp+=n1.a[i];
		if(n2.a[0]>=i) temp+=n2.a[i];
		ans.a[i]=temp%mod;
		c=temp/mod;
	}
	if(c>0) ans.a[++l]=c;
	ans.a[0]=l;
	return ans;
}
void print(BigNum ans);
void DP(Trie *root){
	for(int i=0;i<=m;i++)
		for(int j=0;j<=idx;j++){
			dp[i][j].a[0]=1;
			dp[i][j].a[1]=0;
		}
	dp[0][1].a[1]=1;
	for(int i=0;i<m;i++){
		for(int j=1;j<idx;j++){
			for(int k=0;k<n;k++){
				Trie *temp=vec[j].son[k];
				if(temp!=NULL){
					if(temp->isword==0)
						dp[i+1][temp->kind]=add(dp[i][j],dp[i+1][temp->kind]);
				}
				else{
					Trie *p=vec[j].fail;
					while(p!=NULL){
						if(p->son[k]!=NULL) break;
						p=p->fail;
					}
					if(p==NULL) p=root;
					else p=p->son[k];
					if(p->isword==0)
						dp[i+1][p->kind]=add(dp[i][j],dp[i+1][p->kind]);
				}
			}
		}
	}
	BigNum ans;
	memset(ans.a,0,sizeof(ans.a));
	for(int i=1;i<idx;i++)
		ans=add(ans,dp[m][i]);
	print(ans);
}
void print(BigNum ans){
	int i;
	for(i=ans.a[0];i>0;i--)
		if(ans.a[i]!=0) 
			break;   
	if(i<=0) puts("0");  
	else{  
		printf("%d",ans.a[i]);
		for(i--;i>0;i--)      
			printf("%09d",ans.a[i]);
		printf("\n");
	}
}
int main(){
	char str[100];
	while(scanf("%d%d%d",&n,&m,&q)!=EOF){
		idx=1;
		Trie *root=NewTrie();
		scanf("%s",str);
		for(int i=0;str[i]!='\0';i++)
			id[str[i]+200]=i;
		for(int i=0;i<q;i++){
			scanf("%s",str);
			insert(root,str,strlen(str));
		}
		bulid_fail(root);
		DP(root);
	//	DeleteTrie(root);
	}
	return 0;
}





