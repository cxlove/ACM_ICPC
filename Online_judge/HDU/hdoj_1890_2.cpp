#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define maxN 100010
int look[maxN];
int n;
struct splaytree{
    int f[maxN], ch[maxN][2], flag[maxN], size[maxN];
    int top, root;
    inline void zig(int x){
        int y=f[x], z=f[y];
        ch[y][1]=ch[x][0]; f[ch[x][0]]=y;
        ch[x][0]=y; f[y]=x;
        f[x]=z;
        if(z) ch[z][ch[z][1]==y]=x;
        push_up(y);
    }
    inline void zag(int x){
        int y=f[x], z=f[y];
        ch[y][0]=ch[x][1]; f[ch[x][1]]=y;
        ch[x][1]=y; f[y]=x;
        f[x]=z;
        if(z) ch[z][ch[z][1]==y]=x;
        push_up(y);
    }
    inline void zigzig(int x){
        int y=f[x], z=f[y], fz=f[z];
        ch[z][1]=ch[y][0]; f[ch[y][0]]=z;
        ch[y][1]=ch[x][0]; f[ch[x][0]]=y;
        f[z]=y; ch[y][0]=z;
        f[y]=x; ch[x][0]=y;
        f[x]=fz;
        if(fz) ch[fz][ch[fz][1]==z]=x;
        push_up(z); push_up(y);
    }
    inline void zagzag(int x){
        int y=f[x], z=f[y], fz=f[z];
        ch[z][0]=ch[y][1]; f[ch[y][1]]=z;
        ch[y][0]=ch[x][1]; f[ch[x][1]]=y;
        f[z]=y; ch[y][1]=z;
        f[y]=x; ch[x][1]=y;
        f[x]=fz;
        if(fz) ch[fz][ch[fz][1]==z]=x;
        push_up(z); push_up(y);
    }
    inline void zigzag(int x){
        int y=f[x], z=f[y], fz=f[z];
        ch[y][1]=ch[x][0]; f[ch[x][0]]=y;
        ch[z][0]=ch[x][1]; f[ch[x][1]]=z;
        f[y]=f[z]=x;
        ch[x][0]=y; ch[x][1]=z;
        f[x]=fz;
        if(fz) ch[fz][ch[fz][1]==z]=x;
        push_up(z); push_up(y);
    }
    inline void zagzig(int x){
        int y=f[x], z=f[y], fz=f[z];
        ch[y][0]=ch[x][1]; f[ch[x][1]]=y;
        ch[z][1]=ch[x][0]; f[ch[x][0]]=z;
        f[y]=f[z]=x;
        ch[x][1]=y; ch[x][0]=z;
        f[x]=fz;
        if(fz) ch[fz][ch[fz][1]==z]=x;
        push_up(z); push_up(y);
    }
    void splay(int x, int goal){
        int y, z;
        push_down(x);
        while(f[x]!=goal){
            if(f[f[x]]==goal){
                y=f[x]; push_down(y); push_down(x);
                if(ch[y][1]==x) zig(x);
                else zag(x);
            }
            else{
                y=f[x]; z=f[y];
                push_down(z); push_down(y); push_down(x);
                if(ch[z][1]==y){
                    if(ch[y][1]==x) zigzig(x);
                    else zagzig(x);
                }
                else{
                    if(ch[y][0]==x) zagzag(x);
                    else zigzag(x);
                }
            }
        }
        push_up(x);
        if(f[x]==0) root=x;
    }
    inline void newnode(int &x){
        x=++top;
        ch[x][0]=ch[x][1]=f[x]=flag[x]=0;
        size[x]=1;
    }
    inline int findmax(int x){
        push_down(x);
        while(ch[x][1]){
            x=ch[x][1];
            push_down(x);
        }
        return x;
    }
    inline void push_up(int x){
        size[x]=1+size[ch[x][0]]+size[ch[x][1]];
    }
    inline void push_down(int x){
        if(flag[x]){
            int temp=ch[x][0];
            ch[x][0]=ch[x][1];
            ch[x][1]=temp;
            flag[ch[x][0]]^=1;
            flag[ch[x][1]]^=1;
            flag[x]=0;
        }
    }
    inline void erase(){ // erase the root
        if(ch[root][0]==0){
            root=ch[root][1];
            f[root]=0;
        }
        else{
            int m=findmax(ch[root][0]);
            splay(m, root);
            ch[m][1]=ch[root][1];
            f[ch[root][1]]=m;
            root=m;
            f[root]=0;
            push_up(root);
        }
    }
    void maketree(int &x, int l, int r, int father){
        if(l>r) return ;
        int mid=(l+r)>>1;
        newnode(x);
        look[mid]=x;
        maketree(ch[x][0], l, mid-1, x);
        maketree(ch[x][1], mid+1, r, x);
        f[x]=father;
        push_up(x);
    }
    void init(int n){
        top=0;
        ch[0][0]=ch[0][1]=f[0]=size[0]=flag[0]=0;
        maketree(root, 0, n-1, 0);
    }
    void travel(int x){
        if(ch[x][0]) travel(ch[x][0]);
        printf("%d ", x);
        if(ch[x][1]) travel(ch[x][1]);
    }
    inline int query(int k){
        int x=look[k], ans;
        splay(x, 0);
        ans=size[ch[x][0]]+1;
        flag[ch[x][0]]^=1;
        erase();
        return ans;
    }
}tree;
struct node{
    int value, pos;
    bool friend operator < (const node &a, const node &b){
        if(a.value == b.value) return a.pos<b.pos;
        return a.value < b.value;
    }
}p[maxN];
int main(){
//    freopen("1.txt", "r", stdin);
    while(scanf("%d", &n)!=EOF && n!=0){
        for(int i=0; i<n; i++){
            scanf("%d", &p[i].value);
            p[i].pos=i;
        }
        sort(p, p+n);
        tree.init(n);
        for(int i=0; i<n-1; i++){
            printf("%d ", tree.query(p[i].pos)+i);
        }
        printf("%d\n", tree.query(p[n-1].pos)+n-1);
    }
    return 0;
}