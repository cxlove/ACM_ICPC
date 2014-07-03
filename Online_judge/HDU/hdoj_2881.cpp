#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
    int x,y,t;
}q[100005];
int  n,m,len;
vector<int>v[100005];
bool cmp(node a,node b)
{
    return a.t<b.t;
} 
int ABS(int val)
{
    return val<0?-val:val;
}    
bool work(int a,int b)
{
    int i,j;
    for(i=0;i<v[a].size();i++)
    {
        if(ABS(q[b].x-q[v[a][i]].x)+ABS(q[b].y-q[v[a][i]].y)<=q[b].t-q[v[a][i]].t)
           return true;
    }
    return false;
}       
        
int main()
{
    int i,j,l,r,mid;
    while(scanf("%d%d",&n,&m)!=EOF)
    {  
        if(n==0&&m==0) break;
        for(i=0;i<=m+1;i++) v[i].clear();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&q[i].t,&q[i].x,&q[i].y);
        }
        sort(q,q+m,cmp);
        len=1;
        v[0].push_back(0);
        for(i=1;i<m;i++)
        {
            l=0,r=len-1;
            while(l<=r)
            {
               mid=(l+r)>>1;
               if(work(mid,i))
               {
                   l=mid+1;
               }
               else
                  r=mid-1;
           }
           v[l].push_back(i);
           if(l==len) len++;
       }
       printf("%d\n",len);
   }
   return 0;
}              
                  
        