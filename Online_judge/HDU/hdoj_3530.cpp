#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<deque>
using namespace std;
const int N=100005;
int a[N],n,m,k;
int main(){
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        deque<int>mx,mn;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        mx.push_back(1);mn.push_back(1);
        int diff=-1,ans=0;
        for(int i=1,j=2;i<=n;i++){
            while(j<=n+1&&(mx.empty()||mn.empty()||a[mx.front()]-a[mn.front()]<=k)){
                if(mx.empty()||mn.empty()) diff=-1;
                else diff=a[mx.front()]-a[mn.front()];
                if(j==n+1) {j++;break;}
                while(!mx.empty()&&a[j]>a[mx.back()]) mx.pop_back();
                while(!mn.empty()&&a[j]<a[mn.back()]) mn.pop_back();
                mx.push_back(j);mn.push_back(j);
                j++;
            }
            if(diff>=m&&diff<=k) ans=max(ans,j-i-1);
            while(!mx.empty()&&mx.front()<=i) mx.pop_front();
            while(!mn.empty()&&mn.front()<=i) mn.pop_front();
            if(mx.empty()||mn.empty()) diff=-1;
            else diff=a[mx.front()]-a[mn.front()];
        }
        printf("%d\n",ans);
    }
    return 0;
}