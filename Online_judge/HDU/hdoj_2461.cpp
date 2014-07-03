#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct Node{
    int x1,y1,x2,y2;
    int area;
}rec[25];
int n,q,cas=1,a[25],area;
bool Init(){
    scanf("%d%d",&n,&q);
    if(n==0&&q==0) return false;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&rec[i].x1,&rec[i].y1,&rec[i].x2,&rec[i].y2);
        rec[i].area=(rec[i].x2-rec[i].x1)*(rec[i].y2-rec[i].y1);
    }
    return true;
}
void xiaojiao(Node b,Node &temp){
    temp.x1=max(temp.x1,b.x1);temp.x2=min(temp.x2,b.x2);
    temp.y1=max(temp.y1,b.y1);temp.y2=min(temp.y2,b.y2);
//    cout<<temp.x1<<" "<<temp.y1<<" "<<temp.x2<<" "<<temp.y2<<endl;
    if(temp.x1>=temp.x2||temp.y1>=temp.y2)
        temp.area=0;
    else
        temp.area=(temp.x2-temp.x1)*(temp.y2-temp.y1);
//    cout<<temp.area<<endl;
}
void dfs(int idx,int k,Node &temp){
    if(idx>a[0]){
        if(k==0) return;
        if(k&1)
            area+=temp.area;
        else
            area-=temp.area;
        return ;
    }
    if(temp.area==0) return;
    Node t=temp;
    dfs(idx+1,k,temp);
    temp=t;
    xiaojiao(rec[a[idx]],temp);
    dfs(idx+1,k+1,temp);
    temp=t;
}
void slove(){
    printf("Case %d:\n",cas++);
    int query=1;
    while(q--){
        scanf("%d",&a[0]);
        for(int i=1;i<=a[0];i++)
            scanf("%d",&a[i]);
        Node temp;
        temp.x1=0;temp.x2=1000;
        temp.y1=0;temp.y2=1000;
        temp.area=1000000;
        area=0;
        dfs(1,0,temp);
        printf("Query %d: %d\n",query++,area);
    }
    puts("");
}
int main(){
    while(Init()){
        slove();
    }
}