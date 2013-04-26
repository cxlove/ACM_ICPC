#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#define LL long long
#define mp(a,b) make_pair(a,b)
using namespace std;
const int N = 400005;
int n;
int pre[N],cnt=0;
map<pair<int,int>,int>m;
int find(int x){
    return pre[x]=(pre[x]==x?x:find(pre[x]));
}
int main(){
    cin>>n;
    for(int i=1;i<=2*n;i++)
        pre[i]=i;
    for(int i=0;i<n;i++){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int a=-1,b=-1;
        if(m.find(mp(x1,y1))==m.end())
            m[mp(x1,y1)]=++cnt,a=cnt;
        if(m.find(mp(x2,y2))==m.end())
            m[mp(x2,y2)]=++cnt,b=cnt;
        if(a==-1) a=m[mp(x1,y1)];
        if(b==-1) b=m[mp(x2,y2)];
        int ra=find(a),rb=find(b);
        if(ra==rb){
            printf("%d\n",i+1);
            return 0;
        }
        pre[ra]=rb;
    }
    printf("%d\n",0);
    return 0;
}
