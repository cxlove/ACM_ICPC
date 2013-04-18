#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#define LL long long
#define Key_value ch[ch[root][1]][0]  
using namespace std;
int n,k;
LL ip[100005];
set<LL>s;
void print(LL n){
    LL t=(1<<8)-1;
    //cout<<n<<endl;
    printf("%I64d.%I64d.%I64d.%I64d\n",(n>>24)&t,(n>>16)&t,(n>>8)&t,n&t);
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        int a,b,c,d;
        char str[100];
        scanf("%s",str);
        sscanf(str,"%d.%d.%d.%d",&a,&b,&c,&d);
        ip[i]=((LL)a<<24)+((LL)b<<16)+((LL)c<<8)+d;
    }
    for(int i=31;i>=0;i--){
        LL t=(1LL<<32)-(1LL<<i);
        s.clear();
        for(int j=0;j<n;j++){
            s.insert(t&ip[j]);
        }
        //cout<<s.size()<<endl;
        if(s.size()==k){
            print(t);
            return 0;
        }
    }
    puts("-1");
    return 0;
}