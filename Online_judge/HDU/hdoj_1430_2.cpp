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
    int a[8];
    int val;
}s,u,v;
int fac[8]={1,1,2,6,24,120,720,5040};
int pre[40321];
char ope[40321];
int get_hash(int *tmp){
    int ret=0;
    for(int i=0;i<8;i++){
        int cnt=0;
        for(int j=0;j<i;j++)
            if(tmp[j]>tmp[i])
                cnt++;
        ret+=cnt*fac[i];
    }
    return ret;
}
void change_a(int *tmp){
    for(int i=0;i<4;i++)
        swap(tmp[i],tmp[7-i]);
}
void change_b(int *tmp){
    int temp=tmp[3];
    for(int i=3;i>0;i--)
        tmp[i]=tmp[i-1];
    tmp[0]=temp;
    temp=tmp[4];
    for(int i=4;i<7;i++)
        tmp[i]=tmp[i+1];
    tmp[7]=temp;
}
void change_c(int *tmp){
    int temp=tmp[1];
    tmp[1]=tmp[6];tmp[6]=tmp[5];tmp[5]=tmp[2];
    tmp[2]=temp;
}
void bfs(){
    queue<Node>que;
    que.push(s);
    pre[s.val]=-2;
    while(!que.empty()){
        u=que.front();
        que.pop();
        for(int i=0;i<3;i++){
            v=u;
            if(i==0){
                change_a(v.a);
                v.val=get_hash(v.a);
                if(pre[v.val]==-1){
                    ope[v.val]=i+'A';
                    pre[v.val]=u.val;
                    que.push(v);
                }
            }
            else if(i==1){
                change_b(v.a);
                v.val=get_hash(v.a);
                if(pre[v.val]==-1){
                    ope[v.val]=i+'A';
                    pre[v.val]=u.val;
                    que.push(v);
                }

            }
            else{
                change_c(v.a);
                v.val=get_hash(v.a);
                if(pre[v.val]==-1){
                    ope[v.val]=i+'A';
                    pre[v.val]=u.val;
                    que.push(v);
                }
            }
        }
    }
}
int main(){
    memset(pre,-1,sizeof(pre));
    int t[8]={1,2,3,4,5,6,7,8};
    memcpy(s.a,t,8*sizeof(int));
    s.val=get_hash(s.a);
    bfs();
    char s1[10],s2[10];
    while(scanf("%s%s",s1,s2)!=EOF){
        int pos[10];
        int des[8];
        for(int i=0;i<8;i++)
            pos[s1[i]-'0']=i+1;
        for(int i=0;i<8;i++)
            des[i]=pos[s2[i]-'0'];
        int tmp=get_hash(des),cnt=0;
        char ans[1000];
        while(pre[tmp]!=-2){
            ans[cnt++]=ope[tmp];
            tmp=pre[tmp];
        }
        for(int i=cnt-1;i>=0;i--)
            printf("%c",ans[i]);
        printf("\n");
    }
    return 0;
}