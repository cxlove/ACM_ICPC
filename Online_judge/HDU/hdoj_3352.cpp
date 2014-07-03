#include<iostream>  
#include<cstdio>  
#include<map>  
#include<cstring>  
#include<cmath>  
#include<vector>  
#include<algorithm>  
#include<set>  
#include<string>  
#include<queue>  
#define inf 100000005  
#define M 40  
#define N 210005  
#define maxn 300005  
#define eps 1e-10  
#define zero(a) fabs(a)<eps  
#define Min(a,b) ((a)<(b)?(a):(b))  
#define Max(a,b) ((a)>(b)?(a):(b))  
#define pb(a) push_back(a)  
#define mp(a,b) make_pair(a,b)  
#define mem(a,b) memset(a,b,sizeof(a))  
#define LL unsigned long long  
#define MOD 2012  
#define lson step<<1  
#define rson step<<1|1  
#define sqr(a) ((double)(a)*(a))  
#define Key_value ch[ch[root][1]][0]  
#define test puts("OK");  
#pragma comment(linker, "/STACK:1024000000,1024000000")  
using namespace std;  
LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}
LL lcm(LL a,LL b){
    return a/gcd(a,b)*b;
}
int main(){
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int w,h;
    while(cin>>w>>h)
    {
        if(w==0&&h==0) break;
        LL tmp=lcm(w,h);
        cout<<tmp/w*tmp/h<<endl;
    }

    return 0;
}