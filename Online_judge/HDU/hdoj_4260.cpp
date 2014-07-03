#include <cstdio>
#include <cstring>
#include <iostream>
#define LL long long
using namespace std;

LL h[64];
char s[100],p[3][3];

void dfs(int i,LL cnt,char goal)
{
    if (i==-1) { printf("%I64d\n",cnt); return; }
    if (goal==s[i]) dfs(i-1,cnt,goal);
    else {
        dfs(i-1,(LL)cnt+(LL)h[i]+1,p[s[i]-65][goal-65]);
    }
}

int main()
{
    for (int i=1; i<=63; i++) h[i]=(1LL<<i)-1;
    p[0][1]=p[1][0]='C';
    p[0][2]=p[2][0]='B';
    p[1][2]=p[2][1]='A';
    while (gets(s),s[0]!='X')
    {
        int l=strlen(s);
        dfs(l-1,0,'B');
    }
    return 0;
}
