#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cctype>
#include <assert.h>

using namespace std;

#define maxn 50010

#define inf 100000000

struct segment
{
int beg,end;
};

struct node 
{
int left,right;
int flag;
int lmax,rmax,tmax;
int dis()
{
return right-left+1;
}
void setV()
{
lmax = rmax = tmax = flag?0:dis();
}
};

node tree[maxn*3];
vector<segment> seg;
void BuildTree(int root,int left,int right)
{
tree[root].left = left;
tree[root].right = right;
tree[root].flag = 0;
tree[root].tmax = tree[root].lmax = tree[root].rmax = right-left+1;
if (left==right)
{
return ;
}
int mid = (left+right)/2;
BuildTree(root*2,left,mid);
BuildTree(root*2+1,mid+1,right);
}

void insert(int left,int right,int root,int mark)
{
if (left<=tree[root].left&&right>=tree[root].right)
{
tree[root].flag = mark;
tree[root].setV();
return ;
}
if (tree[root].flag!=-1)
{
tree[root*2].flag = tree[root*2+1].flag = tree[root].flag;
tree[2*root].setV();
tree[2*root+1].setV();
tree[root].flag = -1;
}
int mid = (tree[root].left+tree[root].right)/2;
if (left<=mid)
{
insert(left,right,root*2,mark);

} 
if (right>mid)
{
insert(left,right,root*2+1,mark);
}
tree[root].tmax = max(tree[root*2].rmax+tree[2*root+1].lmax,max(tree[root*2].tmax,tree[root*2+1].tmax));
tree[root].lmax = tree[root*2].lmax;
tree[root].rmax = tree[root*2+1].rmax;
if (tree[root*2].tmax==tree[root*2].dis())
{
tree[root].lmax += tree[2*root+1].lmax;
}
if (tree[root*2+1].tmax==tree[root*2+1].dis())
{
tree[root].rmax += tree[2*root].rmax;
}

}

int query(int val,int root)
{
if (tree[root].left==tree[root].right&&val==1)
{
return tree[root].left;
}
if (tree[root].flag!=-1)
{
tree[root*2].flag = tree[root*2+1].flag = tree[root].flag;
tree[2*root].setV();
tree[2*root+1].setV();
tree[root].flag = -1;
}
if (tree[root*2].tmax>=val)
{
return query(val,2*root);
}
else if (tree[root*2].rmax+tree[root*2+1].lmax>=val)
{
return tree[root*2].right - tree[root*2].rmax+1;
}
else if (tree[root*2+1].tmax>=val)
{
query(val,root*2+1);
}
else
{
return 0;
}
}

int n,m;

int Bsearch(int x)
{
int low = 0;
int high = seg.size()-1;
while (low<=high)
{
int mid = (low+high)>>1;
if (seg[mid].beg<=x)
{
   low = mid+1;
}
else
{
   high = mid-1;
}
}
return low;
}

int main()
{
int i,j;
int a,b,c,x;
while (scanf("%d %d",&n,&m)!=EOF)
{
seg.clear();
memset(tree,0,sizeof(tree));
BuildTree(1,1,n);
char str[10];
segment edge;
while (m--)
{
   scanf("%s",str);
   if (str[0]=='R')
   {
    insert(1,n,1,0);
    seg.clear();
    puts("Reset Now");
   } 
   else if (str[0]=='N')
   {
    scanf("%d",&x);
    if (tree[1].tmax<x)
    {
     puts("Reject New");
    } 
    else
    {
     edge.beg = query(x,1);
     edge.end = edge.beg+x-1;
     int ans = Bsearch(edge.beg);
     seg.insert(seg.begin()+ans,edge);
     insert(edge.beg,edge.end,1,1);
     printf("New at %d\n",edge.beg);
    }
   } 
   else if (str[0]=='F')
   {
    scanf("%d",&x);
    int ans = Bsearch(x)-1;
    if (ans<=-1||seg[ans].end<x)
    {
     puts("Reject Free");
    } 
    else
    {
     insert(seg[ans].beg,seg[ans].end,1,0);
     printf("Free from %d to %d\n",seg[ans].beg,seg[ans].end);
     seg.erase(seg.begin()+ans,seg.begin()+ans+1);
    }
   } 
   else if (str[0]=='G')
   {
    scanf("%d",&x);
    if (x>seg.size())
    {
     puts("Reject Get");
    }
    else
    {
     printf("Get at %d\n",seg[x-1].beg);
    }
   }
}
puts("");
}
return 0;
}
