#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define N 1000000
#define LL long long
#define inf 1<<29
#define eps 1e-7
using namespace std;
int sg[N];
//n是P态，能一步到达的是N态
void get_sg(int n){
    int len=1,b=1;
    while(1){
        if(n==0||(n>=b&&n<b*10))
            break;
        len++;
        b*=10;
    }
    b=1;
    for(int i=1;i<=len;i++){
        int s=(n/b)%10;
        int t=n;
        for(int j=s+1;j<=9;j++){
            t+=b;
            sg[t]=1;
        }
        b*=10;
    }
    if(len!=6){
        int t=n*10; //先在后面加一个0
        sg[t]=1;
        int b=10;
        for(int i=len+2;i<=6;i++){
            t*=10;
            for(int j=0;j<b;j++)
                sg[t+j]=1;
            b*=10;
        }
    }
}
void Init(){
    memset(sg,0,sizeof(sg));
    sg[0]=1;
    for(int i=0;i<N;i++)
        if(!sg[i])
            get_sg(i);
}
char str[10];
int main(){
    Init();
    while(scanf("%s",str)!=EOF){
        if(str[0]==0){
            puts("Yes");
            continue;
        }
        int n=0;
        for(int i=0;i<strlen(str);i++)
            n=n*10+str[i]-'0';
        if(!sg[n])
            puts("No");
        else
            puts("Yes");
    }
    return 0;
}
        