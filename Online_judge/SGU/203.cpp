#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
using namespace std;
priority_queue<long long,vector<long long>,greater<long long> >que;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        long long k;scanf("%lld",&k);
        que.push(k);
    }
    long long sum=0;
    for(int i=1;i<n;i++){
        long long t=que.top();que.pop();
        t+=que.top();que.pop();
        sum+=t;
        que.push(t);
    }
    printf("%lld\n",sum);
    return 0;
}
