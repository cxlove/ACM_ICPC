#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
#include<cassert>
#define LL long long
#define eps 1e-8
#define inf 10000
#define zero(a) fabs(a)<eps
#define N 20005
using namespace std;
struct Point{
    double x,y;
}ant[105],tree[105];
double xmul(Point p0,Point p1,Point p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
bool SegmentAcross(Point s1a,Point s1b,Point s2a,Point s2b){
    if(max(s1a.x,s1b.x)>=min(s2a.x,s2b.x)&&max(s2a.x,s2b.x)>=min(s1a.x,s1b.x)
    &&max(s1a.y,s1b.y)>=min(s2a.y,s2b.y)&&max(s2a.y,s2b.y)>=min(s1a.y,s1b.y))
		if(xmul(s1a,s1b,s2a)*xmul(s1a,s1b,s2b)<-eps)
			if(xmul(s2a,s2b,s1a)*xmul(s2a,s2b,s1b)<-eps)
		    	return true;
	return false;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&ant[i].x,&ant[i].y);
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&tree[i].x,&tree[i].y);
        int match[105];
        for(int i=0;i<n;i++)
            match[i]=i;
        while(1){
            bool ok=true;
            for(int i=0;i<n;i++)
               for(int j=0;j<n;j++){
                   if(i==j) continue;
                   if(SegmentAcross(ant[i],tree[match[i]],ant[j],tree[match[j]])){
                       swap(match[i],match[j]);
                       ok=false;
                   }
               }
            if(ok) break;
        }
        for(int i=0;i<n;i++) printf("%d\n",match[i]+1);
    }
    return 0;
}


