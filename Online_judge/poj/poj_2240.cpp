#include<iostream>  
#include<cstdio>  
#include<cstring>   
using namespace std;  
char info[31][51];  
double f[31][31];  
int find(char s[51],int n)  
{  
    for(int i=1;i<=n;i++)  
       if(!strcmp(s,info[i]))   
         return i;  
}  
void floyd(int n){  
     for(int k=1;k<=n;k++)  
       for(int i=1;i<=n;i++)  
          for(int j=1;j<=n;j++)  
            if(f[i][k]!=0.0 && f[k][j]!=0.0 && f[i][j]<f[i][k]*f[k][j])  
               f[i][j]=f[i][k]*f[k][j];  
}  
int main(){  
    int n,c=1;  
    while(scanf("%d",&n),n){  
        for(int i=1;i<=n;i++)  
           scanf("%s",info[i]);  
        int m;  
        scanf("%d",&m);  
        char s1[51],s2[52];  
        double p;  
        for(int i=1;i<=n;i++)  
          for(int j=1;j<=n;j++)   
             f[i][j]=(i==j?1.0:0.0);  
        for(int i=0;i<m;i++){  
            scanf("%s%lf%s",s1,&p,s2);  
            int s=find(s1,n),t=find(s2,n);  
            f[s][t]=p;  
        }  
        floyd(n);  
        bool flag=0;  
        for(int i=1;i<=n;i++)  
          if(f[i][i]>1.0) {flag=1;break;}  
        if(flag) printf("Case %d: Yes\n",c++);  
        else printf("Case %d: No\n",c++);  
    }  
 return 0;  
}  
