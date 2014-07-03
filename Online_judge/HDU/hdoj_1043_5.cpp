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
    int maze[3][3];
    int h,g;
    int x,y;
    int Hash;
    bool operator<(const Node n1)const{
        return h!=n1.h?h>n1.h:g>n1.g;
    }
    bool check(){
        if(x>=0&&x<3&&y>=0&&y<3)
            return true;
        return false;
    }
}s,u,v,tt;
int HASH[9]={1,1,2,6,24,120,720,5040,40320};
int destination=322560;
int vis[400000],pre[400000];
int way[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void debug(Node tmp){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            printf("%d ",tmp.maze[i][j]);
        printf("\n");
    }
    printf("%d %d\n%d %d\n",tmp.x,tmp.y,tmp.g,tmp.h);
    printf("hash=%d\n",tmp.Hash);
}
int get_hash(Node tmp){
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
bool isok(Node tmp){
    int a[9],k=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            a[k++]=tmp.maze[i][j];
    int sum=0;
    for(int i=0;i<9;i++)
        for(int j=i+1;j<9;j++)
            if(a[j]&&a[i]&&a[i]>a[j])
                sum++;
    return !(sum&1);
}
int get_h(Node tmp){
    int ans=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(tmp.maze[i][j])
                ans+=abs(i-(tmp.maze[i][j]-1)/3)+abs(j-(tmp.maze[i][j]-1)%3);
    return ans;
}
void astar(){
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
                swap(v.maze[v.x][v.y],v.maze[u.x][u.y]);
                v.Hash=get_hash(v);            
                if(vis[v.Hash]==-1){
                    vis[v.Hash]=i;
                    v.g++;;
                    pre[v.Hash]=u.Hash;
                    v.h=get_h(v);
                    que.push(v);
                    /*debug(v);
                    system("pause");*/
                }
                if(v.Hash==destination){
        //            debug(v);
                    return ;
                }
            }
        }
    }
}
void print(){
    string ans;
    ans.clear();
    int nxt=destination;
    while(pre[nxt]!=-1){
        switch(vis[nxt]){
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
    tt.maze[0][0]=1;
    tt.maze[0][1]=2;
    tt.maze[0][2]=3;
    tt.maze[1][0]=4;
    tt.maze[1][1]=5;
    tt.maze[1][2]=6;
    tt.maze[2][0]=7;
    tt.maze[2][1]=8;
    tt.maze[2][2]=0;
//    cout<<get_hash(tt)<<endl;
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
        if(!isok(s)){
            printf("unsolvable\n");
            continue;
        }
        s.Hash=get_hash(s);
        if(s.Hash==destination){
            puts("");
            continue;
        }
        vis[s.Hash]=-2;
        s.g=0;s.h=get_h(s);
    //    debug(s);
        astar();
        print();
    }
    return 0;
}