#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#define LL long long
#define eps 1e-7
#define N 2000000
#define MOD 1000000007
#define inf 1<<30
#define zero(a) (fabs((double)(a))<eps)
using namespace std;
struct Point{
    int x,y,v,l;
}p[15];
int n;
vector<Point>a;
int xmul(Point p0,Point p1,Point p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
double dist(Point p1,Point p2){
    return sqrt((double)(p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}
bool cmp(Point p1,Point p2){
    if(xmul(a[0],p1,p2)>0) return true;
    else if(zero(xmul(a[0],p1,p2))&&dist(a[0],p1)<dist(a[0],p2)) return true;
    return false;
}
double Grham_scan(int len){
    if(a.size()==1) return len;
    else if(a.size()==2) return len-dist(a[0],a[1])*2;
    for(int i=1;i<a.size();i++)
        if(a[i].y<a[0].y||(a[i].y==a[0].y&&a[i].x<a[0].x))
            swap(a[0],a[i]);
    sort(a.begin()+1,a.end(),cmp);
    vector<Point>s;
    s.push_back(a[0]);s.push_back(a[1]);s.push_back(a[2]);
    for(int i=3;i<a.size();i++){
        while(s.size()>=2&&xmul(s[s.size()-2],s[s.size()-1],a[i])<eps)
            s.pop_back();
        s.push_back(a[i]);
    }
    s.push_back(s[0]);
    double ans=0;
    for(int i=0;i<s.size()-1;i++)
        ans+=dist(s[i],s[i+1]);
    return len-ans;
}
int main(){
    int cas=0;
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=0;i<n;i++)
            scanf("%d%d%d%d",&p[i].x,&p[i].y,&p[i].v,&p[i].l);
        int best_val=inf,best_num,best_state;
        double best_extra;
        for(int i=1;i<(1<<n)-1;i++){
            int tmp_val=0,tmp_len=0;
            a.clear();
            for(int j=0;j<n;j++){
                if(!((1<<j)&i))
                    a.push_back(p[j]);
                else{
                    tmp_len+=p[j].l;
                    tmp_val+=p[j].v;
                }
            }
            if(tmp_val>best_val)  continue;
            double extra=Grham_scan(tmp_len);
            if(extra>=0){
                if(tmp_val<best_val){
                    best_val=tmp_val;
                    best_num=n-a.size();
                    best_state=i;
                    best_extra=extra;
                }
                else if(tmp_val==best_val&&n-a.size()<best_num){
                    best_num=n-a.size();
                    best_state=i;
                    best_extra=extra;
                }
            }
        }
        printf("Forest %d\nCut these trees: ",++cas);
        for(int i=0;i<n;i++)
            if((1<<i)&best_state)  printf("%d ",i+1);
        printf("\nExtra wood: %.2f\n\n",best_extra);
    }
    return 0;
}


