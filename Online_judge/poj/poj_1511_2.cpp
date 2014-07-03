#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX = 1000001;
const int inf = 1<<30;//!!!!!!!!!!1!!!!!!!!!!
int N,m,n;

typedef struct vol
{
 int w,//当前位置
  v,//价值 value
  next;//下一结点的位置
} Voll;
Voll peo[MAX],rev[MAX];

int start1[MAX], start2[MAX];
int queue[MAX];  //优化序列
int path[MAX];   // path[i] 从1即到i当前最短路

__int64 SPFA( Voll peor[], int startt[])
{

 int i,start=0,end=1,temp;
 temp = 1;
 for(i=0;i<n+1;i++)
 {
  path[i] = inf;
 }
 
 path[temp] = 0;
 queue[0] = temp;

 while(start<end)
 {
  temp = queue[start];
  start++;

  for(i=startt[temp]; i!=-1; i=peor[i].next)
  {
   if(peor[i].v + path[temp] < path[peor[i].w])
   {
    path[peor[i].w] = peor[i].v + path[temp];
    queue[end++] = peor[i].w;
   }
  }
 }
 //
 __int64 sum=0;
 for(i=1;i<=n;i++)
 {
  sum+=path[i];
 }
 return sum;
}

void init()
{
 scanf("%d %d", &n, &m);
 int i,x,y,v;

 fill(start1, start1 + n+1, -1);//应该是 n+1!!!!!   - -!
 fill(start2, start2 + n+1, -1);
 
 for(i=0;i<m;i++)
 {
  scanf("%d %d %d",&x,&y,&v);

  peo[i].w = y;
  peo[i].v = v;
  peo[i].next = start1[x];   //保存邻接表串的始端位置，逆向实现相当给力

  start1[x] = i;      
  
  ///reverse反向
  rev[i].w = x;
  rev[i].v = v;
  rev[i].next = start2[y];
  start2[y] = i;
 }
}

int main()
{
 scanf("%d", &N);
 while(N--)
 {
  init(); 
  printf("%I64d\n", SPFA(peo, start1) + SPFA(rev, start2));
 }
 return 0;
}