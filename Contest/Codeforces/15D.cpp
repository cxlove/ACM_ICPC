#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
using namespace std;
typedef long long LL;
const int N = 1005;
int n, m, a, b;
LL sum[N][N];
bool vis[N][N];
int num[N][N], l[N][N], rightdown[N][N];
struct Node{
    int x, y;
    LL amount;
    Node(){}
    Node(int _x,int _y,LL _a):x(_x),y(_y),amount(_a){}
    bool operator< (const Node &n)const {
        if (amount != n.amount)
            return amount < n.amount;
        if (x != n.x) return x < n.x;
        return y < n.y;
    }
};
vector<Node> ans,ret;
int main(){
    scanf ("%d%d%d%d", &n, &m, &a, &b);
    for (int i = 1 ; i <= n ; i ++){
        deque <int> que;
        while (!que.empty()) que.pop_back();
        for (int j = 1 ; j <= m ; j ++){
            scanf ("%d", &num[i][j]);
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + num[i][j];
            while (!que.empty() && que.front() + b <= j) que.pop_front();
            while (!que.empty() && num[i][j] < num[i][que.back()]) que.pop_back();
            que.push_back(j);
            l[i][j] = num[i][que.front()];
        }
    }
    for (int j = b ; j <= m ; j ++){
        deque <int> que;
        while (!que.empty()) que.pop_back();
        for (int i = 1 ; i <= n ; i ++){
            while (!que.empty() && que.front() + a <= i) que.pop_front();
            while (!que.empty() && l[i][j] < l[que.back()][j]) que.pop_back();
            que.push_back(i);
            rightdown[i][j] = l[que.front()][j];
        }
    }
    for (int i = 1 ; i + a -1 <= n ; i ++){
        for (int j = 1 ; j + b - 1 <= m ; j++){
            LL matrix_sum = sum[i + a - 1][j + b - 1] - sum[i - 1][j + b - 1] - sum[i + a - 1][j - 1] + sum[i - 1][j - 1];
            ans.push_back(Node(i, j, matrix_sum - (LL)a * b * rightdown[i + a -1][j + b - 1]));
        }
    }
    sort (ans.begin(), ans.end());
    for (int r = 0 ; r < ans.size() ; r ++){
        int x = ans[r].x, y = ans[r].y;
        if (vis[x][y]) continue;
        ret.push_back(ans[r]);
        for (int i = max(1, x - a + 1) ; i <= x + a - 1 ; i ++){
            for (int j = max(1, y - b + 1) ; j <= y + b - 1 ; j++){
                vis[i][j] = true;
            }
        }
    }
    printf("%d\n", ret.size());
    for (int i = 0 ; i < ret.size() ; i ++){
        printf("%d %d %I64d\n", ret[i].x, ret[i].y, ret[i].amount);
    }
    return 0;
}
