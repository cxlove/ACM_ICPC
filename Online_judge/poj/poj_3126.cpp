#include<iostream>
#include<cstring>
using namespace std;
bool f[10000];
int dig[4]={1,10,100,1000};
void prime(){
	memset(f,false,sizeof(f));
	for(int i=2;i<=100;i++){
		if(f[i])  continue;
		for(int j=2;i*j<=9999;j++)
			f[i*j]=true;
	}
}
int bfs(int a,int b){
	bool flag[10000];
	int que[10000];
	int step[10000];
	memset(flag,false,sizeof(flag));
	flag[a]=true;
	int head=0,tail=0;
	que[tail++]=a;
	step[a]=0;
	while(head<tail){
		a=que[head++];
		if(a==b)
			return step[b];
		for(int i=0;i<4;i++){
			for(int j=0;j<=9;j++){
				int temp=a-((a/dig[i])%10)*dig[i]+dig[i]*j;
				if(!f[temp]&&!flag[temp]&&temp>1000){
					que[tail++]=temp;
					flag[temp]=true;
					step[temp]=step[a]+1;

				}
			}
		}
	}
	return -1;
}
int main(){
	int t;
	cin>>t;
	prime();
	while(t--){
		int a,b;
		cin>>a>>b;
		int sum=bfs(a,b);
		if(sum==-1)
			cout<<"Impossible."<<endl;
		else
			cout<<sum<<endl;
	}
	return 0;
}