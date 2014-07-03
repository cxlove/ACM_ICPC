#include<iostream>  
#include<cstdio>  
#include<map>  
#include<cstring>  
#include<cmath>  
#include<vector>  
#include<algorithm>  
#include<set>  
#include<string>  
#include<ctime>
#include<queue>  
#define inf 1000000005  
#define M 40  
#define N 100005
#define maxn 300005  
#define eps 1e-8
#define zero(a) fabs(a)<eps  
#define Min(a,b) ((a)<(b)?(a):(b))  
#define Max(a,b) ((a)>(b)?(a):(b))  
#define pb(a) push_back(a)  
#define mp(a,b) make_pair(a,b)  
#define mem(a,b) memset(a,b,sizeof(a))  
#define LL long long  
#define MOD 1000000007
#define lson step<<1
#define rson step<<1|1
#define sqr(a) ((a)*(a))  
#define Key_value ch[ch[root][1]][0]  
#define test puts("OK");  
#define pi acos(-1.0)
#define lowbit(x) ((-(x))&(x))
#define HASH1 1331
#define HASH2 10001
#define C   240  
#define TIME 10  
#pragma comment(linker, "/STACK:1024000000,1024000000")  
using namespace std;
int main(){
int a, e,o,u,i,j,n;
    char b[105];
   // while(!=EOF)
   // {
        scanf("%d",&n);
       for(int k=0;k<n;k++)
        {
            if(k==0) getchar();
            a=e=i=o=u=0;
            if(k) puts("");
            gets(b);
            for(j=0;b[j];j++)
            {
                if(b[j]=='a')a++;
                if(b[j]=='e')e++;
                if(b[j]=='i')i++;
                if(b[j]=='o')o++;
                if(b[j]=='u')u++;
            }
            printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",a,e,i,o,u);
        }
    //}
    return 0;
}
