#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<algorithm>
#define N 200005
#define inf 1<<29
#define MOD 100000007
#define LL long long
#define Key_value ch[ch[root][1]][0]
#define _match(a,b) ((a)==(b))
using namespace std;
int n,q,a[N];
int size[N],pre[N],rev[N],val[N],same[N],add[N],m[N];
int ch[N][2],tot1,root,s[N],tot2;
//debug部分copy from hh  
void Treaval(int x) {  
    if(x) {  
        Treaval(ch[x][0]);  
        printf("结点%2d:左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d ,val = %2d  min =%2d \n",x,ch[x][0],ch[x][1],pre[x],size[x],val[x],m[x]);  
        Treaval(ch[x][1]);  
    }  
}  
void debug() {printf("%d\n",root);Treaval(root);}  
//以上Debug  
void Update_Rev(int r){
	if(!r) return;
	swap(ch[r][0],ch[r][1]);
	rev[r]^=1;
}
void Update_Add(int r,int ADD){
	if(!r) return;
	m[r]+=ADD;
	val[r]+=ADD;
	add[r]+=ADD;
}
void NewNode(int &r,int k,int father){
    if(tot2)
        r=s[tot2--];
    else
        r=++tot1;
    ch[r][0]=ch[r][1]=0;
    pre[r]=father;
	val[r]=m[r]=k;
	size[r]=1;
	add[r]=0;
}
void Push_Up(int x){
    int l=ch[x][0],r=ch[x][1];
    size[x]=size[l]+size[r]+1;
    m[x]=min(min(m[l],m[r]),val[x]);
}
void Push_Down(int x){
	int l=ch[x][0],r=ch[x][1];
    if(add[x]){
       Update_Add(l,add[x]);
	   Update_Add(r,add[x]);
	   add[x]=0;
    }
	if(rev[x]){
		Update_Rev(l);
		Update_Rev(r);
		rev[x]=0;
	}
}
void Bulid(int &r,int L,int R,int father){
    if(L>R)
        return ;
    int mid=(L+R)/2;
    NewNode(r,a[mid],father);
    Bulid(ch[r][0],L,mid-1,r);
    Bulid(ch[r][1],mid+1,R,r);
    Push_Up(r);
}
void Init(){
    tot1=tot2=root=0;
    ch[root][0]=ch[root][1]=pre[root]=rev[root]=size[root]=add[root]=0;
	m[root]=inf;
    NewNode(root,inf,0);
    NewNode(ch[root][1],inf,root);
    Push_Up(root);
    Bulid(Key_value,1,n,ch[root][1]);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
void Rotate(int x,int kind){  
    int y=pre[x];    
    Push_Down(y);
    Push_Down(x);
    ch[y][!kind]=ch[x][kind];   
    pre[ch[x][kind]]=y;  
    if(pre[y])  
        ch[pre[y]][ch[pre[y]][1]==y]=x;  
    pre[x]=pre[y];  
    ch[x][kind]=y;  
    pre[y]=x;  
    Push_Up(y);  
}   
void Splay(int r,int goal){  
    Push_Down(r);
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
void RotateTo(int k,int goal) {  
    int r=root;  
    Push_Down(r);  
    while(size[ch[r][0]]!=k){  
        if(k<size[ch[r][0]]){  
            r=ch[r][0];  
        } else {  
            k-=(size[ch[r][0]]+1);  
            r=ch[r][1];  
        }  
        Push_Down(r);  
    }  
    Splay(r,goal);  
}  
int Get_Kth(int r,int k){
    Push_Down(r);
    int t=size[ch[r][0]]+1;
    if(t==k)
        return r;
    if(t>k)
        return Get_Kth(ch[r][0],k);
    else
        return Get_Kth(ch[r][1],k-t);
}
int Get_Min(int r){
    Push_Down(r);
    while(ch[r][0]){
        r=ch[r][0];
        Push_Down(r);
    }
    return r;
}
int Get_Max(int r){
    Push_Down(r);
    while(ch[r][1]){
        r=ch[r][1];
        Push_Down(r);
    }
    return r;
}
void Reversal(int l,int r){
    int x=Get_Kth(root,l);
	Splay(x,0);
	int y=Get_Kth(root,r+2);
	Splay(y,root);
    Update_Rev(Key_value);
}
void Cut(int a,int b,int c){
    int x=Get_Kth(root,a);
    int y=Get_Kth(root,b+2);    
    Splay(x,0);
    Splay(y,root);
    int tmp=Key_value;
    Key_value=0;
    Push_Up(ch[root][1]);
    Push_Up(root);
    int z=Get_Kth(root,c+1);
    Splay(z,0);
    int m=Get_Min(ch[root][1]);
    Splay(m,root);
    Key_value=tmp;
    pre[Key_value]=ch[root][1];
    Push_Up(ch[root][1]);
    Push_Up(root);
}
int cnt;
void InOrder(int r){
    if(r==0)
        return;
    Push_Down(r);
    InOrder(ch[r][0]);
  if(cnt>=1)
      printf("%d  ",val[r]);
    cnt++;
    InOrder(ch[r][1]);
}
void Insert(int pos,int k){
    int x=Get_Kth(root,pos);
    Splay(x,0);
    int y=Get_Min(ch[root][1]);
    Splay(y,root);
	NewNode(Key_value,k,ch[root][1]);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
void erase(int r){
    if(!r) return;
    s[++tot2]=r;
    erase(ch[r][0]);
    erase(ch[r][1]);
}
void Delete(int l){
    int x=Get_Kth(root,l);
    Splay(x,0); 
    int y=Get_Kth(root,l+2);
    Splay(y,root);
    erase(Key_value);
    pre[Key_value]=0;
    Key_value=0;
    Push_Up(ch[root][1]);
    Push_Up(root);
}
void ADD(int l,int r,int k){
	int x=Get_Kth(root,l);
	Splay(x,0);
	int y=Get_Kth(root,r+2);
	Splay(y,root);
	Update_Add(Key_value,k);
	Push_Up(ch[root][1]);
	Push_Up(root);
}
int Get_Answer(int l,int r){
	int x=Get_Kth(root,l);
	Splay(x,0);
	int y=Get_Kth(root,r+2);
	Splay(y,root);
	return m[Key_value];
}
void Revolve(int a,int b,int t){
	if(!t)
		return;
	int c=b-t;
	int x=Get_Kth(root,a);
	Splay(x,0);
	x=Get_Kth(root,c+2);
	Splay(x,root);
	int tmp=Key_value;
	Key_value=0;
	Push_Up(ch[root][1]);
	Push_Up(root);
	Splay(Get_Kth(root,b-c+a),0);
	Splay(Get_Kth(root,b-c+a+1),root);
	Key_value=tmp;
	pre[Key_value]=ch[root][1];
	Push_Up(ch[root][1]);
	Push_Up(root);
}
int main(){
    while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&q);
		Init();
		char str[10];
		int l,r,k;
		while(q--){
			scanf("%s",str);
			if(!strcmp(str,"ADD")){
				scanf("%d%d%d",&l,&r,&k);
				ADD(l,r,k);
			}
			else if(!strcmp(str,"REVERSE")){
				scanf("%d%d",&l,&r);
				Reversal(l,r);
			}
			else if(!strcmp(str,"REVOLVE")){
				scanf("%d%d%d",&l,&r,&k);
				Revolve(l,r,(k%(r-l+1)+(r-l+1))%(r-l+1));
			}
			else if(!strcmp(str,"INSERT")){
				scanf("%d%d",&l,&k);
				Insert(l+1,k);
			}
			else if(!strcmp(str,"DELETE")){
				scanf("%d",&l);
				Delete(l);
			}
			else{
				scanf("%d%d",&l,&r);
				printf("%d\n",Get_Answer(l,r));
			}
		}
	}
	return 0;
}
