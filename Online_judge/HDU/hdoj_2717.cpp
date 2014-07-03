#include<iostream>
#include<cstring>
using namespace std;
struct Node{
    int t,step;
}node,q[200005];
int N,K,i;
bool vis[200005];
int bfs();
int main()
{
    int ans;
    while(cin>>N>>K)
    {
        memset(vis,false,sizeof(vis));
        ans=bfs();
        cout<<ans<<endl;
    }
    return 0;
}
int bfs()
{
   int head=0,tail=0,j;
   node.t=N;node.step=0;
   q[tail++]=node;
   while(head<tail)
   {
       Node cur;
       cur=q[head++];
       if(cur.t==K) return cur.step;
       for(j=0;j<3;j++)
       {
           Node next;
           if(j==0)
           {
               next.t=cur.t+1;
               next.step=cur.step+1;
           }
           else if(j==1)
           {
               next.t=cur.t-1;
               next.step=cur.step+1;
           }
           else
           {
               next.t=cur.t*2;
               next.step=cur.step+1;
           }
           if(next.t>=0&&next.t<=200000&&(!vis[next.t]))
           {
               q[tail++]=next;
               vis[next.t]=true;
           }
       }
   }
}
