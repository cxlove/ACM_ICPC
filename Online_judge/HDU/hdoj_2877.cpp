#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 1<<25
using namespace std;
struct Trie{
    int price;
    Trie *son[30];
};
int n,m,mmap[15][10005];
int cnt,color[30];
Trie *NewTrie(){
    Trie *temp=new Trie;
    temp->price=-1;
    for(int i=0;i<30;i++)
        temp->son[i]=NULL;
    return temp;
}
void Insert(Trie *root,int *s,int len,int pri){
    Trie *temp=root;
    for(int i=0;i<len;i++){
        if(temp->son[s[i]]==NULL)
            temp->son[s[i]]=NewTrie();
        temp=temp->son[s[i]];
    }
    if(temp->price==-1)
        temp->price=pri;
    else
        temp->price=min(temp->price,pri);
}
void DeleteTrie(Trie *root){
    if(root!=NULL){
        for(int i=0;i<30;i++)
            DeleteTrie(root->son[i]);
        root=NULL;
        delete root;
    }
}
int find(int num){
    for(int i=0;i<cnt;i++)
        if(color[i]==num)
            return i;
    color[cnt++]=num;
    return cnt-1;
}
int dp[10005]={0};
int DP(Trie *root){
    int sum=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)
            dp[j]=inf;
        for(int j=1;j<=n;j++){
            Trie *temp=root;
            for(int k=j;;k++){
                temp=temp->son[mmap[i][k]];
                if(temp==NULL)
                    break;
                else
                    if(temp->price>=0)
                        dp[k]=min(dp[j-1]+temp->price,dp[k]);
            }
        }
        if(dp[n]==inf)
            return -1;
        sum+=dp[n];
    }
    return sum;
}
int main(){
    int t,x1,x2,y1,y2,col;
    while(scanf("%d%d",&m,&n)!=EOF){
        Trie *root=NewTrie();
        scanf("%d",&t);
        cnt=0;
        while(t--){
            scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&col);
            col=find(col);
            for(int i=x1+1;i<=x2;i++)
                for(int j=y1+1;j<=y2;j++)
                    mmap[i][j]=col;
        }
        scanf("%d",&t);    
        for(int i=0;i<t;i++){
            int l,pri,a[25];
            scanf("%d%d",&pri,&l);
            for(int j=0;j<l;j++){
                scanf("%d",&a[j]);
                a[j]=find(a[j]);
            }
            Insert(root,a,l,pri);
        }
        int ans=DP(root);
        if(ans==-1)
            printf("impossible\n");
        else
            printf("%d\n",ans);
        DeleteTrie(root);
    }
    return 0;
}
