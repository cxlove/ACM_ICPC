//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<cmath>
//#include<queue>
//#define inf 1<<30
//using namespace std;
//struct Node{
//    int u,v,w,next;
//}edge[70005];
//int n,m,start[3005],cnt,dist[3005],ret[3005];
//void addedge(int u,int v,int w){
//    edge[cnt].u=u;edge[cnt].v=v;edge[cnt].w=w;
//    edge[cnt].next=start[u];start[u]=cnt++;
//}
//void Init(){
//    int u,v,w;
//    scanf("%d%d",&n,&m);
//    memset(start,-1,sizeof(start));
//    cnt=0;
//    while(m--){
//        scanf("%d%d%d",&u,&v,&w);
//        addedge(u,v,w);
//    }
//}
//int main(){
//    int t;
//    scanf("%d",&t);
//    while(t--){
//        Init();
//    }
//}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int t,n,k;
struct Node{
    int v,idx;
    string name;
    bool operator<(const Node t) const{
        return v!=t.v?v<t.v:idx>t.idx;
    }
}temp;
vector<int>que;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        que.clear();
        for(int i=0;i<n;i++){
            cin>>k;
            que.push_back(k);
        }
        sort(que.begin(),que.end(),cmp);
        int sum=0;
        for(int i=2;i<n;i=i+3)
            sum+=que[i];
        cout<<sum<<endl;
    }
    return 0;
}
    
    