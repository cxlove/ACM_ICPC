#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<set>
#include<vector>
#include<map>
#include<algorithm>
#define N 210005
#define inf 100000000
#define MOD 100000007
#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))
#define Key_value ch[ch[root][1]][0]
#define _match(a,b) ((a)==(b))
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
LL ans;
map<LL ,int>mp;char str[20];
void dfs(int l,int r,LL num,LL t){
    if(l>r){if(t==0) mp[num]++;return ;}
    t=t*10+str[l]-'0';
    dfs(l+1,r,num+t,0);
    dfs(l+1,r,num,t);
}
void dfs2(int l,int r,LL num,LL t){
    if(l>r){if(t==0&&mp.find(num)!=mp.end()) ans+=mp[num];return ;}
    t=t*10+str[l]-'0';
    dfs2(l+1,r,num+t,0);
    dfs2(l+1,r,num,t);
}
int main(){

    while(scanf("%s",str)!=EOF){
        if(str[0]=='E') break;
        int l=strlen(str);
        ans=0;
        for(int i=1;i<l;i++){
            mp.clear();
            dfs(0,i-1,0,0);
            dfs2(i,l-1,0,0);
        //    cout<<"33333333333"<<endl;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}