#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 100005
#define MOD 100000
#define LL long long
using namespace std;
struct Trie{
    Trie *next[4];
    Trie *fail;
    int kind,isword;
};
Trie *que[N],s[N];
int idx;
int id(char ch){
    if(ch=='A') return 0;
    else if(ch=='T') return 1;
    else if(ch=='C') return 2;
    return 3;
}
Trie *NewTrie(){
    Trie *tmp=&s[idx];
    for(int i=0;i<4;i++) tmp->next[i]=NULL;
    tmp->isword=0;
    tmp->fail=NULL;
    tmp->kind=idx++;
    return tmp;
}
void Insert(Trie *root,char *s,int len){
    Trie *tmp=root;
    for(int i=0;i<len;i++){
        if(tmp->next[id(s[i])]==NULL) tmp->next[id(s[i])]=NewTrie();
        tmp=tmp->next[id(s[i])];
    }
    tmp->isword=1;
}
void Bulid_fail(Trie *root){
    int tail=0,head=0;
    que[tail++]=root;
    root->fail=NULL;
    while(head<tail){
        Trie *tmp=que[head++];
        for(int i=0;i<4;i++){
            if(tmp->next[i]==NULL){
                if(tmp==root) tmp->next[i]=root;
                else tmp->next[i]=tmp->fail->next[i];
            }
            else{
                if(tmp==root) tmp->next[i]->fail=root;
                else{
                    tmp->next[i]->fail=tmp->fail->next[i];
                    if(tmp->next[i]->fail->isword)
                        tmp->next[i]->isword=1;
                }
                que[tail++]=tmp->next[i];
            }
        }
    }
}
void DeleteTrie(Trie *root){
    if(root){
        for(int i=0;i<4;i++) if(root->next[i]) DeleteTrie(root->next[i]);
        delete root;
        root=NULL;
    }
}
char str[15];
struct Matrix{
    LL m[101][101];
}Init;
Matrix mult(Matrix m1,Matrix m2){
    Matrix ans;
    memset(ans.m,0,sizeof(ans.m));
    for(int i=0;i<idx;i++){
        for(int k=0;k<idx;k++){
            if(m1.m[i][k]==0) continue;
            for(int j=0;j<idx;j++){
                ans.m[i][j]+=(LL)m1.m[i][k]*m2.m[k][j];
                if(ans.m[i][j]>=MOD) ans.m[i][j]%=MOD;
            }
        }
    }
    return ans;
}
Matrix PowMod(Matrix m1,int n){
    Matrix ans;
    for(int i=0;i<idx;i++) for(int j=0;j<idx;j++) ans.m[i][j]=i==j;
    while(n){
        if(n&1) ans=mult(ans,m1);
        m1=mult(m1,m1);
        n>>=1;
    }
    return ans;
}
int main(){
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF){
        idx=0;
        Trie *root=NewTrie();
        for(int i=0;i<m;i++){
            scanf("%s",str);
            Insert(root,str,strlen(str));
        }
        Bulid_fail(root);
        memset(Init.m,0,sizeof(Init.m));
        for(int i=0;i<idx;i++){
            for(int j=0;j<4;j++){
                Trie *son=s[i].next[j];
                if(!son->isword&&!s[i].isword)
                    Init.m[i][son->kind]++;
            }
        }
        Init=PowMod(Init,n);
        LL ans=0;
        for(int i=0;i<idx;i++){
            ans+=Init.m[0][i];
            if(ans>=MOD) ans-=MOD;
        }
        printf("%I64d\n",ans);
        //DeleteTrie(root);
    }
    return 0;
}



