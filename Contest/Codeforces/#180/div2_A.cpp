#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#define LL long long
#define lowbit(i) (i&(-i))
using namespace std;
const int N = 1005;
char str[N];
int main(){
    int n;
    scanf("%d%s",&n,str);
    int l=0,r=0;
    int s=n,e=0,lastr=0;
    for(int i=0;i<n;i++){
        if(str[i]=='L'){
            l++,s=min(s,i+1),e=max(e,i+1);
            if(lastr==0)
                lastr=i;
        }
        else if(str[i]=='R')
            r++,s=min(s,i+1),e=max(e,i+1);
    }
    if(r==0) cout<<e<<" "<<s-1<<endl;
    else if(l==0) cout<<s<<" "<<e+1<<endl;
    else cout<<s<<" "<<lastr<<endl;
    return 0;

}