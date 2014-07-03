#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>

using namespace std;
int main(){
    int n;
    string a[15],b[15],str;
    while(cin>>n){
                  getchar();
        if(n==0) break;
        for(int i=0;i<n;i++){
            getline(cin,a[i]);
            getline(cin,b[i]);
        }
        getline(cin,str);
        for(int i=0;i<n;i++){
            int pos;
            while((pos=str.find(a[i]))!=string::npos){
                 str.erase(str.begin()+pos,str.begin()+pos+a[i].size());
                 str.insert(pos,b[i]);
            }
        }
        cout<<str<<endl;;
    }
    return 0;
}
