#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<string>
#include<vector>
#define eps 1e-10
#define LL long long
#define LD long double
#define pi acos(-1.0)
#define inf 1LL<<60
using namespace std;
struct Node{
    int A,B;
}a[1000];
bool cmp(Node n1,Node n2){
    return n1.B-n1.A>n2.B-n2.A;
}
int n,v,t;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&v,&n);
        for(int i=0;i<n;i++)
            scanf("%d%d",&a[i].A,&a[i].B);
        sort(a,a+n,cmp);
        bool flag=true;
        for(int i=0;i<n;i++)
            if(v>=a[i].B&&v>=a[i].A)
                v-=a[i].A;
            else{
                flag=false;
                break;
            }
        printf("%s\n",flag?"Yes":"No");
    }
    return 0;
}