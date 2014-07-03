//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<algorithm>
//#define N 1000005
//using namespace std;
//struct SBT{
//	//左子树指针，右子树指针，大小，键值
//	int left,right,size,key;
//	void Init(){
//		left=right=key=0;
//		size=1;
//	}
//}T[N];
//int root,tot; //根的位置以及节点个数
////左旋转处理
//void Left_rot(int &x){  
//	int k=T[x].right;
//	T[x].right=T[k].left;
//	T[k].left=x;
//	T[k].size=T[x].size;
//	T[x].size=T[T[x].left].size+T[T[x].right].size+1;
//	x=k;
//}
////右旋转处理
//void Right_rot(int &x){
//	int k=T[x].left;
//	T[x].left=T[k].right;
//	T[k].left=x;
//	T[k].size=T[x].size;
//	T[x].size=T[T[x].left].size+T[T[x].right].size+1;
//	x=k;
//}
////调整处理
//void Maintain(int &r,bool flag){
//	if(flag){  //更新右子树
//		if(T[T[T[r].right].right].size>T[T[r].left].size)
//			Left_rot(r);
//		else if(T[T[T[r].right].left].size>T[T[r].left].size){
//			Right_rot(T[r].right);
//			Left_rot(r);
//		}
//		else
//			return;
//	} 
//	else{   //更新在左子树
//		if(T[T[T[r].left].left].size>T[T[r].right].size)
//			Right_rot(r);
//		else if(T[T[T[r].left].right].size>T[T[r].right].size){
//			Left_rot(T[r].left);
//			Right_rot(r);
//		}
//		else 
//			return;
//	}
//	//更新子树，然后再更新根，直到平衡为止
//	Maintain(T[r].left,false);
//	Maintain(T[r].right,true);
//	Maintain(r,false);
//	Maintain(r,true);
//}
////插入新节点
//void Insert(int &r,int k){
//	if(r==0){
//		r=++tot;
//		T[r].Init();
//		T[r].key=k;
//	}
//	else{
//		T[r].size++;
//		if(k<T[r].key)
//			Insert(T[r].left,k);
//		else
//			Insert(T[r].right,k);
//		//插入后要调整，保证平衡
//		Maintain(r,k>=T[r].key);
//	}
//}
////删除结点，利用的是前驱替换
//int Remove(int &r,int k){
//	int d_key;
//	if(!r)
//		return 0;
//	T[r].size--;
//	//前者说明就是要删的节点，后两者说明不存在此节点
//	if(T[r].key==k||(T[r].left==0&&k<T[r].key)||(T[r].right==0&&k>T[r].key)){
//		d_key=T[r].key;
//		if(T[r].left&&T[r].right)
//			T[r].key=Remove(T[r].left,k+1);
//		else
//			r=T[r].left+T[r].right;
//	}
//	else Remove(k<T[r].key?T[r].left:T[r].right,k);
//}
////取得最大值，即一直遍历到最右的结点
//int Get_Max(int &r){
//	while(T[r].right)
//		r=T[r].right;
//	return r;
//}
////取得最小值，即一直遍历到最左的结点
//int Get_Min(int &r){
//	while(T[r].left)
//		r=T[r].left;
//	return r;
//}
////获得前驱
//int Get_Pre(int &r,int y,int k){
//	if(r==0) return y;
//	if(k>T[r].key)
//		Get_Pre(T[r].right,r,k);
//	else
//		Get_Pre(T[r].left,y,k);
//}
////获得后继
//int Get_Next(int &r,int y,int k){
//	if(r==0) return y;
//	if(k<T[r].key)
//		Get_Next(T[r].left,r,k);
//	else
//		Get_Next(T[r].right,y,k);
//}
////取得第K小的数，注：暂不能解决有重复数的
//int Get_Kth(int &r,int k){
//	int t=T[T[r].left].size+1;
//	if(t==k) return T[r].key;
//	if(t<k)  return Get_Kth(T[r].right,k-r);
//	else return Get_Kth(T[r].left,k);
//}
////获得结点的名次
//int Get_Rank(int &r,int k){
//	if(k<T[r].key) 
//		return Get_Rank(T[r].left,k);
//	else if(k>T[r].key)
//		return Get_Rank(T[r].right,k)+T[T[r].left].size+1;
//	else
//		return T[T[r].left].size+1;
//}
////排序
//void Inorder(int &r){
//	if(r==0) return;
//	Inorder(T[r].left);
//	printf("%d\n",T[r].key);
//	Inorder(T[r].right);
//}
//int main(){  
//	root=tot=0;  
//	char ch;  
//	int x,tmp;  
//	while(scanf("%c %d",&ch,&x)!=EOF){  
//		switch(ch){  
//		case 'I':  
//			Insert(root,x);  
//			break;  
//		case 'D':  
//			Remove(root,x);  
//			break;  
//		case 'K':  
//			tmp=Get_Kth(root,x);  
//			printf("%d\n",tmp);  
//			break;  
//		case 'C':  
//			printf("%d\n",Get_Rank(root,x));  
//			break;  
//		case 'P':  
//			tmp=Get_Pre(root,0,x);  
//			printf("%d\n",T[tmp].key);  
//			break;  
//		case 'S':  
//			tmp=Get_Next(root,0,x);  
//			printf("%d\n",T[tmp].key);  
//			break;  
//		case 'L':  
//			Inorder(root);  
//			break;  
//		}  
//	}  
//	return 0;  
//}  



