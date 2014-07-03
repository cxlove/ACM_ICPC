#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
int main(){
    int n;
    string word;
    map<string,int> mmap;
    while(scanf("%d",&n)&&n){
        mmap.clear();
        for(int i=0;i<n;i++){
            cin>>word;
            mmap[word]++;
        }
        int mmax=0;
        string ans;
        for(map<string,int>::iterator it=mmap.begin();it!=mmap.end();it++)
            if(it->second>mmax){
                 ans=it->first;
                 mmax=it->second;
            }
        cout<<ans<<endl;
    }
    return 0;
}
    
