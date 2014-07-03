/*
ID:cxlove
PROB:HDU 2896 病毒侵袭
DATA:2012.2.16
HINT:AC自动机
*/
/*
ID:cxlove
PROB:HDU 2222 Keywords Search
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
vector<int>ans;
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
bool AC(Trie *root,char *s,int len){
    Trie *p=root;
    int cnt=0;
    bool flag=false;
    for(int i=0;i<len;i++){
        while(p->son[s[i]]==NULL&&p!=root)
            p=p->fail;
        p=p->son[s[i]];
        p=(p==NULL)?root:p;
        Trie *temp=p;
        while(temp!=root){
            if(temp->wordcount>0){
                flag=true;
                ans.push_back(temp->wordcount);
            }
            temp=temp->fail;
        }
    }
    return flag;
}
int main(){
    int t,n;
    char str[10005];
    scanf("%d",&n);
    Trie *root=NewTrie();
    for(int i=1;i<=n;i++){
        scanf("%s",str);
        insert(root,str,strlen(str),i);
    }
    bulid_fail(root);
    scanf("%d",&n);
    int total=0;
    for(int i=1;i<=n;i++){
        scanf("%s",str);
        ans.clear();
        if(AC(root,str,strlen(str))){
            printf("web %d:",i);
            sort(ans.begin(),ans.end());
            for(int i=0;i<ans.size();i++)
                if(i==0||ans[i]!=ans[i-1])
                    printf(" %d",ans[i]);
            printf("\n");
            total++;
        }        
    }
    printf("total: %d\n",total);
    DeleteTrie(root);
    return 0;
}





