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
using namespace std;
int t,n,k;
struct Node{
    int p,v,idx;
    string name;
    bool operator<(const Node t) const{
        return v!=t.v?v>t.v:idx>t.idx;
    }
}temp;
int main(){
    string ope;
    Node temp;
    int idx=0;
    priority_queue<Node>que;
    while(!que.empty())
        que.pop();
    while(cin>>ope){                
        if(ope=="GET"){
            if(que.empty())
                cout<<"EMPTY QUEUE!\n";
            else{
                temp=que.top();
                que.pop();
                cout<<temp.name<<" "<<temp.p<<endl;
            }
        }
        else{
            cin>>temp.name>>temp.p>>temp.v;
            temp.idx=idx++;
            que.push(temp);
        }
    }
    return 0;
}