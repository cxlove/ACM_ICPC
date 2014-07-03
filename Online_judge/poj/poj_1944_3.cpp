#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1010;
const int INF = 0x7FFFFFFF;
int cover[2 * MAXN];
vector<int> g[2 * MAXN];
int cal(int s, int n)
{
int b, ret;
b = ret = 0;
for(int i = s; i <= s + n - 1; i++) {
if(cover[i] > i) {
if(i >= b) {
ret += cover[i] - i;
b = cover[i];
}else if(cover[i] > b) {
ret += cover[i] - b;
b = cover[i];
}
}
}
return ret;
}
int main()
{
int i, n, p;
int a, b, temp;;
scanf("%d %d", &n, &p);
memset(cover, 0, sizeof(cover));
for(i = 1; i <= n; i++) g[i].clear();
for(i = 1; i <= p; i++) {
scanf("%d %d", &a, &b);
if(a > b) {
temp = a; a = b; b = temp;
}
if(b > cover[a]) cover[a] = b;
g[a].push_back(b);
}
int ans = INF;
vector<int>::iterator it;
for(int i = 1; i <= n; i++) {
int t = cal(i, n);
if(t < ans) ans = t;
for(it = g[i].begin(); it != g[i].end(); it++) {
g[*it].push_back(i + n);
if(i + n > cover[*it]) cover[*it] = i + n;
}
}
printf("%d\n", ans);
return(0);
}

