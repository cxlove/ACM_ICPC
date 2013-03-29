#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<ctime>
#define LL long long
#define mp(a,b) make_pair(a,b)
using namespace std;
const int N=100005;
int n,t;
int a[N],b[N];
stack<pair<int,int> >s;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        while(!s.empty()) s.pop();
        int idx=0,mx=-1;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(a[i]>mx)
                mx=a[i],idx=i;
        }
        for(int i=0;i<n;i++)
            b[i]=a[(i+idx)%n];
        LL ans=0;
        for(int i=0;i<n;i++){
            while(!s.empty()&&b[i]>s.top().first) ans+=s.top().second,s.pop();
            if(s.empty()||b[i]<s.top().first) ans+=(s.empty()?0:1),s.push(mp(b[i],1));
            else{
                pair<int,int>u=s.top();s.pop();
                if(!s.empty()) ans+=1;
                s.push(u);
                ans+=s.top().second,s.top().second++; 
            }
        }
        while(s.size()>2){
            ans+=s.top().second;
            s.pop();
        }
        if(s.size()==2){
            pair<int,int>u=s.top();s.pop();
            if(s.top().second>1) ans+=u.second;
        }
        printf("%I64d\n",ans);
    }
    //printf("%.6lf",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}