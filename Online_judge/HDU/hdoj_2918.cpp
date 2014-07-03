#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define LD long double
#define LL __int64
#define M 200005
using namespace std;
int T,a[9];
int depth;
char str[10];
bool flag;
int rotation[4][4]={{0,1,4,3},{1,2,5,4},{3,4,7,6},{4,5,8,7}};
int get_h(int *b){
    int ans=0;
    for(int i=0;i<9;i++)
        ans+=abs(i/3-(b[i]-1)/3)+abs(i%3-(b[i]-1)%3);
    return (ans+3)/4;
}
void change(int *b,int kind){
    if(kind&1){
        kind/=2;
        int tmp=b[rotation[kind][3]];
        for(int i=3;i>0;i--)
            b[rotation[kind][i]]=b[rotation[kind][i-1]];
        b[rotation[kind][0]]=tmp;
    }
    else{
        kind/=2;
        int tmp=b[rotation[kind][0]];
        for(int i=1;i<4;i++)
            b[rotation[kind][i-1]]=b[rotation[kind][i]];
        b[rotation[kind][3]]=tmp;
    }
}
void IDAstar(int *b,int tmp_depth,int pre){
    if(flag)
        return;
    if(get_h(b)>tmp_depth)
        return;
    if(tmp_depth==0&&get_h(b)==0){
        flag=true;
        return;
    }
    for(int i=0;i<8;i++){
        if(pre>=0&&pre/2==i/2&&(pre%2)^(i%2))
            continue;
        int tmp[9];
        for(int j=0;j<9;j++)
            tmp[j]=b[j];
        change(tmp,i);
        IDAstar(tmp,tmp_depth-1,i);
    }
}
int main(){
    int cas=0;
    while(scanf("%s",str)!=EOF&&strcmp(str,"0000000000")){
        T=str[0]-'0';
        for(int i=0;i<9;i++)
            a[i]=str[i+1]-'0';    
        flag=false;
        for(depth=get_h(a);depth<=T;depth++){    
            IDAstar(a,depth,-1);
            if(flag){
                printf("%d. %d\n",++cas,depth);
                break;
            }
        }
        if(!flag)
            printf("%d. -1\n",++cas);
    }
    return 0;
}
