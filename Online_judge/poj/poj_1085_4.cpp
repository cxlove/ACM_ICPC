#include<iostream>  
#include<cstdio>  
#include<map>  
#include<cstring>  
#include<cmath>  
#include<vector>  
#include<queue>  
#include<algorithm>  
#include<set>  
#define inf (1ull<<63)-1  
#define N 50005  
#define maxn 100005  
#define Min(a,b) ((a)<(b)?(a):(b))  
#define Max(a,b) ((a)>(b)?(a):(b))  
#define pb(a) push_back(a)  
#define mem(a,b) memset(a,b,sizeof(a))  
#define eps 1e-9  
#define zero(a) fabs(a)<eps  
#define LL long long  
#define ULL unsigned long long  
#define lson (step<<1)  
#define rson (step<<1|1)  
#define MOD 1000000007  
#define mp(a,b) make_pair(a,b)  
using namespace std;  
//10个顶点之间的连线编号
int mat[11][11]={
{0,0,0,0,0,0,0,0,0,0,0},  
{0,0,0,1,0,0,0,0,0,0,0},  
{0,0,0,2,3,4,0,0,0,0,0},  
{0,1,2,0,0,5,6,0,0,0,0},  
{0,0,3,0,0,7,0,9,10,0,0},  
{0,0,4,5,7,0,8,0,11,12,0},  
{0,0,0,6,0,8,0,0,0,13,14},  
{0,0,0,0,9,0,0,0,15,0,0},  
{0,0,0,0,10,11,0,15,0,16,0},  
{0,0,0,0,0,12,13,0,16,0,17},  
{0,0,0,0,0,0,0,14,0,17,0}  
};  
//9个三角形组成的边状态压缩一下
int tri[9]={7,152,52,352,34304,3200,71680,12544,155648};  
int STATUS=(1<<18)-1;
int Get_Status(int old,int seg,int &cnt){
	int now=old|seg;
	for(int i=0;i<9;i++){
		//之前不包含这个三角形，现在包含了
		if((old&tri[i])!=tri[i]&&(now&tri[i])==tri[i])
			cnt++;
	}
	return now;
}
int MaxSearch(int state,int alpha,int ca,int cb);
int MinSearch(int state,int beta,int ca,int cb){
	//出现5个三角形，胜负已分
	if(ca>=5) return 1;
	if(cb>=5) return -1;
	//所有的边都取了,游戏也结束
	if(state==STATUS) return ca>cb?1:-1;
	int ans=1;
	int remain=(~state)&STATUS;  //剩下还有哪些边可以取
	while(remain){
		int seg=remain&(-remain); //枚举
		int ta=ca,tb=cb;
		int now=Get_Status(state,seg,tb),tmp;
		if(tb>cb) tmp=MinSearch(now,beta,ca,tb);
		else tmp=MaxSearch(now,ans,ca,tb);
		if(tmp<ans) ans=tmp;
		if(tmp<=beta) return ans;
		remain-=seg;
	}
	return ans;
}
int MaxSearch(int state,int alpha,int ca,int cb){
	//出现5个三角形，胜负已分
	if(ca>=5) return 1;
	if(cb>=5) return -1;
	//所有的边都取了,游戏也结束
	if(state==STATUS) return ca>cb?1:-1;
	int ans=-1;
	int remain=(~state)&STATUS;  //剩下还有哪些边可以取
	while(remain){
		int seg=remain&(-remain); //枚举
		int ta=ca,tb=cb;
		int now=Get_Status(state,seg,ta),tmp;
		if(ta>ca) tmp=MaxSearch(now,alpha,ta,cb);
		else tmp=MinSearch(now,ans,ta,cb);
		if(tmp>ans) ans=tmp;
		if(tmp>=alpha) return ans;
		remain-=seg;
	}
	return ans;
}
int main(){
	int t,cas=0;
	scanf("%d",&t);
	while(t--){
		int n,u,v;
		scanf("%d",&n);
		//已经走了多少步，当前边的状态
		int cnt=0,state=0;
		//两个人分别有几个三角形
		int ca=0,cb=0;
		while(n--){
			scanf("%d%d",&u,&v);
			int ta=ca,tb=cb;
			state=Get_Status(state,1<<mat[u][v],(cnt&1)?cb:ca);
			//没有新的三角形，
			if(ta==ca&&tb==cb)
				cnt++;
		}
		int ans;
		//cout<<cnt<<" "<<ca<<" "<<cb<<endl;
		if(cnt&1) ans=MinSearch(state,-1,ca,cb);
		else ans=MaxSearch(state,1,ca,cb);
		printf("Game %d: %c wins.\n",++cas,ans==1?'A':'B');
	}
	return 0;
}
