#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 100015
#define inf 1<<29
#define LL long long
#define Key_value ch[ch[root][1]][0]
using namespace std;
int n,q,p[N],cnt,s[2*N],e[2*N],ope[N];
int node[2*N];
char str[N][10];
int root,tot,size[2*N],key[2*N],pre[2*N],ch[2*N][2],num[2*N];
void Treaval(int x) {  
    if(x) {  
        Treaval(ch[x][0]);  
        printf("结点%2d:左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d ,key = %2d   num= %2d \n",x,ch[x][0],ch[x][1],pre[x],size[x],key[x],num[x]);  
        Treaval(ch[x][1]);  
    }  
}  
void debug() {printf("%d\n",root);Treaval(root);}   
void Push_Up(int r){
    size[r]=size[ch[r][0]]+size[ch[r][1]]+num[r];
}
void NewNode(int &r,int father,int k){
    r=++tot;
    pre[r]=father;
    size[r]=e[k]-s[k]+1;
    num[r]=e[k]-s[k]+1;
    key[r]=k;
    node[k]=r;
    ch[r][0]=ch[r][1]=0;
}
void Bulid(int &x,int l,int r,int father){
    if(l>r)
        return;
    int mid=(l+r)/2;
    NewNode(x,father,mid);
    Bulid(ch[x][0],l,mid-1,x);
    Bulid(ch[x][1],mid+1,r,x);
    Push_Up(x);
}
void Rotate(int x,int kind){  
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
/*void Splay(int r,int goal){  
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
*/
void leftrotate(int x)
{
    int y = ch[x][1], p = pre[x];
    ch[x][1] = ch[y][0];
    if(ch[x][1])
        pre[ch[x][1]] = x;
    ch[y][0] = x;
    pre[x] = y;
    pre[y] = p;
    if(p == 0)
        root = y;
    else
        ch[p][1] == x ? ch[p][1] = y : ch[p][0] = y;
    Push_Up(x);
}
void rightrotate(int x)
{
    int y = ch[x][0], p = pre[x];
    ch[x][0] = ch[y][1];
    if(ch[x][0])
        pre[ch[x][0]] = x;
    ch[y][1] = x;
    pre[x] = y;
    pre[y] = p;
    if(p == 0)
       root= y;
    else
        ch[p][1] == x ? ch[p][1] = y : ch[p][0] = y;
    Push_Up(x);
}
void Splay(int x, int goal)
{
    int y, z;
    for(;;)
    {
        if((y = pre[x]) == goal)
            break;
        if((z = pre[y]) == goal)
            ch[y][1] == x ? leftrotate(y) : rightrotate(y);
        else
        {
            if(ch[z][1] == y)
            {
                if(ch[y][1] == x)
                    leftrotate(z), leftrotate(y);
                else
                    rightrotate(y), leftrotate(z);
            }
            else
            {
                if(ch[y][0] == x)
                    rightrotate(z), rightrotate(y);
                else
                    leftrotate(y), rightrotate(z);
            }
        }
    }
    Push_Up(x);
}
int Bin(int x){
    int low=0,high=cnt-1,mid;
    while(low<=high){
        mid=(low+high)>>1;
        if(s[mid]<=x&&e[mid]>=x)
            return mid;
        if(e[mid]<x)
            low=mid+1;
        else
            high=mid-1;
    }
}
int Get_Min(int r){
    Push_Up(r);
    while(ch[r][0]){
        r=ch[r][0];
        Push_Up(r);
    }
    return r;
}
/*
int Delete(int &cur, int p)
{
    int k;
    if(cur == root || ch[cur][1] == 0)
    {
        if(cur == root)
        {
            k = Delete(ch[cur][0], cur);
            ch[k][0] = ch[root][0], ch[k][1] = ch[root][1];
            if(ch[k][0])
                pre[ch[k][0]] = k;
            if(ch[k])
                pre[ch[k][1]] = k;
            root = k;
            pre[root] = 0;
           Push_Up(root);
        }
        else
        {
            k = cur;
            if(ch[k][0])
                pre[ch[k][0]] = p;
            cur = ch[k][0];
        }
        return k;
    }
    else
    {
        k = Delete(ch[cur][1], cur);
        Push_Up(cur);
        return k;
    }
}
*/
void Delete(){
    int k=Get_Min(ch[root][1]);
    Splay(k,root);
    ch[ch[root][1]][0]=ch[root][0];
    root=ch[root][1];
    pre[ch[root][0]]=root;
    pre[root]=0;
    Push_Up(root);
}
void Insert(int &r,int k,int father){
    if(r==0){
        NewNode(r,father,k);
        return;
    }
    Insert(ch[r][0],k,r);
    Push_Up(r);
}
void Top(int x){
    int k=Bin(x);
    int y=node[k];  //找到这个人所在区间的标号
    Splay(y,0);   //旋转至根部
    if(!ch[root][0]||!ch[root][1]){   //左右孩子不完整，直接将孩子拉到根部
        root=ch[root][0]+ch[root][1];
        pre[root]=0;
    }
    else
        Delete();
    Insert(root,k,0);
    Splay(tot,0);
}
int Get_Rank(int x){
    int k=Bin(x);
    int y=node[k];
    Splay(y,0);
    return size[ch[root][0]]+1;
}
int Get_Kth(int r,int k){
    int t=size[ch[r][0]];
    if(k<=t)
        return Get_Kth(ch[r][0],k);
    else if(k<=t+num[r])
        return s[key[r]]+(k-t)-1;
    else
        return Get_Kth(ch[r][1],k-t-num[r]);
}
void slove(){
    for(int i=0;i<q;i++){
        if(str[i][0]=='T')
            Top(ope[i]);
        else if(str[i][0]=='Q')
            printf("%d\n",Get_Rank(ope[i]));
        else
            printf("%d\n",Get_Kth(root,ope[i]));
    }
}
int main(){
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        int total=0;
        p[total++]=0;
        for(int i=0;i<q;i++){
            scanf("%s%d",str[i],&ope[i]);
            if(str[i][0]=='T'||str[i][0]=='Q')
                p[total++]=ope[i];
        }
        p[total++]=n;
        sort(p,p+total);
        cnt=0;
        for(int i=1;i<total;i++)
            if(p[i]!=p[i-1]){
                if(p[i]-p[i-1]>1){   //中间的区间
                    s[cnt]=p[i-1]+1;
                    e[cnt]=p[i]-1;
                    cnt++;
                }
                s[cnt]=p[i];   //端点
                e[cnt]=p[i];
                cnt++;
            }
        root=tot=0;    
        ch[root][0]=ch[root][1]=pre[root]=size[root]=num[root]=key[root]=0;
        Bulid(root,0,cnt-1,0);
        printf("Case %d:\n",++cas);
        slove();
    }
    return 0;
}
