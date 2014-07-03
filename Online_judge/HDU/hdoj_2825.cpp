/*
ID:cxlove
PROB:HDU 2825 Wireless Password
DATA:2012.2.28
HINT:AC自动机+DP+状态压缩
*/
#include<iostream>
#include<cstdio>
using namespace std;
struct Trie{
    Trie *fail,*son[26];
    int idx;
    int word;
}tree[300],*que[300];
int cnt,n,m,num,sum[1<<10]={0};
int dp[27][300][1<<10];
Trie *NewTrie(){
    Trie *temp=&tree[cnt];
    memset(temp->son,NULL,sizeof(temp->son));
    temp->fail=NULL;
    temp->idx=cnt;
    temp->word=0;
    cnt++;
    return temp;
}
void insert(Trie *root,char *s,int len,int k){
    Trie *temp=root;
    for(int i=0;i<len;i++){
        if(temp->son[s[i]-'a']==NULL)
            temp->son[s[i]-'a']=NewTrie();
        temp=temp->son[s[i]-'a'];
    }
    temp->word=(temp->word|1<<k);
}
void bulid_fail(Trie *root){
    int head=0,tail=0;
    que[tail++]=root;
    root->fail=root;
    while(head<tail){
        Trie *temp=que[head++];
        for(int i=0;i<26;i++)
            if(temp->son[i]!=NULL){
                if(temp==root)
                    temp->son[i]->fail=root;
                else
                    temp->son[i]->fail=temp->fail->son[i];
                temp->son[i]->word|=temp->son[i]->fail->word;
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
void DeleteTrie(Trie *root){
    if(root!=NULL){
        for(int i=0;i<26;i++)
            DeleteTrie(root->son[i]);
        delete root;
        root=NULL;
    }
}
int main(){
    char word[15];
    for(int i=1;i<(1<<10);i++)
        sum[i]=sum[i>>1]+(i&1);
    while(scanf("%d%d%d",&n,&m,&num)){
        if(n==0&&m==0&&num==0)
            break;
        cnt=0;
        Trie *root=NewTrie();
        for(int i=0;i<m;i++){
            scanf("%s",word);
            insert(root,word,strlen(word),i);
        }
        bulid_fail(root);
        //memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++)
            for(int j=0;j<=cnt;j++)
                for(int k=0;k<(1<<m);k++)
                    dp[i][j][k]=0;
        dp[0][0][0]=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<cnt;j++)
                for(int k=0;k<(1<<m);k++)
                    if(dp[i][j][k]){
                        for(int r=0;r<26;r++)
                            if(tree[j].son[r]==NULL)
                                continue;
                            else
                                dp[i+1][tree[j].son[r]->idx][k|tree[j].son[r]->word]=(dp[i][j][k]+dp[i+1][tree[j].son[r]->idx][k|tree[j].son[r]->word])%20090717;
                    }
        int ans=0;
        for(int i=0;i<cnt;i++)
            for(int j=0;j<(1<<m);j++)
                if(sum[j]>=num)
                    ans=(ans+dp[n][i][j])%20090717;
        printf("%d\n",ans);
    //    DeleteTrie(root);
    }
    return 0;
}
/*
10 2 2
hello 
world 
4 1 1
icpc 
10 0 0
0 0 0
*/

