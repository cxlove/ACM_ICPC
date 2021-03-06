#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct Node{
    int num,step;
}s,e,u,v;
bool flag[10000];
int Pow(int a){
    return a==0?1:10*Pow(a-1);
}
int change1(int num,int pos,int kind){
    int a[5];
    for(int i=0;i<4;i++){
        a[i]=num%10;
        num/=10;
    }
    a[pos]+=kind;
    if(a[pos]==0)
        a[pos]=9;
    else if(a[pos]==10)
        a[pos]=1;
    int ret=0;
    for(int i=3;i>=0;i--)
        ret=ret*10+a[i];
    return ret;
}
int change2(int num,int pos){
    int a[5];
    for(int i=0;i<4;i++){
        a[i]=num%10;
        num/=10;
    }
    swap(a[pos],a[pos+1]);
    int ret=0;
    for(int i=3;i>=0;i--)
        ret=ret*10+a[i];
    return ret;
}
int bfs(){
    queue<Node>que;
    que.push(s);
    if(s.num==v.num)
        return 0;
    memset(flag,false,sizeof(flag));
    flag[s.num]=true;
    while(!que.empty()){
        u=que.front();
        que.pop();
        for(int i=0;i<7;i++){
            if(i>=4){
                v.num=change2(u.num,i-4);
                if(flag[v.num]==false){
                    flag[v.num]=true;
                    v.step=u.step+1;
                    if(v.num==e.num)
                        return v.step;
                    que.push(v);
                }
                continue;
            }
            for(int j=-1;j<=1;j+=2){
                v.num=change1(u.num,i,j);
                if(flag[v.num]==false){
                    flag[v.num]=true;
                    v.step=u.step+1;
                    if(v.num==e.num)
                        return v.step;
                    que.push(v);
                }
            }
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&s.num,&e.num);
        s.step=0;
        printf("%d\n",bfs());
    }
    return 0;
}
