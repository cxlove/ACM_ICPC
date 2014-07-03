#include <iostream>
#include <queue>
#include<cstring>
#include<cstdio>
using namespace std;
#define MIN(A,B) ((A) <= (B)? (A) : (B));  //返回最小值 

const int MAX = 200 + 10;
const int INF = 1<<30;
int flow[MAX][MAX];  //流量
int cap[MAX][MAX];  //容量
int p[MAX];  //父编号数组
int a[MAX];  //残量

int n;  //nodes
int np;  //power stations
int nc;  //consumers
int m;  //power transport lines

void EdmondsKarp(int s, int t)
{
 int u, v;
 queue<int> q;
 int f = 0;
 while (true)
 {
  memset(a, 0, sizeof(a));
  q.push(s);
  a[s] = INF;
  
  while (!q.empty())
  {
   u = q.front();
   q.pop();   
   for (v=0; v<=n+1; v++)
   {
    if (a[v] == 0 && cap[u][v] > flow[u][v])
    {
     p[v] = u;
     a[v] = MIN(a[u], cap[u][v] - flow[u][v]);  //s-v路径上的最小残量
     q.push(v);
    }
   }
  }
  if (a[t] == 0)
  {
   break;
  }
  for (v=t; v!=s; v=p[v])
  {
   flow[p[v]][v] += a[t];  //更新正向流量
   flow[v][p[v]] -= a[t];  //更新反向流量
  }
  f += a[t]; 
 }
 printf("%d\n", f);
}

int main()
{
 int u, v, w, i;
 char ch;

 while (scanf("%d%d%d%d", &n, &np, &nc, &m) != EOF)
 {
  memset(cap, 0, sizeof(cap));
  memset(flow, 0, sizeof(flow));
  // 输入边信息 
  for (i=0; i<m; i++)
  {
   cin>>ch>>u>>ch>>v>>ch>>w;
   cap[u+1][v+1] = w;
  }
  // 输入发电厂的信息 
  for (i=0; i<np; i++)
  {
   cin>>ch>>u>>ch>>w;
   cap[0][u+1] = w;
  }
  // 输入用户的信息 
  for (i=0; i<nc; i++)
  {
   cin>>ch>>u>>ch>>w;
   cap[u+1][n+1] = w;
  }
  EdmondsKarp(0, n+1);
 }
 return 0;
}
