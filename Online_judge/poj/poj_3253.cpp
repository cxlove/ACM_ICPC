#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<queue>
#define LL long long
using namespace std;
struct Node{
	int l;
	bool operator <(const Node t) const{
		return l>t.l;
	}
}temp,temp2;
priority_queue<Node>que;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		while(!que.empty())
			que.pop();
		for(int i=1;i<=n;i++){
			scanf("%d",&temp.l);
			que.push(temp);
		}
		LL sum=0;
		while(que.size()!=1){
			temp=que.top();que.pop();
			temp2=que.top();que.pop();
			temp.l+=temp2.l;
			sum+=temp.l;
			que.push(temp);
		}
		printf("%I64d\n",sum);
	}
	return 0;
}

	