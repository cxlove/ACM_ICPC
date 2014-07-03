#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct Node{
    int l,w;
}a[5005];
bool cmp(Node n1,Node n2){
    return n1.l!=n2.l?n1.l<n2.l:n1.w<n2.w;
}
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d",&a[i].l,&a[i].w);
        sort(a,a+n,cmp);
        int ans=0,l,w;
        for(int i=0;i<n;i++){
            if(a[i].l==-1)
                continue;
            ans++;
            l=a[i].l;w=a[i].w;
            for(int j=i+1;j<n;j++)
                if(a[j].l>=l&&a[j].w>=w){
                    l=a[j].l;
                    w=a[j].w;
                    a[j].l=-1;
                }
        }
        printf("%d\n",ans);
    }
    return 0;
}