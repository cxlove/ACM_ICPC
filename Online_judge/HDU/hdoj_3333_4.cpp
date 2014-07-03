# include<stdio.h> 
# include<string.h> 
# include<stdlib.h> 
# define N 30005 
# define M 100005 
struct node{ 
    int from,to,idx; 
}Q[M]; 
  
struct node1{ 
    int left,right; 
    __int64 num; 
}tree[N*4]; 
int a[N],tem[N],visit[N],temp[N],k; 
__int64 ans1,ans[M]; 
  
int cmp(const void *a,const void *b) 
{ 
    struct node *c=(struct node *)a; 
    struct node *d=(struct node *)b; 
    return c->to - d->to; 
} 
int cmp1(const void *a,const void *b) 
{ 
    return *(int *)a - *(int *)b; 
} 
void bulid(int l,int r,int t) 
{ 
    int mid; 
    tree[t].num=0; 
    tree[t].left=l; 
    tree[t].right=r; 
    if(l==r) return; 
    mid=(l+r)/2; 
    bulid(l,mid,2*t); 
    bulid(mid+1,r,2*t+1); 
} 
void insert(int t,int p,int val) 
{ 
    int mid; 
    if(tree[t].left==tree[t].right) {tree[t].num+=val;return;} 
    mid=(tree[t].left+tree[t].right)/2; 
    if(p<=mid) insert(2*t,p,val); 
    else if(p>mid) insert(2*t+1,p,val); 
    tree[t].num=tree[2*t].num+tree[2*t+1].num; 
} 
void Query(int t,int l,int r) 
{ 
    int mid; 
    if(tree[t].left==l && tree[t].right==r)  
    { 
        ans1+=tree[t].num;return; 
    } 
    mid=(tree[t].left+tree[t].right)/2; 
    if(r<=mid) Query(2*t,l,r); 
    else if(l>mid) Query(2*t+1,l,r); 
    else
    { 
        Query(2*t,l,mid); 
        Query(2*t+1,mid+1,r 
            ); 
    } 
} 
int is(int v) 
{ 
    int l,r,mid; 
    l=1;r=k; 
    while(l<=r) 
    { 
        mid=(l+r)/2; 
        if(temp[mid]>v) r=mid-1; 
        else if(v>temp[mid]) l=mid+1; 
        else return mid; 
    } 
} 
int main() 
{ 
    int i,j,n,ncase,id,flag,t,m; 
    scanf("%d",&ncase); 
    while(ncase--) 
    { 
        scanf("%d",&n); 
        t=0; 
        for(i=1;i<=n;i++) 
        { 
            scanf("%d",&a[i]); 
            tem[t++]=a[i]; 
        } 
        qsort(tem,t,sizeof(tem[0]),cmp1); 
        temp[1]=tem[0]; 
        k=1; 
        for(i=1;i<t;i++) 
        { 
            if(tem[i]!=tem[i-1])  
            { 
                k++; 
                temp[k]=tem[i]; 
            } 
        } 
        memset(visit,0,sizeof(visit)); 
        scanf("%d",&m); 
        for(i=1;i<=m;i++) 
        { 
            scanf("%d%d",&Q[i].from,&Q[i].to); 
            Q[i].idx=i; 
        } 
        qsort(Q+1,m,sizeof(Q[1]),cmp); 
            bulid(1,n,1); 
        j=1; 
        for(i=1;i<=n;i++) 
        { 
            id=is(a[i]); 
            flag=visit[id]; 
            if(flag) 
            { 
                insert(1,flag,-a[i]); 
            } 
            insert(1,i,a[i]); 
            visit[id]=i; 
            for(;j<=m;j++) 
            { 
                if(i==Q[j].to) 
                { 
                    ans1=0; 
                    Query(1,Q[j].from,Q[j].to); 
                    ans[Q[j].idx]=ans1; 
                } 
                else break; 
            } 
        } 
        for(i=1;i<=m;i++) 
        { 
            printf("%I64d\n",ans[i]); 
        } 
    } 
    return 0; 
}