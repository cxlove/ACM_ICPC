#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
//4462706    2011-08-21 13:24:53    Accepted    1983    406MS    400K    1727 B    C++    ashione
#define N 10
char map[N][N];
int n,m,t,minstep,step[8]={0,1,0,-1,1,0,-1,0};
bool use[N][N][2];//三维标记状态

typedef struct p{
    int x,y,t,f;
    int pathx[N*N],pathy[N*N]; //pathx,y 表示的是通路路径（如果可以到达的话）
}p;
p s;
void init(){ //s表示为初始点。

    cin>>n>>m>>t;
    minstep=N;
    memset(map,'#',sizeof(map));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>map[i][j];
            if(map[i][j]=='S')
                s.x=i,s.y=j,s.t=0,s.f=0;
        }
    }
}


void bfs(int k){
    if( k > 4 || k>minstep) //BFS 搜索 不可能大于四个围点，也不能大于当年最大值
        return ;
    queue<p> q;
    q.push(s);
    memset(use,false,sizeof(use));
    bool succeed=false;
    use[s.x][s.y][s.f]=true;
    p temp,now;
    while(!q.empty()){ 
        temp=q.front();
        q.pop();
        if(map[temp.x][temp.y] == 'E' && temp.f ){ //若已经搜到，并且拿到宝石。
            succeed = true;
            break;
        }
        for(int i=0;i<8;i+=2){
            now=temp;
            now.x+=step[i];
            now.y+=step[i+1];
            if(map[now.x][now.y] =='J')
                now.f=1;
            if(map[now.x][now.y] =='#' ||now.t>=t || use[now.x][now.y][now.f])
                continue;
            use[now.x][now.y][now.f]=true;
            now.t++;
            now.pathx[now.t]=now.x;
            now.pathy[now.t]=now.y;
            q.push(now);
        }
    }

    if(!succeed){//不成功，即为满足题意。

        minstep = minstep < k?minstep:k;
        return ;

    }

    for(int j=1;j<=temp.t ;j++){//沿着通路判断，
        
        int x=temp.pathx[j],y=temp.pathy[j];
        char tc=map[x][y];
        if(tc == 'E' || tc == 'S')//DFS回溯判断是否通路
            continue;        
        map[x][y]='#';
        bfs(k+1);
        map[x][y]=tc;
    }
    
}

int main(){    

    int T;
    cin>>T;
    while(T--){
        init();
        bfs(0);
        cout<<minstep<<endl;
    }
    return 0;

}