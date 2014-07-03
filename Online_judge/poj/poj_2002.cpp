#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;
set<int>myset;
int hash(int x,int y){
    return x*20005+y;
}
struct Point{
    int x,y;
    void read(){
        scanf("%d%d",&x,&y);
        myset.insert(hash(x,y));
    }
    bool operator<(const Point n)const{
        return x!=n.x?x<n.x:y<n.y;
    }
}p[1000];
int n;
int main(){
    while(scanf("%d",&n)&&n){
        myset.clear();
        for(int i=0;i<n;i++)
            p[i].read();
        sort(p,p+n);
        int ret=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(myset.find(hash(p[i].x+p[j].y-p[i].y,p[i].y+p[i].x-p[j].x))!=myset.end()&&myset.find(hash(p[j].x+p[j].y-p[i].y,p[j].y+p[i].x-p[j].x))!=myset.end())
                    ret++;
            }
        }
        printf("%d\n",ret/2);
    }
    return 0;
}
