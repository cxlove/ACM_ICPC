//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<queue>
//#include<map>
//#include<stack>
//#include<algorithm>
//#include<string>
//#define LL long long
//#define LD long double
//#define eps 1e-7
//#define inf 1<<30
//#define MOD 1000000007
//#define N 100005
//using namespace std;
//struct MergeTree{
//    int left,right,mid;
//}tree[N*4];
//int num[N],mer[20][N];
//int n,q;
//void create(int step,int l,int r,int deep){
//    tree[step].left=l;
//    tree[step].right=r;
//    tree[step].mid=(l+r)>>1;
//    if(l==r){
//        mer[deep][l]=num[l];
//        return;
//    }
//    create(step<<1,l,(l+r)/2,deep+1);
//    create((step<<1)|1,(l+r)/2+1,r,deep+1);
//    int i=l,j=(l+r)/2+1,p=l;
//    while(i<=(l+r)/2&&j<=r){
//        if(mer[deep+1][i]>mer[deep+1][j])
//            mer[deep][p++]=mer[deep+1][j++];
//        else
//            mer[deep][p++]=mer[deep+1][i++];
//    }
//    while(i<=(l+r)/2)
//        mer[deep][p++]=mer[deep+1][i++];
//    while(j<=r)
//        mer[deep][p++]=mer[deep+1][j++];
//}
//int query(int step,int l,int r,int deep,int key){
//    if(tree[step].right<l||tree[step].left>r)
//        return 0;
//    if(tree[step].left>=l&&tree[step].right<=r)
//        return lower_bound(&mer[deep][tree[step].left],&mer[deep][tree[step].right]+1,key)-&mer[deep][tree[step].left];
//    return query(2*step,l,r,deep+1,key)+query(2*step+1,l,r,deep+1,key);
//}
//int slove(int l,int r,int k){
//    int high=n,low=1,mid;
//    while(low<high){
//        mid=(low+high+1)>>1;
//        int cnt=query(1,l,r,1,mer[1][mid]);
//        if(cnt<=k)
//            low=mid;
//        else
//            high=mid-1;
//    }
//    return mer[1][low];
//}
//int main(){
//    int t;
//    scanf("%d",&t);
//    while(t--){
//        scanf("%d%d",&n,&q);
//        for(int i=1;i<=n;i++)
//            scanf("%d",&num[i]);
//        create(1,1,n,1);
//        while(q--){
//            int l,r,k;
//            scanf("%d%d%d",&l,&r,&k);
//            printf("%d\n",slove(l,r,k-1));
//        }
//    }
//    return 0;
//}

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 100005
using namespace std;
struct Node{
    int left,right,mid;
}tree[N*4];
int sa[N],num[20][N],cnt[20][N];
int n,q;
void debug(int d){
    for(int i=1;i<=n;i++)
        printf("%d ",num[d][i]);
    printf("\n");
}
void bulid(int step,int l,int r,int deep){
    tree[step].left=l;
    tree[step].right=r;
    tree[step].mid=(l+r)>>1;
    if(l==r)
        return;
    int mid=(l+r)>>1;
    int mid_val=sa[mid],lsum=mid-l+1;;
    for(int i=l;i<=r;i++)
        if(num[deep][i]<mid_val)
            lsum--;
    int L=l,R=mid+1;
    for(int i=l;i<=r;i++){
        if(i==l)
            cnt[deep][i]=0;
        else
            cnt[deep][i]=cnt[deep][i-1];
        if(num[deep][i]<mid_val||(num[deep][i]==mid_val&&lsum>0)){
            num[deep+1][L++]=num[deep][i];
            cnt[deep][i]++;
            if(num[deep][i]==mid_val)
                lsum--;
        }
        else
            num[deep+1][R++]=num[deep][i];
    }
//    debug(deep);
    bulid(2*step,l,mid,deep+1);
    bulid(2*step+1,mid+1,r,deep+1);
}
int query(int step,int l,int r,int k,int deep){
    if(l==r)
        return num[deep][l];
    int s1,s2;
    if(tree[step].left==l)
        s1=0;
    else
        s1=cnt[deep][l-1];
    s2=cnt[deep][r]-s1; 
    if(k<=s2)
        return query(2*step,tree[step].left+s1,tree[step].left+s1+s2-1,k,deep+1);
    int b1=l-1-tree[step].left+1-s1;
    int b2=r-l+1-s2;
    return query(2*step+1,tree[step].mid+1+b1,tree[step].mid+1+b1+b2-1,k-s2,deep+1);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++){
            scanf("%d",&num[1][i]);
            sa[i]=num[1][i];
        }
        sort(sa+1,sa+n+1);
        bulid(1,1,n,1);
        while(q--){
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            printf("%d\n",query(1,l,r,k,1));
        }
    }
    return 0;
}