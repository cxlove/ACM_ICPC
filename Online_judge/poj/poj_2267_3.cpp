#include<iostream>
#include<cstring>
#include<map>
#include<string>
#include<cstdio>
using namespace std;

using namespace std;
const int MAXN = 1100;
const int MAXM = MAXN*MAXN;
struct node
{
       int  v, next;
       int day;
}mapp[1000000];
struct edge
{
       int u, v;
       int stime, etime;
}ed[MAXM];
map <string, int> maze;
int head[MAXM];
int id;
void init()
{
     id = 0;
     memset(head, -1, sizeof(head));     
}

void addedge(int u, int v,int da)
{
     mapp[id].v = v, mapp[id].day = da, mapp[id].next = head[u], head[u] = id ++;
}
const int inf = 1 << 30;
int ans;
int Que[100*MAXM];
int dist[MAXM];
bool inque[MAXM];
void SPFA(int s, int e, int n)
{
     int front, rear;
     front = rear = 0;
     for (int i = 1; i < n; i ++){
         dist[i] = inf, inque[i] = false;
         if (ed[i].u == s){
            Que[rear ++] = i;
            inque[i] = true;
            dist[i] = 0;            
         }
     }
     while (front < rear ){
           int pre = Que[front ++];
           inque[pre] = false;
           for (int i = head[pre]; i != -1; i = mapp[i].next){
               int v = mapp[i].v;
               if (dist[v] > dist[pre]+mapp[i].day){
                   dist[v] = dist[pre]+mapp[i].day;
                   if (!inque[v]){
                      Que[rear ++] = v;
                      inque[v] = true;               
                   }
               }    
           }      
     }
     for (int i = 1; i < n; i ++){
         if (ans > dist[i] && ed[i].v == e){
            ans = dist[i];            
         }   
     }
}
int check(int i, int j)
{
    //这里有点纠结，要考虑需要消耗一升血的条件，当发车时间和到站时间都<=6或者都>=18时，显然当到站时间大于发车时间时，吸血鬼要等待一天，这样必然要消耗一升血
    //当到站时间<=6并且发车时间>=18时因为要经过12：00所以也要消耗一升血 
    if ((ed[j].stime < ed[i].etime&&((ed[j].stime <= 6 && ed[i].etime <= 6) || (ed[j].stime >= 18 && ed[i].etime >= 18))) || (ed[j].stime >= 18 && ed[i].etime <= 6))
       return 1;
    else return 0; 
}
int main()
{
    int t;
    scanf("%d", &t);
    int nc = 0;
    while (t --){
          int m;
          init();
          scanf("%d", &m);
          maze.clear();
          string a, b;
          int c, d;
          int len = 1;
          int num = 1;        
          while (m --){
                cin >> a >> b;
                scanf("%d%d", &c, &d);
                if (!maze[a]) 
                   maze[a] = num ++;
                if (!maze[b])
                   maze[b] = num ++;
                c%=24;
                if (c >= 18 && (c+d) <= 30 || (c <= 6 && (c+d) <= 6)){//当前时间为合法时间 
                   ed[len].u = maze[a], ed[len].v  = maze[b], ed[len].stime = c, ed[len ++].etime = (c+d)%24;
                }
          }
          
          cin >> a >> b;
          printf("Test Case %d.\n", ++ nc);
          if (maze[a] == maze[b]){
             printf("Vladimir needs 0 litre(s) of blood.\n");            
             continue;
          }
          if (maze[a] == 0 || maze[b] == 0){
             printf("There is no route Vladimir can take.\n");            
             continue;       
          }
          for (int i = 1; i < len; i ++){
              for (int j = 1; j < len; j ++){
                  if (ed[i].v == ed[j].u){//如果存在一条合法边 
                     int k = check(i, j);
                     addedge(i, j, k);
                  }    
              }
          } 
          ans = inf;
          SPFA(maze[a], maze[b], len); 
          if (ans == inf) printf("There is no route Vladimir can take.\n");
          else printf("Vladimir needs %d litre(s) of blood.\n", ans);
    }   
    return 0;    
}