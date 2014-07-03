#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#define inf 1<<29
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
using namespace std;
struct Trie
{
    Trie *next[26];
    int cnt;
};
int n,m;
Trie *NewNode()
{
    Trie *tmp=new Trie();
    mem(tmp->next,NULL);
    tmp->cnt=0;
    return tmp;
}
void Insert(Trie *root,char *s,int len)
{
    Trie *tmp=root;
    for(int i=0; i<len; i++)
    {
        if(tmp->next[s[i]-'a']==NULL) tmp->next[s[i]-'a']=NewNode();
        tmp=tmp->next[s[i]-'a'];
        tmp->cnt++;
    }
}
int slove(Trie *root,char *s,int len)
{
    Trie *tmp=root;
    for(int i=0;i<len;i++)
    {
        int id=s[i]-'a';
        if(tmp->next[id]==NULL) return 0;
        tmp=tmp->next[id];
    }
    return tmp->cnt;
}
void Delete(Trie *p)
{
    if(p!=NULL)
    {
        for(int i=0;i<26;i++) Delete(p->next[i]);
        delete p;
        p=NULL;
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        Trie *root=NewNode();
        for(int i=0; i<n; i++)
        {
            char str[50];
            scanf("%s",str);
            Insert(root,str,strlen(str));
        }
        int ans=0;
        for(int i=0; i<m; i++)
        {
            int k;
            char str[50];
            scanf("%d",&k);
            for(int r=0; r<k; r++)
            {
                double a[8],mmax=-inf,mmin=inf;
                for(int j=0; j<8; j++)
                {
                    scanf("%lf",&a[j]);
                    mmax=max(mmax,a[j]);
                    mmin=min(mmin,a[j]);
                }
                int tmp=0;
                for(int j=0; j<8; j++)
                {
                    if(fabs(a[j]-mmin)<fabs(a[j]-mmax)) tmp=tmp*2+0;
                    else tmp=tmp*2+1;
                }
                str[r]=(char)tmp;
            }
            ans+=slove(root,str,k);
        }
        printf("%d\n",ans);
        Delete(root);
    }
    return 0;
}