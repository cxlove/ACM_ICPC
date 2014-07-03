#include<iostream>  
#include<cstdio>  
#include<map>  
#include<cstring>  
#include<cmath>  
#include<vector>  
#include<queue>  
#include<algorithm>  
#include<set> 
#include<string>
#define inf 1<<30
#define N 100005  
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
struct Point{
	int x,y;
	Point(){}
	Point(int _x,int _y):x(_x),y(_y){}
}p[10],ansp;
int n,tot,best;
char str[10][10];
int vis[10][10],tt;
int way[4][2]={0,1,0,-1,1,0,-1,0};
int pw3[15],dp[60000];
bool check(int x1,int y1,int x2,int y2){
	if(x1>=0&&x2>=0&&x1<n&&x2<n&&str[x1][y1]==str[x2][y2]&&!vis[x1][y1])
		return true;
	return false;
}
void dfs(int i,int j){
	if(vis[i][j]) return;
	tt++;vis[i][j]=1;
	for(int k=0;k<4;k++){
		int ii=i+way[k][0],jj=j+way[k][1];
		if(check(ii,jj,i,j))
			dfs(ii,jj);
	}
}
int get_score(){
	mem(vis,0);
	int c1=0,c2=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			tt=0;
			if(vis[i][j]==0)
				dfs(i,j);
			if(str[i][j]=='0') c1=max(c1,tt);
			else c2=max(c2,tt);
		}
	return c1-c2;
}
void debug(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%c ",str[i][j]);
		puts("");
	}
}
int MinSearch(int,int,int,int);
int MaxSearch(int,int,int,int);
int MaxSearch(int state,int dep,int now,int alpha){
	//棋盘放满，统计一下当前局面
	if(state==0){
	//	debug();
	//	printf("%d\n",get_score());
	//	system("pause");
		return get_score();
	}
	if(dp[now]!=-inf) return dp[now];
	int ans=-inf,st=state;
	//枚举所有的位置
	while(st){
		int k=st&(-st),pos;
		for(pos=0;;pos++)
			if((1<<pos)&k)
				break;
		str[p[pos].x][p[pos].y]='0';
		int tmp=MinSearch(state-k,dep+1,now+pw3[pos],ans);	
		str[p[pos].x][p[pos].y]='.';
		ans=max(tmp,ans);	
		if(tmp>=alpha) return tmp;
		if(dep==0){
			if(ans>best||(ans==best&&(p[pos].x<ansp.x||(p[pos].x==ansp.x&&p[pos].y<ansp.y)))){
				best=ans;
				ansp=p[pos];
			}
		}
		
		st-=k;
	}
	return dp[now]=ans;
}
int MinSearch(int state,int dep,int now,int beta){
	//棋盘放满，统计一下当前局面
	if(state==0) return get_score();
	if(dp[now]!=-inf) return dp[now];
	int ans=inf,st=state;
	//枚举所有的位置
	while(st){
		int k=st&(-st),pos;
		for(pos=0;;pos++)
			if((1<<pos)&k)
				break;
		str[p[pos].x][p[pos].y]='1';
		int tmp=MaxSearch(state-k,dep+1,now+2*pw3[pos],ans);		
		str[p[pos].x][p[pos].y]='.';
		ans=min(tmp,ans);		
		if(ans<=beta) return ans;
		st-=k;
	}
	return dp[now]=ans;
}
int main(){
	pw3[0]=1;
	for(int i=1;i<=10;i++) pw3[i]=pw3[i-1]*3;
	while(scanf("%d",&n)!=EOF&&n){
		int c1=0,c2=0;tot=0;
		for(int i=0;i<n;i++){
			scanf("%s",str[i]);
			for(int j=0;j<n;j++){
				if(str[i][j]=='.') p[tot++]=Point(i,j);
				else if(str[i][j]=='0') c1++;
				else c2++;
			}
		}
		if(c1>c2){
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(str[i][j]=='0') str[i][j]='1';
					else if(str[i][j]=='1')str[i][j]='0';
		}
		best=-inf;
		int ret;
		for(int i=0;i<pw3[tot];i++) dp[i]=-inf;
		ret=MaxSearch((1<<tot)-1,0,0,inf);
		printf("(%d,%d) %d\n",ansp.x,ansp.y,best);
	}
	return 0;
}


