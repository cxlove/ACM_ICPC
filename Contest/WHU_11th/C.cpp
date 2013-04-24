#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#define pi acos(-1.0)
#define eps 1e-8
using namespace std;
int n;
string ope[300];
bool check(double x){
    double s[300];
    int top=0;
    for(int i=0;i<n;i++){
        if(ope[i]=="x") s[top++]=x;
        if(ope[i]=="sin") s[top-1]=sin(s[top-1]);
        if(ope[i]=="cos") s[top-1]=cos(s[top-1]);
        if(ope[i]=="tan") s[top-1]=tan(s[top-1]);
        if(ope[i]=="+") s[top-2]+=s[top-1],top--;
        if(ope[i]=="-") s[top-2]-=s[top-1],top--;
        if(ope[i]=="*") s[top-2]*=s[top-1],top--;
    }
    return s[0]<=eps;
}
bool solve(){
    for(int i=0;i<100;i++){
        double x=rand()%10000/10000.0*2*pi;
        if(!check(x)) return false;
    }
    return true;
}
int main(){
    srand(time(0));
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            cin>>ope[i];
        printf("Case %d: %s\n",++cas,solve()?"Yes":"No");
    }
    return 0;
}