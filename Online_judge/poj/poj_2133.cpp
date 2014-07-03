#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int b,e;
int que[1<<16];
int t[1<<16]={0};
int change(char str[20]){
	int num=0;
	for(int i=0;i<b;i++)
		num=num*2+str[i]-'0';
	return num;
}
void output(int num){
	stack<int> ans;
	for(int i=0;i<b;i++)
		ans.push(num%2),num/=2;
	for(int i=0;i<b;i++)
		printf("%d",ans.top()),ans.pop();
	printf("\n");
}
int differ(int target ,int num){
	int ans=0;
	for(int i=0;i<b;i++){
		ans+=(target%2!=num%2);
		target/=2;
		num/=2;
	}
	return ans;
}
int main(){
	char str[20];	
	scanf("%d%d%s",&b,&e,str);
	int head=0,tail=e;
	int target=change(str);
	for(int i=0;i<e;i++){
		scanf("%s",str);
		que[i]=change(str);
	}
	while(head<tail){
		int temp=que[head++];
		if(temp==target&&t[temp]){
			printf("%d\n",t[temp]);
			output(temp);
			return 0;
		}
		for(int i=0;i<e;i++)
			if(!t[temp^que[i]]){
				t[temp^que[i]]=t[temp]+1;
				que[tail++]=temp^que[i];
			}
	}
//	for(int i=0;i<tail;i++)
//		output(que[i]);
	int bestnum=1<<16,besttime=1<<16,bestdiffer=1<<16;
	for(int i=0;i<tail;i++)
		if(t[que[i]]&&(differ(target,que[i])<bestdiffer||(differ(target,que[i])==bestdiffer&&t[i]<besttime)||(differ(target,que[i])==bestdiffer&&t[i]<besttime&&que[i]<bestnum))){
			bestnum=que[i];
			besttime=t[que[i]];
			bestdiffer=differ(target,bestnum);
		}
	printf("%d\n",besttime);
	output(bestnum);
	return 0;
}





