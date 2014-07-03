#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 100005
#define LL __int64
using namespace std;
struct Node{
    int left,right,mid;
}tree[N*4];
int sa[N],num[20][N],cnt[20][N]; //sa中是排序后的，num记录每一层的排序结果，cnt[deep][i]表示第deep层，前i个数中有多少个进入左子树
LL Lsum[20][N],sum[N];
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
            lsum--;    //lsum表示左子树中还需要多少个中值
    int L=l,R=mid+1;
    Lsum[deep][0]=0;
    for(int i=l;i<=r;i++){
        if(i==l)
            cnt[deep][i]=0;
        else
            cnt[deep][i]=cnt[deep][i-1];
        Lsum[deep][i]=Lsum[deep][i-1];
        if(num[deep][i]<mid_val||(num[deep][i]==mid_val&&lsum>0)){  //左子树
            num[deep+1][L++]=num[deep][i];
            cnt[deep][i]++;
            Lsum[deep][i]+=(LL)num[deep][i];
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
int lnum;
LL lsum;
int query(int step,int l,int r,int k,int deep){
    if(l==r)
        return num[deep][l];
    int s1,s2;   //s1为[tree[step].left,l-1]中分到左子树的个数
    if(tree[step].left==l)
        s1=0;
    else
        s1=cnt[deep][l-1];
    s2=cnt[deep][r]-s1;   //s2为[l,r]中分到左子树的个数
    if(k<=s2)   //左子树的数量大于k,递归左子树
        return query(2*step,tree[step].left+s1,tree[step].left+s1+s2-1,k,deep+1);
    int b1=l-1-tree[step].left+1-s1;  //b1为[tree[step].left,l-1]中分到右子树的个数
    int b2=r-l+1-s2;   //b2为[l,r]中分到右子树的个数
    lnum+=s2;
    lsum=(LL)lsum+Lsum[deep][r]-Lsum[deep][l-1];
    return query(2*step+1,tree[step].mid+1+b1,tree[step].mid+1+b1+b2-1,k-s2,deep+1);
}
int main(){
    int cas=0;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n)    ;
        sum[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&num[1][i]);
            sa[i]=num[1][i];
            sum[i]=(LL)sum[i-1]+sa[i];
        }
        sort(sa+1,sa+n+1);
        bulid(1,1,n,1);
        scanf("%d",&q);
        printf("Case #%d:\n",++cas);
        while(q--){
            int l,r,k;
            scanf("%d%d",&l,&r);
            l++;r++;
            k=(r-l+2)>>1;
            lnum=0;
            lsum=0;
            int ave=query(1,l,r,k,1);
            printf("%I64d\n",(LL)ave*(lnum-(r-l+1-lnum))+sum[r]-sum[l-1]-lsum-lsum);
        }
        puts("");
    }
    return 0;
}