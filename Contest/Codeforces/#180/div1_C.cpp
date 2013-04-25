#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#define LL long long
#define test puts("OK");
using namespace std;
struct Node{
    int c,id;
    bool operator<(const Node n)const{
        return c<n.c;
    }
}a[100005];
int c[100005],d[100005];
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].c);
        a[i].id=i;
    }
    sort(a,a+n);
    int m=n/3;
    for(int i=m,j=0;i<n;i++,j++){
        int id=a[i].id;
        if(j&1){
            c[id]=j/2;
            d[id]=a[i].c-c[id];
        }
        else{
            d[id]=j/2;
            c[id]=a[i].c-d[id];
        }
    }
    for(int i=0;i<m;i++){
        c[a[i].id]=0;
        d[a[i].id]=a[i].c;
    }
    puts("YES");
    for(int i=0;i<n;i++) printf("%d ",c[i]);puts("");
    for(int i=0;i<n;i++) printf("%d ",d[i]);
    return 0;
}