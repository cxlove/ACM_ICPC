#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;
const int N = 205;
const int M = 1000000;
const int INF = 1000000000;
const double eps = 1e-6;
int sqr (int d) {
    return d * d;
}
inline int dcmp (double d) {
    return d < -eps ? -1 : d > eps;
}
struct Point {
    double x , y;
    Point () {}
    Point (int _x , int _y):x(_x) , y(_y) {}
    void input () {
        scanf ("%lf %lf" , &x , &y);
    }
    void output () {
        printf ("%f %f " , x , y);
    }
    double dist (Point &p) {
        return sqrt(sqr (x - p.x) + sqr (y - p.y));
    }
    inline bool operator == (const Point &p) const {
        return dcmp (x - p.x) == 0 && dcmp (y - p.y) == 0;
    }
    inline Point operator - (const Point &p) const {
        return Point (x - p.x , y - p.y);
    }
    inline Point operator + (const Point &p) const {
        return Point (x + p.x , y + p.y);
    }
    inline Point turnLeft () {
        return Point (-y , x);
    }
    inline double operator * (const Point &p) const {
        return x * p.y - y * p.x;
    }
};
struct LICH {
    Point p;
    int r , t;
    void input () {
        p.input ();
        scanf ("%d %d" ,&r , &t);
    }
}lich[N];
struct WISP {
    Point p;
    void input () {
        p.input ();
    }
}wisp[N];
struct TREE {
    Point p;
    int r;
    void input () {
        p.input ();
        scanf ("%d" , &r);
    }
}tree[N];
struct Line {
    Point a , b;
    Line () {}
    Line (Point _a , Point _b) :a(_a) , b(_b) {}
    inline double operator * (const Point &p) const {
        return (b - a) * (p - a);
    }
    inline double DisPointToSeg (Point p) {
        if (a == b) return a.dist (p);
        Point q = p + (a - b).turnLeft ();
        if (((p - a) * (q - a)) * ((p - b) * (q - b)) > 0) {
            return min (p.dist (a) ,p.dist (b));
        }
        return fabs ((*this) * p) / a.dist (b);
    }
};
bool can[N][N];
int n , m , k;

bool gao (LICH l , WISP w) {
    // l.p.output ();w.p.output ();cout << l.p.dist (w.p) << " " << l.r << endl;
    if (dcmp(l.p.dist (w.p) - l.r) > 0) return false;
    for (int i = 0 ; i < k ; i ++) {
        // cout << Line (l.p , w.p).DisPointToSeg(tree[i].p) << " " << tree[i].r << endl;
        if (dcmp(Line (l.p , w.p).DisPointToSeg(tree[i].p) - tree[i].r) <= 0)
            return false;
    }
    return true;
}
struct edge
{
    int u,v,w,next;
}e[M];

int head[N * 5],tot,source,sink,level[N * 5],cur[N * 5];

bool bfs(){
    queue<int> q;
    memset(level,-1,sizeof(level));
    level[source] = 0;
    q.push(source);
    while(! q.empty()){
        int u = q.front();q.pop();
        for(int i = head[u];i != -1;i = e[i].next){
            int v = e[i].v;
            if(e[i].w && level[v] == -1){
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[sink] != -1;
}

int dfs(int u,int flow){
    if(u == sink) return flow;
    int tmp = flow;
    for(int &i = cur[u];i != -1;i = e[i].next){
        int v = e[i].v;
        if(e[i].w && level[v] == level[u] + 1){
            int add = dfs(v,min(e[i].w,tmp));
            tmp -= add;
            e[i].w -= add;
            e[i ^ 1].w += add;
            if(! tmp) break;
        }
    }
    return flow - tmp;
}

int dinic(){
    int maxFlow = 0;
    while(bfs()){
        for(int i = 0;i < N * 5;i ++)
            cur[i] = head[i];
        maxFlow += dfs(source,int(1e9));
    }
    return maxFlow;
}

void add_edge(int u,int v,int w){
    e[tot].u = u , e[tot].v = v , e[tot].w = w;
    e[tot].next = head[u] , head[u] = tot ++;
}

void _add(int u,int v,int w){
    add_edge(u,v,w);
    add_edge(v,u,0);
}

bool check(int limit){
    for(int i = 0;i < tot;i += 2){
        e[i].w += e[i ^ 1].w;
        e[i ^ 1].w = 0;
    }
    for(int i = 0;i < n;i ++){
        int c = i << 1;
        e[c].w = limit / lich[i].t + 1;
        e[c ^ 1].w = 0;
    }
    int ret = dinic();
    return ret == m;
}

int solve(){
    memset(head,-1,sizeof(head));
    tot = 0;
    source = N * 5 - 2 , sink = N * 5 - 1;
    for(int i = 0;i < n;i ++)
        _add(source,i,0);
    for(int i = 0;i < n;i ++)
        for(int j = 0;j < m;j ++)
            if(can[i][j]) _add(i,j + n,1);
    for(int j = 0;j < m;j ++)
        _add(n + j,sink,1);
    // printf("END:%d\n",bfs());
    int l = 0 , r = 0;
    int ans = -1;
    for(int i = 0;i < n;i ++)
        r = max(r,lich[i].t);
    r *= m;
    while(l <= r){
        int mid = (l + r) >> 1;
        // printf("l:%d  r:%d  mid:%d\n",l,r,mid);
        if(check(mid)) ans = mid , r = mid - 1;
        else l = mid + 1;
    }
    return ans;
}

int main () {
    // freopen("input.txt","r",stdin);
    int t ;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d %d" , &n , &m , &k);
        for (int i = 0 ; i < n ; i++)
            lich[i].input ();
        for (int i = 0 ; i < m ; i ++)
            wisp[i].input ();
        for (int i = 0 ; i < k ; i ++)
            tree[i].input ();
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                can[i][j] = gao (lich[i] , wisp[j]);
            }
        }
        // for(int i = 0;i < n;i ++)
        //     for(int j = 0;j < m;j ++)
        //         printf("i:%d j:%d  can:%d\n",i,j,can[i][j]);
        int ans = solve();
        printf("%d\n",ans);
    }
    return 0;
}
        