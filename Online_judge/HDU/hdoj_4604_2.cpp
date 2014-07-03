    #include<iostream>  
    #include<cstdio>  
    #include<string>  
    #include<cstring>  
    #include<algorithm>  
    #include<cmath>  
    using namespace std;  
    #define lson l,mid,rt<<1  
    #define rson mid+1,r,rt<<1|1  
    const int maxn=100005;  
    struct node  
    {  
        int val,id;  
        bool operator<(const node &a) const  
        {  
            return val<a.val;  
        }  
    }nd[maxn];  
    int a[maxn];  
    int tree[maxn<<2][2];  
    int query(int type,int L,int R,int l,int r,int rt)  
    {  
        if(L<=l&&r<=R)  
        {  
            return tree[rt][type];  
        }  
        int mid=(l+r)>>1;  
        int ret=0;  
        if(R<=mid)  
            return query(type,L,R,lson);  
        if(L>mid)  
            return query(type,L,R,rson);  
        ret=query(type,L,R,lson);  
        ret=max(ret,query(type,L,R,rson));  
        return ret;  
    }  
    void insert(int type,int pos,int val,int l,int r,int rt)  
    {  
        if(l==r)  
        {  
            tree[rt][type]=max(tree[rt][type],val);  
            return ;  
        }  
        int mid=(l+r)>>1;  
        if(pos<=mid)  
            insert(type,pos,val,lson);  
        if(pos>mid)  
            insert(type,pos,val,rson);  
        tree[rt][type]=max(tree[rt<<1][type],tree[rt<<1|1][type]);  
    }  
    int main()  
    {  
        int t,i,j,n,cg,ans,t1,t2,tt1,tt2;  
        scanf("%d",&t);  
        while(t--)  
        {  
            scanf("%d",&n);  
            for(i=1;i<=n;++i)  
            {  
                scanf("%d",&a[i]);  
                nd[i].val=a[i];nd[i].id=i;  
            }  
            sort(nd+1,nd+1+n);  
            cg=1;  
            a[nd[1].id]=1;  
            for(i=2;i<=n;++i)  
            {  
                if(nd[i].val!=nd[i-1].val)  
                    cg++;  
                a[nd[i].id]=cg;  
            }  
            memset(tree,0,sizeof(tree));  
            ans=0;  
            for(i=n;i>0;--i)  
            {  
                t1=query(1,1,a[i],1,cg,1);  
                tt1=t1;  
                if(a[i]!=cg)  
                {  
                    t1+=query(0,a[i]+1,cg,1,cg,1);  
                }  
                t2=query(0,a[i],cg,1,cg,1);  
                tt2=t2;  
                if(a[i]!=1)  
                {  
                    t2+=query(1,1,a[i]-1,1,cg,1);  
                }  
                ans=max(ans,max(t1,t2)+1);  
                insert(1,a[i],tt1+1,1,cg,1);  
                insert(0,a[i],tt2+1,1,cg,1);  
            }  
            printf("%d\n",ans);  
        }  
        return 0;  
    }  