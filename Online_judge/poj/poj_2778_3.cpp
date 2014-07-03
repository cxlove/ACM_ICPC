/*
ID:cxlove
PROB:poj 2778 DNA Sequence
DATA:2012.2.18
HINT:AC自动机+矩阵快速幂乘
*/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct Trie{
	Trie *fail,*son[4];
	bool isword;
	int kind;
};
Trie *que[100001],vec[1000];
int idx;
__int64 mat[110][110],ans[110][110];
int id(char ch){
	switch(ch){
	case 'A':return 0;
		case 'G':return 1;
			case 'T':return 2;
				case 'C':return 3;
	}
}
Trie *NewTrie(){
	Trie *temp=&vec[idx];
	for(int i=0;i<4;i++)
		temp->son[i]=NULL;
	temp->isword=false;
	temp->fail=NULL;
	temp->kind=idx;idx++;
	return temp;
}
void insert(Trie *root,char *s,int len){
	Trie *temp=root;
	for(int i=0;i<len;i++){
		if(temp->son[id(s[i])]==NULL)  temp->son[id(s[i])]=NewTrie();
		temp=temp->son[id(s[i])];
	}
	temp->isword=true;
}
void DeleteTrie(Trie *root){
	if(root!=NULL){
		for(int i=0;i<4;i++)
			DeleteTrie(root->son[i]);
		delete root;
		root=NULL;
	}
}
void bulid_fail(Trie *root){
	Trie *p=root,*temp;
	int head=0,tail=0;
	que[tail++]=root;
	root->fail=NULL;
	while(head<tail){
		temp=que[head++];
		for(int i=0;i<4;i++)
			if(temp->son[i]!=NULL){
				if(temp==root) temp->son[i]->fail=root;
				else{							
					temp->son[i]->fail=temp->fail->son[i];						
					if(temp->son[i]->fail->isword)                     
						temp->son[i]->isword=true;  
				}
				que[tail++]=temp->son[i];
			}
			else{
				if(temp==root)
					temp->son[i]=root;
				else
					temp->son[i]=temp->fail->son[i];
			}
	}
}
void MatrixMul(__int64 a[][110],__int64 b[][110],int m){  
	__int64 temp[110][110]={0};   
    for(int i=0;i<m;i++)  
       for(int j=0;j<m;j++)         
		   for(int k=0;k<m;k++){  
               temp[i][j]+=a[i][k]*b[k][j]; 
               if(temp[i][j]>=100000)  
                    temp[i][j]%=100000;  
            }  
    for(int i=0;i<m;i++)  
        for(int j=0;j<m;j++)  
            a[i][j]=temp[i][j];  
}  
void MatrixPow(__int64 t[][110],__int64 a[][110],int m,int n){
	while(n>0){
		if(n&1)
			MatrixMul(t,a,m);
		MatrixMul(a,a,m);
		n=n>>1;
	}
}
int main(){
	int n,m;
	char word[20];
	while(scanf("%d%d",&m,&n)!=EOF){
		idx=0;
		Trie *root=NewTrie();
		while(m--){
			scanf("%s",word);
			insert(root,word,strlen(word));
		}
		bulid_fail(root);		
		memset(mat,0,sizeof(mat));
		for(int i=0;i<idx;i++)
			for(int j=0;j<4;j++){
				Trie *temp=vec[i].son[j];  
                if(vec[i].isword==false&&temp->isword==false)          
					mat[i][temp->kind]++;  
           }  
		memset(ans,0,sizeof(ans));
		for(int i=0;i<idx;i++)
			ans[i][i]=1;
		MatrixPow(ans,mat,idx,n);  
		__int64 sum=0;
		for(int i=0;i<idx;i++)
			sum+=ans[0][i];
		printf("%I64d\n",sum%100000);
	//	DeleteTrie(root);
	}
	return 0;
}