#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#define inf 110000000
#define M 10005
#define N 100005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define MOD 1000000007
using namespace std;
struct Node{
    int val,id;
}x[N],y[N];
int n,q;
int flag[N];
bool cmp(Node n1,Node n2){
    return n1.val<n2.val;
}
int BinSearch(Node *a,int n,int m){
    int low=0,high=n-1,mid,pos=-1;
    while(low<=high){
        mid=(low+high)/2;
        if(a[mid].val==m){pos=mid;break;}
        if(a[mid].val<m) low=mid+1;
        else high=mid-1;
    }
    if(pos==-1) return 0;
    int i=pos-1,ans=0;
    while(i>=0&&a[i].val==m){
        if(flag[a[i].id]==0){flag[a[i].id]=1;ans++;}
        i--;
    }
    while(pos<n&&a[pos].val==m){
        if(flag[a[pos].id]==0){flag[a[pos].id]=1;ans++;}
        pos++;
    }
    return ans;
}
int main(){
    while(scanf("%d%d",&n,&q)!=EOF&&n+q){
        for(int i=0;i<n;i++){
            scanf("%d%d",&x[i].val,&y[i].val);
            x[i].id=y[i].id=i;
        }
        sort(x,x+n,cmp);
        sort(y,y+n,cmp);
        mem(flag,0);
        while(q--){
            int k,p;
            scanf("%d%d",&k,&p);
            if(k==0)
                printf("%d\n",BinSearch(x,n,p));
            else
                printf("%d\n",BinSearch(y,n,p));
        }
        puts("");
    }
    return 0;
}



