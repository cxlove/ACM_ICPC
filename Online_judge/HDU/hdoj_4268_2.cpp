#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#define inf 1<<28
#define N 105
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define LL long long
using namespace std;
struct Node{
    int h,w;
    int id;
    void get(int H,int W,int ID){h=H;w=W;id=ID;}
}v[200005];
multiset<int>m;
multiset<int>::iterator it;
bool cmp(Node n1,Node n2){
    return n1.h!=n2.h?n1.h>n2.h:(n1.w!=n2.w?n1.w>n2.w:n1.id<n2.id);
}
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int h,w;
            scanf("%d%d",&h,&w);
            v[i].get(h,w,0);
        }
        for(int i=0;i<n;i++){
            int h,w;
            scanf("%d%d",&h,&w);
            v[i+n].get(h,w,1);
        }
        sort(v,v+2*n,cmp);
        m.clear();
        int ans=0;
        for(int i=0;i<2*n;i++){
        //    cout<<v[i].id<<" "<<v[i].h<<" "<<v[i].w<<endl;
            if(v[i].id==0) m.insert(v[i].w);
            else{            
                it=m.lower_bound(v[i].w);
                if(it!=m.end()){
                    m.erase(it);
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}