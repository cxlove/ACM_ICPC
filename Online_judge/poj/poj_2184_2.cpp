#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

const int MID = 100000, INF = 99999999;
int dp[MID * 2 + 3];
int n;
bool flg[MID * 2 + 3];

int main()
{
 int l, r, i, j, k, s, f, best;

 //scanf ("%d", &n);
 while ( scanf ("%d", &n) != EOF )
 {
  //init
  memset(flg, false, sizeof(flg));
  for (i = 1; i <= MID*2; i++)
   dp[i] = -INF;
  dp[MID] = 0;
  flg[MID] = true;
  l = r = 0;

  for (i = 1; i <= n; i++)
  {
   scanf ("%d %d", &s, &f);
   if (s <= 0 && f <= 0 ) continue;
   if (s < 0)
   {
    for (j = l; j <= r; j++)
    {
     if (flg[j+MID] && dp[j+MID+s] < dp[j+MID] + f)
     {
      dp[j+MID+s] = dp[j+MID] + f;
      flg[j+MID+s] = true;
     }
    }
   l += s;
   }
   else
   {
    for (j = r; j >= l; j--)
    {
     if (flg[j+MID] && dp[j+MID+s] < dp[j+MID] + f)
     {
      dp[j+MID+s] = dp[j+MID] + f;
      flg[j+MID+s] = 1;
     }
    }
    r += s;
   }
  }
  best = 0;
  for (i = 0; i <= r; i++)
  {
   if (flg[i+MID] && dp[i+MID] > 0 && i + dp[i+MID] > best)
    best = i + dp[i+MID];
  }

  printf ("%d\n", best);
 }
 return 0;
}