#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
string s,e;
int main(){
    int t,n,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        cin>>s>>e;
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());
        int ans=0;
        for(int i=0;i<n;i++)
            ans+=abs(s[i]-e[i]);
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}