//矩形切割
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1005;
const int M = 5005;
struct Rec{
    int x1,x2,y1,y2;
    char col[3];
}rec[M];
int n,m,ret=0;
void cut(int x1,int y1,int x2,int y2,int d){
    while(d<m&&(x2<=rec[d].x1||x1>=rec[d].x2||y2<=rec[d].y1||y1>=rec[d].y2)) d++;
    if(d==m){
        ret+=(x2-x1)*(y2-y1);
        return ;
    }
    if(x1<rec[d].x1){
        cut(x1,y1,rec[d].x1,y2,d+1);
        x1=rec[d].x1;
    }
    if(x2>rec[d].x2){
        cut(rec[d].x2,y1,x2,y2,d+1);
        x2=rec[d].x2;
    }
    if(y1<rec[d].y1)
        cut(x1,y1,x2,rec[d].y1,d+1);
    if(y2>rec[d].y2)
        cut(x1,rec[d].y2,x2,y2,d+1);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d%d%d%s",&rec[i].x1,&rec[i].y1,&rec[i].x2,&rec[i].y2,&rec[i].col);
        if(rec[i].x1>rec[i].x2) swap(rec[i].x1,rec[i].x2);
        if(rec[i].y1>rec[i].y2) swap(rec[i].y1,rec[i].y2);
        rec[i].x2++;rec[i].y2++;
    }
    for(int i=m-1;i>=0;i--){
        if(rec[i].col[0]=='b')
            cut(rec[i].x1,rec[i].y1,rec[i].x2,rec[i].y2,i+1);
    }
    printf("%d\n",n*n-ret);
    return 0;
}
