#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<queue>
#include<bitset>
#define inf 1<<30
#define M 2005
#define N 100005
#define maxn 300005
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson step<<1
#define rson step<<1|1
#define MOD 1000000009
#define sqr(a) ((a)*(a))
#define Key_value ch[ch[root][1]][0]
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int k,q,flag[2000005];
string s,t;
vector<int> a[26];
int main(){
    cin>>k>>t;
    for(int i=0;i<k;i++)
        s+=t;
    for(int i=0;i<s.size();i++)
        a[s[i]-'a'].pb(i);
    cin>>q;
    while(q--){
        char ch[3];
        int m;
        cin>>m>>ch;
        int id=ch[0]-'a';
        flag[a[id][m-1]]=1;
        a[id].erase(a[id].begin()+m-1);
    }
    for(int i=0;i<s.size();i++)
        if(!flag[i])
            cout<<s[i];


    return 0;
}