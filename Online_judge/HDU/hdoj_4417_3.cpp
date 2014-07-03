#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<queue>
#define inf 1<<28
#define M 6000005
#define N 100005
#define maxn 300005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define MOD 1000000007
#define lson step<<1
#define rson step<<1|1
using namespace std;
struct Node{
    int left,right;
    int sum;
}L[N*4];
int sa[N],num[20][N],cnt[20][N];
void Bulid(int step,int l,int r,int deep){
    L[step].left=l;
    L[step].right=r;
    if(l==r)
        return;
    int mid=(l+r)>>1;
    int mid_val=sa[mid],lsum=mid-l+1;;
    for(int i=l;i<=r;i++)
        if(num[deep][i]<mid_val)
            lsum--;    //lsum表示左子树中还需要多少个中值
    int L=l,R=mid+1;
    for(int i=l;i<=r;i++){
        if(i==l)
            cnt[deep][i]=0;
        else
            cnt[deep][i]=cnt[deep][i-1];
        if(num[deep][i]<mid_val||(num[deep][i]==mid_val&&lsum>0)){  //左子树
            num[deep+1][L++]=num[deep][i];
            cnt[deep][i]++;
            if(num[deep][i]==mid_val)
                lsum--;
        }
        else
            num[deep+1][R++]=num[deep][i];
    }
    Bulid(2*step,l,mid,deep+1);
    Bulid(2*step+1,mid+1,r,deep+1);
}
int Query(int step,int l,int r,int k,int deep){
    if(l==r)
        return num[deep][l];
    int s1,s2;   //s1为[L[step].left,l-1]中分到左子树的个数
    if(L[step].left==l)
        s1=0;
    else
        s1=cnt[deep][l-1];
    s2=cnt[deep][r]-s1;   //s2为[l,r]中分到左子树的个数
    int m=(L[step].left+L[step].right)/2;
    if(k<=s2)   //左子树的数量大于k,递归左子树
        return Query(lson,L[step].left+s1,L[step].left+s1+s2-1,k,deep+1);
    int b1=l-1-L[step].left+1-s1;  //b1为[L[step].left,l-1]中分到右子树的个数
    int b2=r-l+1-s2;   //b2为[l,r]中分到右子树的个数
    return Query(rson,m+1+b1,m+1+b1+b2-1,k-s2,deep+1);
}
int slove(int l,int r,int h){
    int ans=0,low=1,high=r-l+1,mid;
    while(low<=high){
        mid=(low+high)/2;
        int tmp=Query(1,l,r,mid,0);
        if(tmp<=h){ans=mid;low=mid+1;}
        else high=mid-1;
    }
    return ans;
}
int main(){
    int n,q,t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++){
            scanf("%d",&sa[i]);
            num[0][i]=sa[i];
        }
        sort(sa+1,sa+1+n);
        Bulid(1,1,n,0);
        printf("Case %d:\n",++cas);
        while(q--){
            int l,r,h;
            scanf("%d%d%d",&l,&r,&h);
            l++;r++;
            printf("%d\n",slove(l,r,h));
        }
    }
    return 0;
}





