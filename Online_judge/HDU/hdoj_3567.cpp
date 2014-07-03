#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#define inf 1<<30
#define LL long long
#define maxn 1<<24
using namespace std;
struct Node{
    int a[3][3];
    int val;
    int x,y;
    bool check(){
        if(x>=0&&x<3&&y>=0&&y<3)
            return true;
        return false;
    }
}tmp,u,v;
int fac[3][3]={{1,1,2},{6,24,120},{720,5040,40320}};
int pre[9][370000];
char ope[9][370000];
int way[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
bool flag[370000];
int get_hash(int maze[3][3]){
    int ret=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            int cnt=0;
            for(int a=0;a<i;a++)
                for(int b=0;b<3;b++)
                    if(maze[a][b]>maze[i][j])
                        cnt++;
            for(int b=0;b<j;b++)
                if(maze[i][b]>maze[i][j])
                    cnt++;
            ret+=cnt*fac[i][j];
        }
    return ret;
}
void bfs(int kind){
    queue<Node>que;
    que.push(tmp);
    pre[kind][tmp.val]=-2;
    flag[tmp.val]=true;
    while(!que.empty()){
        u=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            v=u;
            v.x+=way[i][0];
            v.y+=way[i][1];
            if(v.check()){
                swap(v.a[v.x][v.y],v.a[u.x][u.y]);
                v.val=get_hash(v.a);
                if(pre[kind][v.val]==-1){
                    flag[v.val]=true;
                    pre[kind][v.val]=u.val;
                    ope[kind][v.val]=i;
                    que.push(v);
                }
            }
        }
    }
}
void Init(char *str,int kind){
    int k=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            if(str[k]=='X')
                tmp.a[i][j]=0;
            else
                tmp.a[i][j]=str[k]-'0';
            k++;
        }
    tmp.x=kind/3;tmp.y=kind%3;
    tmp.val=get_hash(tmp.a);
    bfs(kind);
}
char ch[5]={"dlru"};
int main(){
    memset(pre,-1,sizeof(pre));
    memset(flag,false,sizeof(flag));
    Init("X12345678",0);
    Init("1X2345678",1);
    Init("12X345678",2);
    Init("123X45678",3);
    Init("1234X5678",4);
    Init("12345X678",5);
    Init("123456X78",6);
    Init("1234567X8",7);
    Init("12345678X",8);
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        char s1[10],s2[10];
        scanf("%s%s",s1,s2);
        int a[3][3],b[3][3],pos,c[9],k=1;
        for(int i=0;i<9;i++){        
            if(s1[i]=='X'){
                c[0]=0;
                pos=i;
            }
            else
                c[s1[i]-'0']=k++;
        }
        for(int i=0;i<9;i++)
            b[i/3][i%3]=(s2[i]=='X'?c[0]:c[s2[i]-'0']);
        int temp=get_hash(b);
        int cnt=0,ans[1000];
        while(pre[pos][temp]!=-2){
            ans[cnt++]=ope[pos][temp];
            temp=pre[pos][temp];
        }
        printf("Case %d: %d\n",++cas,cnt);
        for(int i=cnt-1;i>=0;i--)
            printf("%c",ch[ans[i]]);
        printf("\n");
    }
    return 0;
}