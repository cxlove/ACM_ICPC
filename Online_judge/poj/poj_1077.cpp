#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<map>
#include<string>
#define inf 1<<30
#define eps 1e-7
#define LD long double
#define LL long long
#define maxn 1000000005
using namespace std;
struct Node{
	int maze[3][3];   //八数码具体情况 
	int h,g;    //两个估价函数
	int x,y;   //空位的位置
	int Hash;   //HASH值
	bool operator<(const Node n1)const{     //优先队列第一关键字为h,第二关键字为g
		return h!=n1.h?h>n1.h:g>n1.g;
	}
	bool check(){    //判断是否合法
		if(x>=0&&x<3&&y>=0&&y<3)
			return true;
		return false;
	}
}s,u,v,tt;
int HASH[9]={1,1,2,6,24,120,720,5040,40320};   //HASH的权值
int destination=322560;   //目标情况的HASH值
int vis[400000];            //判断状态已遍历，初始为-1，否则为到达这步的转向
int pre[400000];        //路径保存
int way[4][2]={{0,1},{0,-1},{1,0},{-1,0}};   //四个方向
void debug(Node tmp){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			printf("%d ",tmp.maze[i][j]);
		printf("\n");
	}
	printf("%d %d\n%d %d\n",tmp.x,tmp.y,tmp.g,tmp.h);
	printf("hash=%d\n",tmp.Hash);
}
int get_hash(Node tmp){    //获得HASH值
	int a[9],k=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			a[k++]=tmp.maze[i][j];
	int res=0;
	for(int i=0;i<9;i++){
		int k=0;
		for(int j=0;j<i;j++)
			if(a[j]>a[i])
				k++;
		res+=HASH[i]*k;
	}
	return res;
}
bool isok(Node tmp){    //求出逆序对，判断是否有解
	int a[9],k=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			a[k++]=tmp.maze[i][j];
	int sum=0;
	for(int i=0;i<9;i++)
		for(int j=i+1;j<9;j++)
			if(a[j]&&a[i]&&a[i]>a[j])
				sum++;
	return !(sum&1);    //由于目标解为偶数，所以状态的逆序数为偶数才可行
}
int get_h(Node tmp){   //获得估价函数H
	int ans=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(tmp.maze[i][j])
				ans+=abs(i-(tmp.maze[i][j]-1)/3)+abs(j-(tmp.maze[i][j]-1)%3);
	return ans;
}
void astar(){    //搜索
	priority_queue<Node>que;
	que.push(s);
	while(!que.empty()){
		u=que.top();
		que.pop();
		for(int i=0;i<4;i++){
			v=u;
			v.x+=way[i][0];
			v.y+=way[i][1];
			if(v.check()){
				swap(v.maze[v.x][v.y],v.maze[u.x][u.y]);   //将空位和相邻位交换
				v.Hash=get_hash(v);			    //得到HASH值
				if(vis[v.Hash]==-1&&isok(v)){   //判断是否已遍历且是否可行，后者可以不要
					vis[v.Hash]=i;           //保存方向
					v.g++;;                  //已花代价+1
					pre[v.Hash]=u.Hash;     //保存路径
					v.h=get_h(v);           //得到新的估价函数H
					que.push(v);     //入队
				}
				if(v.Hash==destination)
					return ;
			}
		}
	}
}
void print(){
	string ans;
	ans.clear();
	int nxt=destination;
	while(pre[nxt]!=-1){  //从终点往起点找路径
		switch(vis[nxt]){   //四个方向对应
		case 0:ans+='r';break;
		case 1:ans+='l';break;
    	case 2:ans+='d';break;
    	case 3:ans+='u';break;
    	}
		nxt=pre[nxt];	
	}
	for(int i=ans.size()-1;i>=0;i--)
		putchar(ans[i]);
	puts("");
}
int main(){
	char str[100];
	while(gets(str)!=NULL){
		int k=0;
		memset(vis,-1,sizeof(vis));
		memset(pre,-1,sizeof(pre));
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++){
				if((str[k]<='9'&&str[k]>='0')||str[k]=='x'){
					if(str[k]=='x'){
						s.maze[i][j]=0;
						s.x=i;
						s.y=j;
					}
					else
						s.maze[i][j]=str[k]-'0';
				}
				else
					j--;
				k++;
			}
		if(!isok(s)){   //起始状态不可行
			printf("unsolvable\n");
			continue;
		}
		s.Hash=get_hash(s);
		if(s.Hash==destination){   //起始状态为目标状态
			puts("");
			continue;
		}
		vis[s.Hash]=-2;
		s.g=0;s.h=get_h(s);
		astar();
		print();
	}
	return 0;
}