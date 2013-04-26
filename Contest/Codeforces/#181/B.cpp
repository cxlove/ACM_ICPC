#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int pre[50],r[50];
int n,m;
vector<int>one,two,three;
int find(int x){
    return pre[x]=(pre[x]==x?x:find(pre[x]));
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        pre[i]=i,r[i]=1;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        int fa=find(u),fb=find(v);
        if(fa!=fb) pre[fa]=fb,r[fb]+=r[fa];
    }
    for(int i=1;i<=n;i++){
        if(find(i)==i){
            if(r[i]>3){
                puts("-1");
                return 0;
            }
            if(r[i]==3) three.push_back(find(i));
            else if(r[i]==2) two.push_back(find(i));
            else if(r[i]==1) one.push_back(find(i));
        }
    }
    if(two.size()>one.size()){
        puts("-1");
        return 0;
    }
    for(int i=0;i<three.size();i++){
        for(int j=1;j<=n;j++)
            if(find(j)==three[i])
                cout<<j<<" ";
        cout<<endl;
    }
    for(int i=0;i<two.size();i++){
        for(int j=1;j<=n;j++)
            if(find(j)==two[i]||find(j)==one[i])
                cout<<j<<" ";
        cout<<endl;
    }
    for(int i=two.size();i<one.size();i+=3){
        for(int j=1;j<=n;j++)
            if(find(j)==one[i]||find(j)==one[i+1]||find(j)==one[i+2])
                cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}