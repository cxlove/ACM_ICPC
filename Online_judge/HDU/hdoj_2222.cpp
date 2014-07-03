/*
ID:cxlove
PROB:HDU 2222 Keywords Search
DATA:2012.2.16
HINT:AC自动机
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct Trie{
    int wordcount;
    Trie *fail;
    Trie *son[26];
}*que[1000001];
Trie *NewTrie(){
    Trie *temp=new Trie;
    temp->wordcount=0;temp->fail=NULL;
    for(int i=0;i<26;i++)
        temp->son[i]=NULL;
    return temp;
}
void insert(Trie *tree,char *s,int len){
    Trie *temp=tree;
    for(int i=0;i<len;i++){
        if(temp->son[s[i]-'a']==NULL) temp->son[s[i]-'a']=NewTrie();
        temp=temp->son[s[i]-'a'];
    }
    temp->wordcount++;
}
void DeleteTrie(Trie *tree){
    if(tree!=NULL){
        for(int i=0;i<26;i++)
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
        for(int i=0;i<26;i++){
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
int AC(Trie *root,char *s,int len){
    Trie *p=root;
    int cnt=0;
    for(int i=0;i<len;i++){
        while(p->son[s[i]-'a']==NULL&&p!=root)
            p=p->fail;
        p=p->son[s[i]-'a'];
        p=(p==NULL)?root:p;
        Trie *temp=p;
        while(temp!=root){
            cnt+=temp->wordcount;
            temp->wordcount=0;
            temp=temp->fail;
        }
    }
    return cnt;
}
int main(){
    int t,n;
    char str[1000005];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        Trie *root=NewTrie();
        while(n--){
            scanf("%s",str);
            insert(root,str,strlen(str));
        }
        bulid_fail(root);
        scanf("%s",str);
        printf("%d\n",AC(root,str,strlen(str)));
        DeleteTrie(root);
    }
    return 0;
}