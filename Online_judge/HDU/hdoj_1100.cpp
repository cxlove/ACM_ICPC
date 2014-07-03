#include<iostream>
#include<cstdio>
#include<cstring>
#define LL __int64
using namespace std;
LL c[30]={1};
//预处理卡特兰数
void Init(){
    for(int i=1;i<=25;i++)
        c[i]=c[i-1]*(4*i-2)/(i+1);
}
//输出k个节点的并排在第cnt位的二叉树
void slove(int k,int cnt){
    //只有一个节点，直接输出
    if(k==1){
        printf("X");
        return;
    }
    //排名很靠前，只有右子树
    if(cnt<=c[k-1]){
        printf("X");
        printf("(");
        slove(k-1,cnt);
        printf(")");
    }
    //排名很靠后，只有左子树
    else if(cnt>c[k]-c[k-1]){
        printf("(");
        slove(k-1,cnt-(c[k]-c[k-1]));
        printf(")");
        printf("X");
    }
    else{
        int t=k-1,m;
        //判断左右子树各有多少个节点，更新名次
        for(int i=t;i>=0;i--){
            if(c[i]*c[t-i]<cnt)
                cnt-=c[i]*c[t-i];
            else{
                m=i;
                break;
            }
        }
        printf("(");
        //递归左子树
        slove(t-m,cnt/c[m]+(cnt%c[m]!=0));
        printf(")X(");
        //递归右子树
        slove(m,(cnt-1)%c[m]+1);
        printf(")");
    }
}
int main(){
    int n,m;
    Init();
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=1;;i++){
            if(n>c[i])
                n-=c[i];
            else{
                m=i;
                break;
            }
        }
        slove(m,n);
        printf("\n");
    }
    return 0;
}