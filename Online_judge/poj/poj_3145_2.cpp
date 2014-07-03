#include<iostream>
 #include<string>
 #include<cmath>
#include<cstdio>
 #include<algorithm>
 using namespace std;
 #define inf 500005
 
 struct node
 {
     int l;
     int r;
     int min_val;
 };
 
 node tree[2500000];
 int n,len;
 int pos[inf];
 int val[inf];
 
 int min(int a,int b)
 {
     return a<b?a:b;
 }
 
 void build(int i,int l,int r)
 {
     tree[i].l=l;
     tree[i].r=r;
     tree[i].min_val=inf;
     if(l==r)
         return;
     int mid=(l+r)/2;
     build(2*i,l,mid);
     build(2*i+1,mid+1,r);
 }
 
 void updata(int i,int w) //更新区间[l,r]
 {
     if(tree[i].l>w || tree[i].r<w)
         return;
     if(tree[i].l>=w && tree[i].r<=w)
     {
         tree[i].min_val=w;
         return;
     }
     updata(2*i,w);
     updata(2*i+1,w);
     tree[i].min_val=min(tree[2*i].min_val,tree[2*i+1].min_val);
 }
 
 int find(int i,int l,int r) //返回区间[l,r]的最小值
 {
     if(tree[i].l>r || tree[i].r<l)
         return inf;
     if(tree[i].l>=l && tree[i].r<=r)
         return tree[i].min_val;
     if(tree[i].l<tree[i].r)
     {
         return min(find(2*i,l,r),find(2*i+1,l,r));
     }
     return inf;
 }
 
 int fun(int y) //直接查找
 {
     int i,ans=inf,k;
     for(i=len;i>=1;i--)
     {
         if(val[i]%y==0)
         {
             return i;
         }
         if(val[i]%y<ans)
         {
             ans=val[i]%y;
             k=i;
         }
     }
     return k;
 }
 
 int solve(int mod)  
 {
     int l=0,r=mod-1,ans=inf,k,temp;//[l,r]便是鸽笼的大小
     while(l<=500000)
     {
         if(r>500000)
             r=500000;
         temp=find(1,l,r);
         if(temp!=inf && temp%mod<ans)
         {
             ans=temp%mod;
             k=pos[temp];
         }
         else if(temp%mod==ans && pos[temp]>k)
         {
             k=pos[temp];
         }
         l+=mod;
         r+=mod;
     }
     return k;
 }
 
 int main()
 {
     char c;
     int x,cas=1,i,ans;
     //freopen("d:\\in.txt","r",stdin);
     while(scanf("%d",&n)!=EOF && n)
     {
         if(cas>1)
             printf("\n");
         build(1,0,500000);
         printf("Case %d:\n",cas++);
         len=0;
         for(i=0;i<n;i++)
         {
             getchar();
             scanf("%c %d",&c,&x);
             if(c=='B')
             {
                 len++;
                 pos[x]=len;
                 val[len]=x;
                 updata(1,x);
             }
             else
             {
                 if(len==0)
                 {
                     printf("-1\n");
                     continue;
                 }
                 if(x<=5000)//范围较小的时候直接查找
                 {
                     ans=fun(x);
                     printf("%d\n",ans);
                 }
                 else
                 {
                     ans=solve(x);
                     printf("%d\n",ans);
                 }
             }
         }
     }
     return 0;
 }
