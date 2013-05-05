#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 5005;
char s[N],e[N];
int main(){
    cin>>s>>e;
    int ans=0;
    for(int i=0;s[i];i++){
        if(s[i]==e[i]) continue;
        int j=i+1;
        for(;s[j];j++)
            if(s[j]!=s[i])
                break;
        if(s[j]=='\0'){
            puts("-1");
            return 0;
        }
        for(j--;j>=i;j--,ans++)
            swap(s[j],s[j+1]);
    }
    cout<<ans<<endl;
    return 0;
}
