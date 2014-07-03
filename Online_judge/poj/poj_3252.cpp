#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define C    240
#define TIME 10
#define inf 1<<25
#define LL long long
using namespace std;
int c[35][35];
void Init(){
    for(int i=0;i<33;i++){
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
}
int slove(int n){
    int len=0,bit[35];
    while(n){
        bit[++len]=n%2;
        n/=2;
    }
    int sum=0;
    for(int i=1;i<len;i++)
        for(int j=(i+1)/2;j<i;j++)
            sum+=c[i-1][j];
    int one=1,zero=0;
    for(int i=len-1;i;i--){
        if(bit[i]){
            zero++;
            for(int j=max(0,(len+1)/2-zero);j<i;j++)
                sum+=c[i-1][j];
            zero--;
            one++;
        }
        else
            zero++;
    }
    return sum;
}
int main(){
    int l,r;
    Init();
    while(cin>>l>>r)
        cout<<slove(r+1)-slove(l)<<endl;
    return 0;
}



