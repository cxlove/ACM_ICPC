#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#define LL long long
#define MOD 31536000
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
bool clo[1005][1005];
vector<int>pants[1005];
int main()
{
    int q,n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF&&n+m+k)
    {
        int ans=0;
        mem(clo,true);
        scanf("%d",&q);
        for(int i=1;i<=m;i++) pants[i].clear();
        while(q--)
        {
            char s1[10],s2[10];
            int p1,p2;
            scanf("%s%d%s%d",s1,&p1,s2,&p2);
            if(s1[0]=='c') clo[p1][p2]=false;
            else pants[p1].push_back(p2);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(clo[i][j])
                {
                    ans+=k-pants[j].size();
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}