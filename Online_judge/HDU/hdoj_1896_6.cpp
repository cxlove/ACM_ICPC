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
using namespace std;
struct Node{
    int p,d;
    bool operator<(const Node t) const{
        return p!=t.p?p>t.p:d>t.d;
    }
};
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        Node temp;
        priority_queue<Node>que;
        while(!que.empty())
            que.pop();
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&temp.p,&temp.d);
            que.push(temp);
        }
        int k=1;
        while(!que.empty()){
            temp=que.top();
            que.pop();
            if(k&1){
                temp.p+=temp.d;
                que.push(temp);
            }
            k++;
        }
        printf("%d\n",temp.p);
    }
    return 0;
}