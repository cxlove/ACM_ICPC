/*
a1,a2,a3,a4,……,an
(t*(a1+1)*a2*a3……*an)-(s*a1*a2……*an)=1
a2*a3*a4……*(t*(a1+1)-s*a1)=1
a2=a3=a4=……an=1
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==1) cout<<8<<endl;
    else{
        int ans=1; //111……1 
        if((n-1)%3==0) ans+=2;  //11111……2   11111……5  
        if((n-1)%6==0) ans++;   //11111……6  
        cout<<ans<<endl;
    }
    return 0;
}
