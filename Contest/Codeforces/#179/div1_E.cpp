#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#define LL long long
#define db puts("BEGIN");
#define de puts("END");
#define inf 2000000000LL
#define Key_value ch[ch[root][1]][0]  
using namespace std;
const int N=100015;
set<int>s;
int n,q,a[N],b[N];
struct Splay_tree{  
    LL sum[N],ans[N];
    int size[N],pre[N],val[N],tot;  
    int ch[N][2],tot1,root,s[N],tot2;    
    //debug部分copy from hh  
    void Treaval(int x) {  
        if(x) {  
            Treaval(ch[x][0]);  
            printf("%2d ",val[x]);  
            Treaval(ch[x][1]);  
        }  
    }  
    void debug() {Treaval(root);puts("");}  
    //以上Debug  
    inline void NewNode(int &r,int k,int father){  
        if(tot2) r=s[--tot2];
        else r=++tot1;  
        ch[r][0]=ch[r][1]=0; 
        sum[r]=k;
        ans[r]=0LL;  
        pre[r]=father;  
        size[r]=1;  
        val[r]=k;  
    }  
    inline void Push_Up(int x){  
        if(x==0) return ;  
        int l=ch[x][0],r=ch[x][1];  
        size[x]=size[l]+size[r]+1;  
        sum[x]=sum[l]+sum[r]+val[x];
        ans[x]=(LL)ans[l]+ans[r]-(LL)sum[l]*size[r]+(LL)sum[r]*size[l]+(LL)val[x]*(size[l]-size[r])-sum[l]+sum[r];
    }  
    inline void Bulid(int &r,int L,int R,int father){  
        if(L>R)  
            return ;  
        int mid=(L+R)/2;  
        NewNode(r,a[mid],father);  
        Bulid(ch[r][0],L,mid-1,r);  
        Bulid(ch[r][1],mid+1,R,r);  
        Push_Up(r);  
    }  
    inline void Init(){  
        tot=tot1=tot2=root=0;  
        NewNode(root,-inf,0);  
        NewNode(ch[root][1],inf,root);  
        Bulid(Key_value,1,n,ch[root][1]);  
        Push_Up(ch[root][1]);  
        Push_Up(root);  
    }  
    inline void Rotate(int x,int kind){  
        int y=pre[x];  
        ch[y][!kind]=ch[x][kind];  
        pre[ch[x][kind]]=y;  
        if(pre[y])  
            ch[pre[y]][ch[pre[y]][1]==y]=x;  
        pre[x]=pre[y];  
        ch[x][kind]=y;  
        pre[y]=x;  
        Push_Up(y);  
    }  
    inline void Splay(int r,int goal){  
        while(pre[r]!=goal){  
            if(pre[pre[r]]==goal)  
                Rotate(r,ch[pre[r]][0]==r);  
            else{  
                int y=pre[r];  
                int kind=(ch[pre[y]][0]==y);  
                if(ch[y][kind]==r){  
                    Rotate(r,!kind);  
                    Rotate(r,kind);  
                }  
                else{  
                    Rotate(y,kind);  
                    Rotate(r,kind);  
                }  
            }  
        }  
        Push_Up(r);  
        if(goal==0) root=r;  
    }  
    inline void RotateTo(int k, int goal) {  
        int x=root;  
        while(k!=size[ch[x][0]]+1){  
            if (k<=size[ch[x][0]]){  
                x=ch[x][0];  
            }else{  
                k-=(size[ch[x][0]]+1);  
                x=ch[x][1];  
            }  
        }  
        Splay(x,goal);  
    }  
    inline int Get_Kth(int r,int k){  
        int t=size[ch[r][0]]+1;  
        if(t==k) return r;  
        if(t>k) return Get_Kth(ch[r][0],k);  
        else return Get_Kth(ch[r][1],k-t);  
    }
    inline int find(int r,int num){
        if(val[r]==num) return r;
        else if(val[r]<num) return find(ch[r][1],num);
        else return find(ch[r][0],num);
    } 
    inline int Insert(int pos,int k){  
        tot++; 
        RotateTo(pos,0);  
        RotateTo(pos+1,root);  
        NewNode(Key_value,k,ch[root][1]);  
        Push_Up(ch[root][1]);  
        Push_Up(root);  
        return Key_value;  
    }  
    inline void Delete(int r){  
        tot--;   
        Splay(r,0);  
        int pos=size[ch[r][0]]; 
        RotateTo(pos,0);  
        RotateTo(pos+2,root);  
        s[tot2++]=Key_value;  
        Key_value=0;  
        Push_Up(ch[root][1]);  
        Push_Up(root);  
    } 
    inline void add(int r,int num,int pos){
        if(num<=val[r]){
            if(ch[r][0]==0)
                Insert(pos,num);
            else
                add(ch[r][0],num,pos);
        }
        else{
            if(ch[r][1]==0)
                Insert(pos+1+size[ch[r][0]],num);
            else 
                add(ch[r][1],num,pos+size[ch[r][0]]+1);
        }
    }
    inline void InOrder(int r){  
        if(r==0)  
            return;  
        InOrder(ch[r][0]);  
        printf("%d ",val[r]);  
        InOrder(ch[r][1]);  
    }  
    inline void Print(){  
        RotateTo(1,0);  
        RotateTo(tot+2,root);  
        InOrder(Key_value);  
        printf("\n");  
    }  
}splay;  
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
        s.insert(a[i]);
    }
    s.insert(inf);s.insert(-inf);
    sort(a+1,a+1+n);
    splay.Init();
    scanf("%d",&q);
    set<int>::iterator it;
    while(q--){
        int k,l,r;
        scanf("%d%d%d",&k,&l,&r);
        if(k==1){
            it=s.lower_bound(b[l]);
            splay.Delete(splay.find(splay.root,*it));
            s.erase(it);
            b[l]+=r;
            s.insert(b[l]);
            splay.add(splay.root,b[l],0);
        }
        else{
            it=s.lower_bound(l);it--;
            splay.Splay(splay.find(splay.root,*it),0);
            it=s.upper_bound(r);
            splay.Splay(splay.find(splay.root,*it),splay.root);  
            printf("%I64d\n",splay.ans[splay.ch[splay.ch[splay.root][1]][0]]);
        }
    }
    return 0;
}