
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 100015
#define inf 1<<29
#define MOD 100000007
#define LL long long
#define Key_value ch[ch[root][1]][0]
#define _match(a,b) ((a)==(b))
using namespace std;
int t,l;
char word[100],ch[100];
char str[N],s[2*N];
int pat_match(int lp,char * pat){
    int fail[2*N]={-1},i=0,j;
    memset(fail,-1,sizeof(fail));
    int mmax=0;
    for (j=l+(l+1)/2;j<lp;j++){
        for (i=fail[j-1];i>=0&&!_match(pat[i+1],pat[j]);i=fail[i]);
        fail[j]=(_match(pat[i+1],pat[j])?i+1:-1);
    }
    return fail[lp-1]+1;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%s%s",word,str);
        l=strlen(str);
        for(int i=0;i<26;i++)
            ch[word[i]-'a']=i+'a';
        for(int i=0;i<l;i++){
            s[i]=ch[str[i]-'a'];
            s[i+l]=str[i];
        }
        s[2*l]='\0';
        int a=l-pat_match(2*l,s);
        str[a]='\0';
        //cout<<l-a<<endl;
        printf("%s",str);
        for(int i=0;i<a;i++)
            printf("%c",ch[str[i]-'a']);
        puts("");
    }
    return 0;
}
