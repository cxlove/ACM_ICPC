#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>
#define LL long long 
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
using namespace std;
int a[12];
int main(){
    int s,d;
    while(cin>>s>>d){
        int cnt;
        if(4*s-d<0) cnt=4;
        else if(3*s-2*d<0) cnt=3;
        else if(2*s-3*d<0) cnt=2;
        else if(s-4*d<0) cnt=1;
        else cnt=0;
        if(cnt==0){
            puts("Deficit");
            continue;
        }
        for(int i=0;i<cnt;i++)
            a[i]=s;
        for(int i=cnt;i<5;i++)
            a[i]=-d;
        for(int i=5;i<12;i++){
            int c=0;
            for(int j=i-4;j<i;j++)
                if(a[j]==s)
                    c++;
            if(c==cnt) a[i]=-d;
            else a[i]=s;
        }
        int sum=0;
        for(int i=0;i<12;i++)
            sum+=a[i];
        if(sum<0) puts("Deficit");
        else printf("%d\n",sum);
    }
    return 0;
}