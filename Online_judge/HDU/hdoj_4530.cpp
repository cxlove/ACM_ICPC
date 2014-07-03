#include<iostream>    
#include<cstdio>    
#include<map>    
#include<cstring>    
#include<cmath>    
#include<vector>    
#include<algorithm>    
#include<set>    
#include<stack>  
#include<string>    
#include<ctime>  
#include<queue>    
#include<cassert>  
#define inf 1000000005    
#define M 10000005   
#define N 110005  
#define maxn 210005    
#define eps 1e-8  
#define zero(a) fabs(a)<eps    
#define Min(a,b) ((a)<(b)?(a):(b))    
#define Max(a,b) ((a)>(b)?(a):(b))    
#define pb(a) push_back(a)    
#define mp(a,b) make_pair(a,b)    
#define mem(a,b) memset(a,b,sizeof(a))    
#define LL long long    
#define MOD 1000000007  
#define sqr(a) ((a)*(a))    
#define Key_value ch[ch[root][1]][0]    
#define test puts("OK");    
#define pi acos(-1.0)  
#define lowbit(x) ((-(x))&(x))  
#pragma comment(linker, "/STACK:1024000000,1024000000")    
using namespace std; 
int t,x,k,q;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&x,&q);
        while(q--){
            int T,k;
            scanf("%d%d",&T,&k);
            if(T==1){
                printf("%.2f\n",k*1.0*(60-x));
            }
            else if(T==2){
                printf("%.2f\n",k*3600.0/(60-x));
            }
            else printf("%.2f\n",k*720*60*60.0/x);
        }
    }
    return 0;
}