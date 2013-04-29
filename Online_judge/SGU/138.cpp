#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N = 105;
const int M = 10005;
struct Node{
    int id,cnt;
    bool operator<(const Node n)const{
        return cnt<n.cnt;
    }
}a[N];
int n,sum=0;
pair<int,int>ans[M];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        a[i].id=i+1;
        cin>>a[i].cnt;
        sum+=a[i].cnt;
    }
    sort(a,a+n);
    int l=0,r=n-1;
    cout<<sum/2<<endl;
    for(int i=0,j=n-1;i<sum/2;i++){
        ans[i].first=a[j].id;
        a[j].cnt--;
        if(a[j].cnt==0){
            j--;
            ans[i].second=a[j].id;
            swap(ans[i].first,ans[i].second);
            a[j].cnt--;
            if(a[j].cnt==0) j--;
        }
    }
    for(int i=0,j=n-1;i<sum/2;i++){
        if(ans[i].second!=0) continue;
        while(a[j].cnt==0) j--;
        ans[i].second=a[j].id;
        a[j].cnt--;
    }
    for(int i=0;i<sum/2;i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    return 0;
}
