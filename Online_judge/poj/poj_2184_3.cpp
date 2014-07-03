#include <iostream>  

 #include <cstdio>  

 using namespace std;  

   

 const int MAX = 100*1001*2;  

 const int N = 105;  

 const int INF = 1000000000;  

    

 int dp[MAX];  

    

 int s[N], f[N];  

 int n;  

    

 int main()  

 {  

     scanf("%d", &n);  

    

    for (int i = 1; i <= n; i++)  

         scanf("%d%d", &s[i], &f[i]);  

    

     for (int i = 0; i <= 200000; i++)  

         dp[i] = -INF;  

     dp[100000] = 0;  

    

     for (int i = 1; i <= n; i++)  

     {  

         if (s[i] < 0 && f[i] < 0)  

             continue;  

    

         if (s[i] > 0)  

         {  
             for (int v = 200000; v >= s[i]; v--)  

                 if (dp[v-s[i]] > -INF)  

                     dp[v] = max(dp[v], dp[v-s[i]] + f[i]);  

    

         }  

         else 

         {  

             for (int v = s[i]; v <= 200000+s[i]; v++)          

                 if (dp[v-s[i]] > -INF)  

                     dp[v] = max(dp[v], dp[v-s[i]] + f[i]);  

    

         }  

     }  

   

     int ans = 0;  

    for (int v = 100000; v <= 200000; v++)  

     {  

         if (dp[v] >= 0)        
             ans = max(ans, dp[v]+v-100000);   

     }  

    

     printf("%d\n", ans);  

     return 0;  

 } 

