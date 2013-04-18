#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
const int mod = 1000000007;
using namespace std;
int a[1010];
int main()
{
    int n;
    map<int,int> mp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        mp[a[i]] ++;
    }
    int ans = 0;
    for(map<int,int>::iterator it = mp.begin();it!=mp.end();it++)
    {
        if(it->first==0) continue;
        if(it->second>2) return puts("-1"),0;
        else if(it->second==2) ans++;
    }
    printf("%d\n",ans);
    return 0;
}