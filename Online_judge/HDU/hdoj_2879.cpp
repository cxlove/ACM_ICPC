#include <iostream>

#include <cstdio>

#include <cstring>

#include <string>

#include <queue>

#include <map>

#include <set>

#include <vector>

#include <cmath>

#include <cstdlib>

#include <algorithm>

using namespace std;

 

const int N = 10000000;

int p[700200], cnt;

bool hash[10000000];

 

void Get_Prime(){

hash[1] = true;

for (int i = 2; i*i <= N; ++ i){

if (!hash[i]){

for (int j = i*i; j <= N; j += i)

hash[j] = true;

}

}

for (int i = 2; i <= N; ++ i) if (!hash[i]) p[cnt ++] = i;

}

 

int main (){

int i,j,cnt=0;

p[cnt++]=2;

for(i=3;i<10000000;i+=2)

{

if(!hash[i])

{

p[cnt++]=i;

if(i<3200)

for(j=i*i;j<10000000;j+=i)hash[j]=1;

}

}

int Cas, n, t;

scanf ("%d", &Cas);

while (Cas --){

scanf ("%d%d",&n,&t);

long long tmp=0,ans=1,kk=2;

for(i=0;i<cnt&&p[i]<=n;++i)tmp+=n/p[i];

while(tmp){

if(tmp&1) ans=(ans*kk)%t;

kk=(kk*kk)%t; 

tmp>>=1;

}

printf("%lld\n",ans);

}

return 0;

}