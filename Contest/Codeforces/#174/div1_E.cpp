#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define lson (step<<1)
#define rson (step<<1|1)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define LL long long
using namespace std;
const int N=100005;
struct Seg_tree{
    int left,right;
    int cnt[2],cover;
}L[N<<2];
int n,k,s[N];
vector<pair<int,int> >change,other;
void push_up(int step){
    for(int i=0;i<2;i++)
        L[step].cnt[i]=L[lson].cnt[i]+L[rson].cnt[i];
}
void push_down(int step){
    if(L[step].cover){
        L[lson].cover^=1;
        L[rson].cover^=1;
        swap(L[lson].cnt[0],L[lson].cnt[1]);
        swap(L[rson].cnt[0],L[rson].cnt[1]);
        L[step].cover=0;
    }
}
void bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].cover=0;
    if(l==r){
        L[step].cnt[0]=1;
        L[step].cnt[1]=0;
        return ;
    }
    int m=(l+r)>>1;
    bulid(lson,l,m);
    bulid(rson,m+1,r);
    push_up(step);
}
void update(int step,int l,int r){
    if(L[step].left==l&&L[step].right==r){
        swap(L[step].cnt[0],L[step].cnt[1]);
        L[step].cover^=1;
        return ;
    }
    int m=(L[step].left+L[step].right)>>1;
    push_down(step);
    if(r<=m) update(lson,l,r);
    else if(l>m) update(rson,l,r);
    else{
        update(lson,l,m);
        update(rson,m+1,r);
    }
    push_up(step);
}
int query(int step,int l,int r,int c){
    if(L[step].left==l&&L[step].right==r)
        return L[step].cnt[c];
    int m=(L[step].left+L[step].right)>>1;
    push_down(step);
    if(r<=m) return query(lson,l,r,c);
    else if(l>m) return query(rson,l,r,c);
    else return query(lson,l,m,c)+query(rson,m+1,r,c);
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    sort(s+1,s+1+n);
    bulid(1,1,n);
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        a=lower_bound(s+1,s+1+n,a)-s;
        b=upper_bound(s+1,s+1+n,b)-s-1;
        if(a>b) continue;
        other.pb(mp(b,a));
        change.pb(mp(a,b));
    }
    sort(change.begin(),change.end());
    sort(other.begin(),other.end());
    LL ans=(LL)n*(n-1)*(n-2)/6;
    for(int i=1,j=0,r=0;i<=n;i++){
        while(j<change.size()&&change[j].first==i){
            update(1,change[j].first,change[j].second);
            j++;
        }
        int win=0;
        if(i>1) win+=query(1,1,i-1,0);
        if(i<n) win+=query(1,i+1,n,1);
        //cout<<win<<endl;
        ans-=(LL)win*(win-1)/2;
        while(r<other.size()&&other[r].first==i){
            update(1,other[r].second,other[r].first);
            r++;
        }
    }
    cout<<ans<<endl;
    return 0;
}