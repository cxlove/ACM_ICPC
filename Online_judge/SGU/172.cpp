#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 205;
int n,m;
int pre[N<<1];
int find(int x){
    return pre[x]=(x==pre[x]?x:find(pre[x]));
}
int main(){
    //freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=2*n;i++)
        pre[i]=i;
    while(m--){
        int a,b;
        cin>>a>>b;
        int l1=a*2-1,l2=a*2;
        int r1=b*2-1,r2=b*2;
        if(find(l1)==find(r1)||find(l2)==find(r2)){
            puts("no");
            return 0;
        }
        if(find(l1)!=find(r2))
            pre[pre[l1]]=pre[r2];
        if(find(l2)!=find(r1))
            pre[pre[l2]]=pre[r1];
    }
    puts("yes");
    vector<int>ans;
    for(int i=1;i<=2*n;i+=2){
        if(find(i)==i){
            for(int j=1;j<=2*n;j+=2){
                if(find(j)==i){
                    ans.push_back((j+1)/2);
                }
            }
        }
    }
    sort(ans.begin(),ans.end());
    ans.resize(unique(ans.begin(),ans.end())-ans.begin());
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<(i==ans.size()-1?'\n':' ');
    return 0;
}
