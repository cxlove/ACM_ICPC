#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#define inf 1<<28
#define N 105
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define LL long long
using namespace std;
int k;
LL Pow[50005][31]={0};
bool find(int x,int z,int k){
    int low=x+1,high=50000-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(Pow[mid][z]==0) {high=mid-1;continue;}
        LL tmp=Pow[x][z]+Pow[mid][z]+(LL)x*mid*z;
        if(tmp==k) return true;
        if(tmp<k) low=mid+1;
        else high=mid-1;
    }
    return false;
}
int main(){
    for(int i=1;i<50000;i++){
        Pow[i][1]=i;
        for(int j=2;j<=31;j++){
            Pow[i][j]=Pow[i][j-1]*i;
            if(Pow[i][j]>(1ll<<32))
                break;
        }
    }
    while(scanf("%d",&k)!=EOF&&k){
        int ans=0;
        for(int z=2;z<=31;z++){
            for(int x=1;k>=Pow[x][z];x++)
                if(find(x,z,k))
                    ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}


