#include<iostream>
#include<cstdio>
#include<cstring>
#define N 99997
#define LL long long 
using namespace std;
int n;
bool flag[N+5];
LL h[N+5];
LL a[5][205];
int Hash(LL num){
    int t=((num%N)+N)%N;
    while(flag[t]&&h[t]!=num)
        t=(t+1)%N;
    return t;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(flag,false,sizeof(flag));
        int n;
        scanf("%d",&n);
        for(int i=0;i<5;i++){
            for(int j=0;j<n;j++)
                scanf("%I64d",&a[i][j]);
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){            
                LL num=-(a[0][i]+a[1][j]);            
                int pos=Hash(num);
                h[pos]=num;                
                flag[pos]=true;
            }
        bool ok=false;    
        
        for(int i=0;i<n;++i)                
            for(int j=0;j<n;++j)                
                for(int k=0;k<n;++k){                        
                    LL num=(a[2][i]+a[3][j]+a[4][k]);
                         int pos=Hash(num);
                         if(flag[pos]) {ok=true;i=j=n;break;}
                    }
    
        if(ok) printf("Yes\n");
       else printf("No\n");
    }
    return 0;
}