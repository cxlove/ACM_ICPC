#include<iostream>
#include<cstdio>
#include <queue>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb(a) push_back(a)
#define MOD 1000000007
#define LL long long
using namespace std;
struct Node
{
    LL now;
    int len,next;
    Node(){}
    Node(LL _n,int _l,int _ne):now(_n),len(_l),next(_ne){}
    bool operator<(const Node n1)const
    {
        return now>n1.now;
    }
}u,v;
int t;
LL n;
LL fac[18];
void bfs()
{
    int L=0;
    LL tmp=n;
    while(tmp)
    {
        L++;
        tmp/=10;
    }
    priority_queue<Node>que;
    que.push(Node(0,0,0));
    while(!que.empty())
    {
        u=que.top();
       // cout<<u.now<<" "<<u.len<<" "<<u.next<<endl;
        que.pop();
        if(u.len==L) {printf("%I64d\n",u.now);return ;}
        if(u.next!=9){que.push(Node(u.now,u.len,u.next+1));}
        v=u;
        v.len++;
        v.now=v.now+fac[v.len-1]*u.next;
        v.next=0;
       // cout<<v.now<<" "<<v.len<<" "<<v.next<<endl;
        if((v.now*v.now)%fac[v.len]==n%fac[v.len]) que.push(v);
    }
    printf("None\n");
}
int main()
{
    scanf("%d",&t);
    fac[0]=1;
    for(int i=1;i<18;i++) fac[i]=fac[i-1]*10;
    while(t--)
    {
        scanf("%I64d",&n);
        bfs();
    }
    return 0;
}