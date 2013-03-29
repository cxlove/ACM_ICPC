#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;
int n,m,k,t;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        if(!(n&1)) puts("Bob");
        else{
            bool flag=true;
            for(int i=1;i*i<=m&&flag;i++)
                if(m%i==0)
                    if(i>=k&&m/i>1||m/i>=k&&i>1)
                        flag=false;
            puts(flag?"Bob":"Alice");
        }
    }
    //printf("%.6lf",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}