#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 1000005
using namespace std;
struct SBT{
	int left,right,size,key,idx;
	void Init(){
		left=right=key=idx=0;
		size=1;
	}
}T[N];
int root,tot;
void Left_rot(int &x){
	int k=T[x].right;
	T[x].right=T[k].left;
	T[k].left=x;
	T[k].size=T[x].size;
	T[x].size=T[T[x].left].size+T[T[x].right].size+1;
	x=k;
}
void Right_rot(int &x){
	int k=T[x].left;
	T[x].left=T[k].right;
	T[k].right=x;
	T[k].size=T[x].size;
	T[x].size=T[T[x].left].size+T[T[x].right].size+1;
	x=k;
}
void Maintain(int &r,bool flag){
	if(flag){
		if(T[T[T[r].right].right].size>T[T[r].left].size)
			Left_rot(r);
		else if(T[T[T[r].right].left].size>T[T[r].left].size){
			Right_rot(T[r].right);
			Left_rot(r);
		}
		else
			return;
	}
	else{
		if(T[T[T[r].left].left].size>T[T[r].right].size)
			Right_rot(r);
		else if(T[T[T[r].left].right].size>T[T[r].right].size){
			Left_rot(T[r].left);
			Right_rot(r);
		}
		else 
			return;
	}
	Maintain(T[r].left,false);
	Maintain(T[r].right,true);
	Maintain(r,false);
	Maintain(r,true);
}
void Insert(int &r,int n,int k){
	if(r==0){
		r=++tot;
		T[r].Init();
		T[r].idx=n;
		T[r].key=k;
	}
	else{
		T[r].size++;
		if(k<T[r].key)
			Insert(T[r].left,n,k);
		else
			Insert(T[r].right,n,k);
		Maintain(r,k>=T[r].key);
	}
}
int Remove(int &r,int k){
	int d_key;
	if(!r)
		return 0;
	T[r].size--;
	if(T[r].key==k||(T[r].left==0&&k<T[r].key)||(T[r].right==0&&k>T[r].key)){
		d_key=T[r].key;
		if(T[r].left&&T[r].right)
			T[r].key=Remove(T[r].left,T[r].key+1);
		else
			r=T[r].left+T[r].right;
	}
	else Remove(k<T[r].key?T[r].left:T[r].right,k);
}
int Get_Max(int r){
	while(T[r].right)
		r=T[r].right;
	return r;
}
int Get_Min(int r){
	while(T[r].left)
		r=T[r].left;
	return r;
}
int Get_Pre(int &r,int y,int k){
	if(r==0) return y;
	if(k>T[r].key)
		Get_Pre(T[r].right,r,k);
	else
		Get_Pre(T[r].left,y,k);
}
int Get_Next(int &r,int y,int k){
	if(r==0) return y;
	if(k<T[r].key)
		Get_Next(T[r].left,r,k);
	else
		Get_Next(T[r].right,y,k);
}
int Get_Kth(int &r,int k){
	int t=T[T[r].left].size+1;
	if(t==k) return T[r].key;
	if(t<k)  return Get_Kth(T[r].right,k-r);
	else return Get_Kth(T[r].left,k);
}
int Get_Rank(int &r,int k){
	if(k<T[r].key) 
		return Get_Rank(T[r].left,k);
	else if(k>T[r].key)
		return Get_Rank(T[r].right,k)+T[T[r].left].size+1;
	else
		return T[T[r].left].size+1;
}
int main(){
	tot=0,root=0;
	int kind,k,p;
	while(scanf("%d",&kind)!=EOF&&kind){
		if(kind==1){
			scanf("%d%d",&k,&p);
			Insert(root,k,p);
		}
		else if(kind==2){
			if(tot==0)
				puts("0");
			else{
				int ans=Get_Max(root);
				printf("%d\n",T[ans].idx);
				Remove(root,T[ans].key);
			}
		}
		else{
			if(tot==0)
				puts("0");
			else{
				int ans=Get_Min(root);
				printf("%d\n",T[ans].idx);
				Remove(root,T[ans].key);
			}
		}
	}
	return 0;
}