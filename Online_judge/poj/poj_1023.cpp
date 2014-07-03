#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#define LL long long 
int main(){
    LL k,n,t;
    char str[100];
    std::cin>>t;
    while(t--){
        std::cin>>k>>str>>n;
        std::string s="";
        for(int i=0;i<k;i++){
            if(n&1){
                LL temp=n;
                n/=2;
                if(str[k-1-i]=='p'){
                    if(temp<0) n--;
                }
                else{
                    if(temp>0) n++;
                }
                s+="1";
            }
            else n/=2,s+="0";
        }
        reverse(s.begin(),s.end());
        if(n==0) std::cout<<s<<std::endl;
        else std::cout<<"Impossible"<<std::endl;
    }
    return 0;
}