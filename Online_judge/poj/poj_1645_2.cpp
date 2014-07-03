#include<iostream>  
#include<cstdio>  
#include<map>  
#include<cstring>  
#include<cmath>  
#include<vector>  
#include<stack>
#include<algorithm>  
#include<set>  
#include<string>  
#include<queue>  
#define inf 1600005  
#define M 1000005  
#define N 1000005
#define maxn 2000005  
#define eps 1e-7
#define zero(a) fabs(a)<eps  
#define Min(a,b) ((a)<(b)?(a):(b))  
#define Max(a,b) ((a)>(b)?(a):(b))  
#define pb(a) push_back(a)  
#define mp(a,b) make_pair(a,b)  
#define mem(a,b) memset(a,b,sizeof(a))  
#define LL long long  
#define lson step<<1
#define rson step<<1|1
#define sqr(a) ((a)*(a))  
#define Key_value ch[ch[root][1]][0]  
#define test puts("OK");
#define pi acos(-1.0)
#define lowbit(x) ((x)&(-(x)))
#pragma comment(linker, "/STACK:1024000000,1024000000")  
#define vi vector<int> 
using namespace std;
struct Point{
    int x,y;
}p1,p2,t;
struct Node{
    vector<int>s;
    int id;
    Point p;
    Node(){}
    Node(int _i):id(_i){s.clear();}
    bool operator<(const Node n)const{
        int l1=s.size(),l2=n.s.size();
        for(int i=0;i<min(l1,l2);i++)
            if(s[i]<n.s[i]) return true;
            else if(s[i]>n.s[i]) return false;
        if(l1>l2) return true;
        else return false;
    }
};
vector<Node>v;
int n,m;
LL xmul(Point p,Point p1,Point p2){
    return ((LL)(p1.x-p.x)*(p2.y-p.y)-(p1.y-p.y)*(p2.x-p.x));
}
int main(){
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&n)!=EOF){
        v.clear();
        for(int i=0;i<n;i++){
            v.pb(Node(i));
            int k;
            scanf("%d",&k);
            while(k--){
                scanf("%d%d",&t.x,&t.y);
            }
            v[v.size()-1].p=t;
        }
        scanf("%d",&m);
        while(m--){
            scanf("%d%d%d%d",&p1.x,&p1.y,&p2.x,&p2.y);
            t.x=0;t.y=-10000;
            for(int i=0;i<n;i++){
                if(((LL)xmul(p1,p2,v[i].p)*xmul(p1,p2,t))<0) v[i].s.pb(1);
                else v[i].s.pb(2);
            }
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
            printf("%c",v[i].id+'A');
        printf("\n");
    }
    return 0;
}