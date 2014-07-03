#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define C    240
#define TIME 10
#define inf 1<<25
#define LL long long
using namespace std;
int m[2][2]={0,0,0,1};
int Nim_Mult_Power(int x,int y){
    if(x<2)
        return m[x][y];
    int a=0;
    for(;;a++)
        if(x>=(1<<(1<<a))&&x<(1<<(1<<(a+1))))
            break;
    int m=1<<(1<<a);
    int p=x/m,s=y/m,t=y%m;
    int d1=Nim_Mult_Power(p,s);
    int d2=Nim_Mult_Power(p,t);
    return (m*(d1^d2))^Nim_Mult_Power(m/2,d1);
}
int Nim_Mult(int x,int y){
    if(x<y)
        return Nim_Mult(y,x);
    if(x<2)
        return m[x][y];
    int a=0;
    for(;;a++)
        if(x>=(1<<(1<<a))&&x<(1<<(1<<(a+1))))
            break;
    int m=1<<(1<<a);
    int p=x/m,q=x%m,s=y/m,t=y%m;
    int c1=Nim_Mult(p,s),c2=Nim_Mult(p,t)^Nim_Mult(q,s),c3=Nim_Mult(q,t);
    return (m*(c1^c2))^c3^Nim_Mult_Power(m/2,c1);
}
int main(){
    int n,x,y,z;
    while(scanf("%d",&n)!=EOF){
        int ret=0;
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&x,&y,&z);
            ret^=Nim_Mult(Nim_Mult(x,y),z);
        }
        puts(!ret?"Yes":"No");
    }
    return 0;
}
