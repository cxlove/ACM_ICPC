/*
ID:cxlove
DATA:2012.3.17
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int N,K,P;
int a[50005];
int b[100005];
int main(){
scanf("%d%d%d",&N,&K,&P);
int i;
for(i=1;i<=K;i++)
   b[i]=i;
int m=K/N;
int num=1;
int j=0;
int k=0;
for(i=2;j<m;i++){
   if(b[i]){
    k++;
    if(k==P+1){
     num++;
     k=0;
     if(num==N){
      a[j++]=b[i];
      b[i]=0;
      num=0;
     }
     b[i]=0;
    }
   }
   if(i==K)
    i=1;
}
sort(a,a+m);
for(i=0;i<m;i++)
   printf("%d\n",a[i]);
return 0;
}
