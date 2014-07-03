#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N = 16;
const int M = 101;
const int MAX = 1000000000;
char op[5] = "+-.";
char ans[N];
int n;
int cnt = 0;
void print()
{
   for(int i = 1; i < n; i++)
   {
      printf("%d %c ",i,ans[i]);
   }
   printf("%d\n",n);
}
int cal()
{
   int sum = 1;
   int a,b;
   for(int i = 1; i < n;)
   {
      if(ans[i] == '+')
      {
         if(ans[i+1] != '.')
         {
            sum += i+1;
         }
         i++;
      }
      else if(ans[i] == '-')
      {
         if(ans[i+1] != '.')
         {
            sum -= i+1;
         }
         i++;
      }
      else
      {
         b = i;
         a = i;
         while(i<n && ans[i] == '.')
         {
            a = a*(i+1>=10 ? 100 : 10)+i+1;
            i++;
         }
         if(b>1)
         {
            if(ans[b-1] == '+')sum+=a;
            else sum -= a;
         }
         else
         {
            sum = a;
         }
      }
   }
   return sum;
}
void dfs(int t)
{
   if(t >= n)
   {
      if(cal() == 0)
      {
         cnt++;
         if(cnt <= 20)print();
      }
   }
   else
   {
      for(int i = 0; i < 3; i++)
      {
         ans[t] = op[i];
         dfs(t+1);
      }
   }
}
int main()
{
   scanf("%d",&n);
   dfs(1);
   printf("%d\n",cnt);
   return 0;
}