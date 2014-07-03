#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
struct Node{
    int num,step;
}s,e,u,v;
int n,m,k;
bool flag[200005];
int bfs(){
    queue<Node>que;
    que.push(s);
    if(s.num==e.num)
        return 0;
    memset(flag,false,sizeof(flag));
    flag[s.num]=true;
    while(!que.empty()){
        u=que.front();
        que.pop();
        for(int i=0;i<3;i++){
            if(i==0){
                v.num=u.num+1;
                v.step=u.step+1;
                if(v.num<=e.num&&flag[v.num]==false){
                    flag[v.num]=true;
                    if(v.num==e.num)
                        return v.step;
                    que.push(v);
                }
            }
            else if(i==1){
                v.num=u.num-1;
                v.step=u.step+1;
                if(v.num>=0&&flag[v.num]==false){
                    flag[v.num]=true;
                    if(v.num==e.num)
                        return v.step;
                    que.push(v);
                }
            }
            else{
                v.num=u.num*2;
                v.step=u.step+1;
                if(v.num<=2*e.num&&flag[v.num]==false){
                    flag[v.num]=true;
                    if(v.num==e.num)
                        return v.step;
                    que.push(v);
                }
            }
        }
    }
    return -1;
}
int main(){    
    while(scanf("%d%d",&s.num,&e.num)!=EOF){
        printf("%d\n",bfs());
    }
    return 0;
}