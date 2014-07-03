#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int P,B,N;

struct node
{
    int index,num;
}ep[1000000];

int cmp(const void *a, const void *b)
{
    node *c = (node *)a;
node *d = (node *)b;
if(c->num != d->num)
   return c->num > d->num ? 1 : -1;
else
   return c->index > d->index ? 1 : -1;
}//cmp(const void *a, const void *b)


int two_research(int goal, int len) // 进行二分查找，寻找 j
{
    int left = 0,right = len-1,mid;
while(left < right)
{
     mid = (left + right) >> 1;
   if(ep[mid].num < goal)
    left = mid + 1;
   else
    right = mid;
}
if(ep[left].num == goal)
   return ep[left].index;
else
   return -1;
}//two_research(int goal, int len)


int two_len(int x) // 计算二进制x的位数
{
    int len = 0;
while(x > 0)
{
     x = x >> 1;
   len++;
}
return len;
}//two_len(int x)


int flag(int x, int i) // 判断二进制x的第i位是否为1
{
    return x & (1 << (i-1));
}//flag(int x, int i)


int calc(int a, int x, int n) // 计算a^x (mod n)
{
    int i;
__int64 y = 1;
for(i = two_len(x);i > 0; i--)
{
     y = (y * y) % n;
   if(flag(x,i) > 0)
    y = (y * a) % n;
}
return y % n;
}//calc(int a, int x, int n)


int solve(int a, int b, int n)
{
    int i,j;
int m,am;
__int64 temp;
m = (int)ceil(sqrt((double)(n - 1))); // m = sqrt(n - 1)取上整
ep[0].index = 0; ep[0].num = 1; temp = 1;
for(i = 1;i < m;i++) // 将a^0 ~ a^m-1 存储到数组ep中
{
     temp = (temp*a)%n;
   ep[i].index = i;
   ep[i].num = temp;
}
qsort(ep,m,sizeof(ep[0]),cmp); //将数组ep进行排序，以便进行二分查找
    am = calc(a,n-2,n); //求a^(n-2) (mod n)
am = calc(am,m,n); //求am^m (mod n),以此求得 a^(-m)
temp = b;
for(i = 0;i < m;i++)
{
     j = two_research(temp,m); // 对每个i 查找是否存在满足条件的j;
   if(j != -1) return i * m + j;
   temp = (temp * am) % n;
}
return -1;

}//solve(int a, int b, int n)


int main()
{
    int result;
while(scanf("%d%d%d",&P,&B,&N)!=EOF)
{
     result = solve(B,N,P);
   if(result == -1)
    printf("no solution\n");
   else
    printf("%d\n",result);
}
return 0;
}
