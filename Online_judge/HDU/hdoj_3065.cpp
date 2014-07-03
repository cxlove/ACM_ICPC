/*
ID:cxlove
PROB:HDU 3065 病毒侵袭持续中
DATA:2012.2.16
HINT:AC自动机
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct Trie{
    int wordcount;
    Trie *fail;
    Trie *son[130];
}*que[1000001];
int cnt[1005]={0};
char word[1005][55];
char str[2000005];
Trie *NewTrie(){
    Trie *temp=new Trie;
    temp->wordcount=0;temp->fail=NULL;
    for(int i=0;i<130;i++)
        temp->son[i]=NULL;
    return temp;
}
void insert(Trie *tree,char *s,int len,int k){
    Trie *temp=tree;
    for(int i=0;i<len;i++){
        if(temp->son[s[i]]==NULL) temp->son[s[i]]=NewTrie();
        temp=temp->son[s[i]];
    }
    temp->wordcount=k;;
}
void DeleteTrie(Trie *tree){
    if(tree!=NULL){
        for(int i=0;i<130;i++)
            DeleteTrie(tree->son[i]);
        delete tree;
        tree=NULL;
    }
}
void bulid_fail(Trie *root){
    Trie *p=root;
    Trie *temp;
    root->fail=NULL;
    int head=0,tail=0;
    que[tail++]=root;
    while(head<tail){
        temp=que[head++];
        for(int i=0;i<130;i++){
            if(temp->son[i]==NULL)
                continue;
            if(temp==root)
                temp->son[i]->fail=root;
            else{
                p=temp->fail;
                while(p!=NULL){
                    if(p->son[i]!=NULL){
                        temp->son[i]->fail=p->son[i];
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
void AC(Trie *root,char *s,int len){
    Trie *p=root;
    bool flag=false;
    for(int i=0;i<len;i++){
        while(p->son[s[i]]==NULL&&p!=root)
            p=p->fail;
        p=p->son[s[i]];
        p=(p==NULL)?root:p;
        Trie *temp=p;
        while(temp!=root){
            if(temp->wordcount>0)
                cnt[temp->wordcount]++;
            temp=temp->fail;
        }
    }
}
int main(){
    int n;    
    while(scanf("%d",&n)!=EOF){
        Trie *root=NewTrie();
        for(int i=1;i<=n;i++){
            scanf("%s",word[i]);
            insert(root,word[i],strlen(word[i]),i);
        }
        bulid_fail(root);
        memset(cnt,0,sizeof(cnt));
        scanf("%s",str);
        AC(root,str,strlen(str));
        for(int i=1;i<=n;i++)
            if(cnt[i])
                printf("%s: %d\n",word[i],cnt[i]);
        DeleteTrie(root);
    }
    return 0;
}
