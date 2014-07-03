#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 100005
#define inf 1<<29
#define LL long long
#define Key_value ch[ch[root][1]][0]
using namespace std;
int pre[N],key[N],ch[N][2],root,tot1;  //分别表示父结点，键值，左右孩子(0为左孩子，1为右孩子),根结点，结点数量
int size[N],s[N],tot2,val[N];    //分别表示子树规模，内存池，内存池容量
int add[N];
LL sum[N];        //延迟标记，子树结点和
int n,q;
//debug部分copy from hh
void Treaval(int x) {
	if(x) {
		Treaval(ch[x][0]);
		printf("结点%2d:左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d ,val = %2d , sum = %2d \n",x,ch[x][0],ch[x][1],pre[x],size[x],val[x],sum[x]);
		Treaval(ch[x][1]);
	}
}
void debug() {printf("%d\n",root);Treaval(root);}
//以上Debug
//新建一个结点
void NewNode(int &r,int father,int k){
	if(tot2)
		r=s[--tot2];
	else
		r=++tot1;
	pre[r]=father;
	val[r]=k;
	sum[r]=k;
	add[r]=0;
	size[r]=1;
	ch[r][0]=ch[r][1]=0;  //左右孩子为空
}
//将延迟标记更新到孩子结点
void Push_Down(int r){
	if(add[r]){
		val[r]+=add[r];
		add[ch[r][0]]+=add[r];
		add[ch[r][1]]+=add[r];
		sum[ch[r][0]]+=(LL)add[r]*size[ch[r][0]];
		sum[ch[r][1]]+=(LL)add[r]*size[ch[r][1]];
		add[r]=0;
	}
}
//通过孩子结点更新父结点
void Push_Up(int r){
	size[r]=size[ch[r][0]]+size[ch[r][1]]+1;
	sum[r]=sum[ch[r][0]]+sum[ch[r][1]]+val[r]+add[r];
}
//旋转，kind为1为右旋，kind为0为左旋
void Rotate(int x,int kind){
	int y=pre[x];
	Push_Down(x);
	Push_Down(y);
	//类似SBT，要把其中一个分支先给父节点
	ch[y][!kind]=ch[x][kind]; 
	pre[ch[x][kind]]=y;
	//如果父节点不是根结点，则要和父节点的父节点连接起来
	if(pre[y])
		ch[pre[y]][ch[pre[y]][1]==y]=x;
	pre[x]=pre[y];
	ch[x][kind]=y;
	pre[y]=x;
	Push_Up(y);
}
//Splay调整，将根为r的子树调整为goal
void Splay(int r,int goal){
	Push_Down(r);
	while(pre[r]!=goal){
		//父节点即是目标位置，goal为0表示，父节点就是根结点
		if(pre[pre[r]]==goal)
			Rotate(r,ch[pre[r]][0]==r);
		else{
			int y=pre[r];
			int kind=ch[pre[y]][0]==y;
			//两个方向不同，则先左旋再右旋
			if(ch[y][kind]==r){
				Rotate(r,!kind);
				Rotate(r,kind);
			}
			//两个方向相同，相同方向连续两次
			else{
				Rotate(y,kind);
				Rotate(r,kind);
			}
		}
	}
	Push_Up(r);
	//更新根结点
	if(goal==0) root=r;
}
//把第k位的数转到goal下边
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
int Insert(int k){
	int r=root;
	while(ch[r][key[r]<k])
		r=ch[r][key[r]<k];
	NewNode(ch[r][k>key[r]],r,k);
	//将新插入的结点更新至根结点
	//Push_Up(r);
	Splay(ch[r][k>key[r]],0);
	return 1;
}
//找前驱，即左子树的最右结点
int get_pre(int x){
	int tmp=ch[x][0];
	if(tmp==0)  return inf;
	while(ch[tmp][1])
		tmp=ch[tmp][1];
	return key[x]-key[tmp];
}
//找后继，即右子树的最左结点
int get_next(int x){
	int tmp=ch[x][1];
	if(tmp==0)  return inf;
	while(ch[tmp][0])
		tmp=ch[tmp][0];
	return key[tmp]-key[x];
}
LL Query(int l,int r){
	RotateTo(l-1,0);
	RotateTo(r+1,root);
	return sum[Key_value];
}
void Update(int l,int r){
	int k;
	scanf("%d",&k);
	RotateTo(l-1,0);
	RotateTo(r+1,root);
	add[Key_value]+=k;
	sum[Key_value]+=size[Key_value]*k;
}
int a[N];
void BulidTree(int &x,int l,int r,int father){
	if(l>r)
		return;
	int mid=(l+r)/2;
	NewNode(x,father,a[mid]);
	if(l<mid)
		BulidTree(ch[x][0],l,mid-1,x);
	if(r>mid)
		BulidTree(ch[x][1],mid+1,r,x);
	Push_Up(x);
}
void Init(){
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	ch[0][0]=ch[0][1]=pre[0]=size[0]=0;
	add[0]=sum[0]=0;
	root=tot1=0;
	NewNode(root,0,-1);
	NewNode(ch[root][1],root,-1);
	size[root]=2;
	BulidTree(Key_value,0,n-1,ch[root][1]);
	Push_Up(ch[root][1]);
	Push_Up(root);
}
int main(){
	while(scanf("%d%d",&n,&q)!=EOF){
		Init();
		while(q--){
			char str[10];
			int x,y;
			scanf("%s%d%d",str,&x,&y);
			if(str[0]=='Q')
				printf("%lld\n",Query(x,y));
			else
				Update(x,y);
		}
	}
	return 0;
}