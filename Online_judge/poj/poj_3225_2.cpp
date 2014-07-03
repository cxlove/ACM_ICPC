#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define maxn 65535*2


enum Lazy_Tag {
    ZERO    = 0,
    ONE     = 1,
    XOR     = 2,
    TAG_MAX = 3,
};

struct Interval {
    char operands;
    int left, right;
    Interval() {}
    Interval(char op, int l, int r) {
        operands = op;
        left = l;
        right = r;
    }
}I[maxn*5];

char id[] = {'U', 'I', 'D', 'C', 'S'};

int find(char c) {
    for(int i = 0; i < 5; i++) {
        if(c == id[i])
            return i;
    }
}

struct Tree {
    char lazy[TAG_MAX];
    int Sum;
    int root, l, r;

    void CoverBy(int mode);
    void UpdateBy(Tree* ls, Tree* rs);
    void TranslateToSon();
    void TranslateTo(Tree* ts);

    int len() {
        return r - l + 1;
    }
}T[maxn*4];
int v[maxn+1];


void Build(int root, int l, int r) {
    T[root].l = l;
    T[root].r = r;
    T[root].root = root;
    T[root].Sum = 0;
    int i;
    for(i = 0; i < TAG_MAX; i++)
        T[root].lazy[i] = 0;

    if(l == r)
        return ;

    int mid = (l + r) >> 1;
    Build(root<<1, l, mid);
    Build(root<<1|1, mid+1, r);
}

void Tree::UpdateBy(Tree* ls, Tree* rs) {
    Sum = ls->Sum + rs->Sum;
}

void Tree::CoverBy(int mode) {
    if(mode == ZERO || mode == ONE) {
        Sum = len() * mode;
        lazy[mode] = 1;
        lazy[mode^1] = lazy[XOR] = 0;
    }else {
        Sum = len() - Sum;
        if(lazy[ONE]) {
            lazy[ONE] = 0;
            lazy[ZERO] = 1;
        }else if(lazy[ZERO]) {
            lazy[ZERO] = 0;
            lazy[ONE] = 1;
        }else
            lazy[XOR] ^= 1;
    }
}

void Tree::TranslateToSon() {
    TranslateTo(&T[root<<1]);
    TranslateTo(&T[root<<1|1]);
    for(int i = 0; i < TAG_MAX; i++)
        lazy[i] = 0;
}

void Tree::TranslateTo(Tree* ts){
    for(int i = 0; i < TAG_MAX; i++) {
        if(lazy[i]) {
            ts->CoverBy(i);
        }
    }
}


void Insert(int root, int l, int r, int mode) {
    if(l > T[root].r || r < T[root].l)
        return ;

    if(mode != XOR && T[root].lazy[mode]) {
        return ;
    }

    if(l <= T[root].l && T[root].r <= r) {
        T[root].CoverBy(mode);
        return ;
    }
    T[root].TranslateToSon();
    Insert(root<<1, l, r, mode);
    Insert(root<<1|1, l, r, mode);

    T[root].UpdateBy(&T[root<<1], &T[root<<1|1]);
}

int Query(int root, int pos) {
    if(pos > T[root].r || pos < T[root].l)
        return 0;
    if(pos <= T[root].l && T[root].r <= pos) {
        return T[root].Sum;
    }
    T[root].TranslateToSon();
    return Query(root<<1, pos) + Query(root<<1|1, pos);
}

int main() {
    char str[2][100];
    int size = 0;
    int i, j;

    while(scanf("%s %s", str[0], str[1]) != EOF) {
        int len = strlen(str[1]);
        int a[2] = {0, 0}, top = 0;
        for(i = 1; str[1][i]; i++) {
            if(str[1][i] >= '0' && str[1][i] <= '9') {
                a[top] = a[top] * 10 + (str[1][i] - '0');
            }else if(str[1][i] == ',') {
                top++;
            }
        }
        a[0] *= 2; a[1] *= 2;
        if(str[1][0] == '(') a[0] ++;
        if(str[1][len-1] == ')') a[1]--;

        I[size++] = Interval(find(str[0][0]), a[0], a[1]);
    }
    Build(1, 0, maxn);

    for(i = 0; i < size; i++) {
        if(I[i].operands == 0) {
            // 集合并
            Insert(1, I[i].left, I[i].right, 1);
        }else if(I[i].operands == 1) {
            // 集合交
            Insert(1, 0, I[i].left - 1, 0);
            Insert(1, I[i].right+1, maxn, 0);
        }else if(I[i].operands == 2) {
            // 集合差
            Insert(1, I[i].left, I[i].right, 0);
        }else if(I[i].operands == 3) {
            // 集合逆差
            Insert(1, 0, I[i].left - 1, 0);
            Insert(1, I[i].right+1, maxn, 0);
            Insert(1, I[i].left, I[i].right, 2);
        }else if(I[i].operands == 4) {
            // 集合的对称集
            Insert(1, I[i].left, I[i].right, 2);
        }
    }
    int Min = INT_MAX;
    size = 0;

    for(i = 0; i <= maxn; i++) {
        v[i] = Query(1, i);
    }

    for(i = 0; i <= maxn; i++) {
        if(v[i]) {
            for(j = i + 1; j <= maxn; j++) {
                if(!v[j])
                    break;
            }
            I[size++] = Interval(0, i, j-1);
            i = j;
        }
    }

    if(size == 0) {
        printf("empty set\n");
    }else {
        for(i = 0; i < size; i++) {
            if(i)
                printf(" ");
            printf("%c%d,%d%c", I[i].left&1?'(':'[', I[i].left/2, (I[i].right+1)/2, I[i].right&1?')':']');
        }
        puts("");
    }
    return 0;
}

/**//*
U (1,65535)
D (100,1000]

U (0,65535)
D (10,65535)
D [10,10]
U (65525,65535]
U [0,0]
*/
