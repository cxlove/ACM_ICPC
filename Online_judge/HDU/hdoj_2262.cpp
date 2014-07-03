#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>
#define LL long long
#define MOD 1000000007
#define eps 1e-6
#define zero(a)  fabs(a)<eps
using namespace std;
int n,m;
int way[4][2]={0,1,0,-1,1,0,-1,0};
char str[20][20];
double a[230][230];
bool flag[20][20];
int ans;
bool bfs(){
    int s,e;
    memset(flag,false,sizeof(flag));
    queue<int>x,y;
    while(!x.empty()) x.pop();
    while(!y.empty()) y.pop();
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(str[i][j]=='$'){
                x.push(i);
                y.push(j);
                s=i;
                e=j;
                flag[i][j]=true;
            }
    while(!x.empty()){
        int ux=x.front(),uy=y.front(),vx,vy;
        x.pop();y.pop();
        for(int i=0;i<4;i++){
            vx=ux+way[i][0];
            vy=uy+way[i][1];
            if(vx>=0&&vx<n&&vy>=0&&vy<m&&str[vx][vy]!='#'&&!flag[vx][vy]){
                flag[vx][vy]=true;
                x.push(vx);y.push(vy);
            }
        }
    }
    return false;
}
void debug(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++)
            printf("%.2f  ",a[i][j]);
        printf("\n");
    }
}
int idx;
bool gauss(int n){
    int i,j;
    for(i=0,j=0;i<n&&j<n;j++){
        int k;

        for(k=i;k<n;k++)
            if(!zero(a[k][j]))
                break;
        if(k<n){
            if(i!=k)
            for(int r=j;r<=n;r++) swap(a[i][r],a[k][r]);
            if(idx==k)  idx=i;
            double tt=1/a[i][j];
            for(int r=j;r<=n;r++)
                a[i][r]*=tt;
            for(int r=0;r<n;r++)
                if(r!=i){
                    for(int t=n;t>=j;t--)
                        a[r][t]-=a[r][j]*a[i][t];
                }
            i++;
        }
    }
    for(int r=i;r<n;r++)
        if(!zero(a[r][n]))
            return false;
    return true;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++)
            scanf("%s",str[i]);
        for(int i=0;i<=n*m;i++)
            for(int j=0;j<=n*m;j++)
                a[i][j]=0;
        bfs();
        int s,e;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                int cnt=0;
                if(str[i][j]=='@'){
                    s=i;
                    e=j;
                }
                if(str[i][j]=='$'){
                    a[i*m+j][n*m]=0;
                    a[i*m+j][i*m+j]=1;
                    continue;
                }
                if(str[i][j]=='#')
                    continue;
                for(int k=0;k<4;k++){
                    int x=i+way[k][0];
                    int y=j+way[k][1];
                    if(x>=0&&x<n&&y>=0&&y<m&&str[x][y]!='#'&&flag[x][y]){
                        a[i*m+j][x*m+y]=1;
                        cnt++;
                    }
                }
                a[i*m+j][n*m]=-1*cnt;
                a[i*m+j][i*m+j]=-1*cnt;
            }
        if(flag[s][e]&&gauss(n*m)){
            for(int i=0;i<n*m;i++)
                if(zero(a[i][s*m+e]-1)){
                    printf("%.6f\n",a[i][n*m]);
                    break;
                }
        }
        else
            puts("-1");
      //  debug(n*m);
    }
    return 0;
}
