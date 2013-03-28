/*
ID:cxlove
Prob:G Grapevine
Algorithm:binary search
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
const int N=505;
struct Query{
    int l,r,id;
    bool operator<(Query q)const{
        return l!=q.l?l<q.l:r<q.r;
    }
}query[10005];
int a[505][505];
int row[505],ans[10005];
int n,m,q;
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(!n&&!m)  break;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
            row[i]=1;
        }
        scanf("%d",&q);
        for(int i=0;i<q;i++){
            scanf("%d%d",&query[i].l,&query[i].r);
            query[i].id=i;
            ans[i]=0;
        }
        sort(query,query+q);
        for(int i=0;i<q;i++){
            int l=query[i].l,r=query[i].r,id=query[i].id;
            for(int j=1;j<=n;j++){
                while(row[j]<=m&&a[j][row[j]]<l) row[j]++;
                if(row[j]<=m){
                    int low=1,high=min(n-j+1,m-row[j]+1),mid;
                    while(low<=high){
                        mid=(low+high)>>1;
                        if(a[j+mid-1][row[j]+mid-1]<=r){
                            ans[id]=max(ans[id],mid);
                            low=mid+1;
                        }
                        else high=mid-1;
                    }
                }
            }
        }
        for(int i=0;i<q;i++) 
            printf("%d\n",ans[i]);
        puts("-");
    }
    return 0;
}