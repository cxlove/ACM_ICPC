#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

const int maxn = 1000000 + 100;
#define keyTree (ch[ch[root][1]][0])
int root, top1, top2;
int ch[maxn][2];
int pre[maxn];
int sz[maxn];
int ss[maxn], que[maxn];

int n, m;
int val[maxn];
bool rev[maxn];
int num[maxn];
int cnt;

inline void pushUp(int x)
{
    sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
}

inline void pushDown(int x)
{
    if (rev[x]) {
        rev[ch[x][0]] ^= 1;
        rev[ch[x][1]] ^= 1;
        swap(ch[x][0], ch[x][1]);
        rev[x] = false;
    }
}

inline void Rotate(int x, int f)
{
    int y = pre[x];
    pushDown(y); pushDown(x);
    ch[y][!f] = ch[x][f];
    pre[ch[x][f]] = y;
    if (pre[y]) {
        if (ch[pre[y]][0] == y) {
            ch[pre[y]][0] = x;
        } else {
            ch[pre[y]][1] = x;
        }
    }
    pre[x] = pre[y]; ch[x][f] = y;
    pre[y] = x; pushUp(y);
}

inline void Splay(int x, int goal)
{
    pushDown(x);
    while (pre[x] != goal) {
        if (pre[pre[x]] == goal) {
            Rotate(x, ch[pre[x]][0] == x);
        } else {
            int y = pre[x], z = pre[y];
            if (ch[z][0] == y) {
                if (ch[y][0] == x) {
                    Rotate(y, 1); Rotate(x, 1);
                } else {
                    Rotate(x, 0); Rotate(x, 1);
                }
            } else {
                if (ch[y][0] == x) {
                    Rotate(x, 1); Rotate(x, 0);
                } else {
                    Rotate(y, 0); Rotate(x, 0);
                }
            }
        }
    }
    pushUp(x);
    if (0 == goal) root = x;
}

inline void RotateTo(int k, int goal) {
    int x = root;
    pushDown(x);
    while (k != sz[ch[x][0]] + 1) {
        if (k <= sz[ch[x][0]]) {
            x = ch[x][0];
        } else {
            k -= (sz[ch[x][0]] + 1);
            x = ch[x][1];
        }
        pushDown(x);
    }
    Splay(x, goal);
}

inline void Erase(int x)
{
    int father = pre[x];
    /*int head = 0, tail = 0;
    for (que[tail++] = x; head < tail; ++head) {
        ss[top2++] = que[head];
        if (ch[que[head]][0]) que[tail++] = ch[que[head]][0];
        if (ch[que[head]][1]) que[tail++] = ch[que[head]][1]; 
    }*/
    ch[father][ch[father][1] == x] = 0;
    pushUp(father);
} 

inline void NewNode(int &x, int c, int f)
{
    if (top2) x = ss[--top2];
    else x = ++top1;
    ch[x][0] = ch[x][1] = 0;
    sz[x] = 1; pre[x] = f;
    val[x] = c; rev[x] = false;
}

inline void MakeTree(int &x, int l, int r, int f)
{
    if (l > r) return ;
    int m = (l + r) >> 1;
    NewNode(x, num[m], f);
    MakeTree(ch[x][0], l, m - 1, x);
    MakeTree(ch[x][1], m + 1, r, x);
    pushUp(x);
}

void Init()
{
    root = top1 = top2 = 0;
    ch[0][0] = ch[0][1] = pre[0] = sz[0] = 0;
    NewNode(root, -1, 0);
    NewNode(ch[root][1], -1, root);
    sz[root] = 2;
    
    MakeTree(keyTree, 1, n, ch[root][1]);
    pushUp(ch[root][1]);
    pushUp(root);
}

inline void Insert(int a, int b, int v)
{
    RotateTo(a + 1, 0);
    RotateTo(b + 1, root);
    int x;
    NewNode(x, v, ch[root][1]);
    ch[ch[root][1]][0] = x;
    pushUp(ch[root][1]);
    pushUp(root);
}

inline void Flip(int a, int b)
{
    RotateTo(a, 0);
    RotateTo(b + 2, root);
    rev[keyTree] ^= 1;
}

void Treaval(int x) {
        if(x) {
            pushDown(x);
            Treaval(ch[x][0]);
            if (cnt == 0) {
                printf("%d", val[x]);
            } else {
                printf(" %d", val[x]);
            }
            cnt++;
            Treaval(ch[x][1]);
        }
}

void PrintAns()
{
    RotateTo(1, 0);
    RotateTo(n + 2, root);
    cnt = 0;
    Treaval(keyTree);
    printf("\n");
}

int main()
{
    int t, L, R;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &num[i]);
        }
        Init();
        scanf("%d%d", &L, &R);
        scanf("%d", &m);
        char op[20];
        char hand;
        int insval;
        while (m--) {
            scanf("%s", op);
            if (op[0] == 'M') {
                while (hand = getchar()) {
                    if (hand != ' ') break;
                }
                if (op[4] == 'L') {
                    if (hand == 'R') {
                        R--;
                    } else {
                        L--;
                    }
                } else {
                    if (hand == 'R') {
                        R++;
                    } else {
                        L++;
                    }
                }
            } else if (op[0] == 'I') {
                while (hand = getchar()) {
                    if (hand != ' ') break;
                }
                scanf("%d", &insval);
                if (hand == 'R') {
                    Insert(R, R + 1, insval); 
                    R++;
                } else {
                    Insert(L - 1, L, insval);
                    R++;
                } 
                n++;
            } else if (op[0] == 'D') {
                while (hand = getchar()) {
                    if (hand != ' ') break;
                }
                if (hand == 'R') {
                    RotateTo(R, 0);
                    RotateTo(R + 2, root);
                    Erase(keyTree);
                    R--;
                } else {
                    RotateTo(L, 0);
                    RotateTo(L + 2, root);
                    Erase(keyTree);
                    R--;
                } 
                n--;
            } else if (op[0] == 'R') {
                Flip(L, R);
            }
        }
        PrintAns();
    }
    return 0;
}
