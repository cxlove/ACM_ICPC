#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<vector>
#define C    240
#define TIME 10
#define eps 1e-7
#define inf 1<<25
#define LL unsigned long long
using namespace std;
string a,b;
bool check(){
    string tmp=a;
    for(int i=0;i<26;i++){
        swap(tmp[0],tmp[1]);
        if(tmp[0]=='z')  tmp[0]='a';
        else tmp[0]++;
        if(tmp[1]=='z')  tmp[1]='a';
        else tmp[1]++;
        if(tmp[0]==b[0]&&tmp[1]==b[1])
           return true;
    }
    return false;
}
string change(string k) {  
    char tmp;  
    tmp = k[1];  
    k[1] = k[0];  
    k[0] = tmp;  
    k[1]++;  
    k[0]++;  
    if(k[0] == 'z' + 1) k[0] = 'a';  
    if(k[1] == 'z' + 1) k[1] = 'a';  
    return k;  
}  
  
void output() {  
    string tmp = a;  
    //cout << "here1" << endl;  
    tmp = change(tmp);  
    //cout << "here3" << endl;  
    if(tmp == b) { cout << "YES" << endl; return ;}  
    while(tmp != a) {  
        tmp = change(tmp);  
        //cout << "here2" << endl;  
        if(tmp == b) { cout << "YES" << endl; return ;}  
    }  
    cout << "NO" << endl;  
    return ;  
}  
  
  
int main(){
    int t,cas=0;
    cin>>t;
    while(t--){
        cin>>a>>b;
       //  cout<<"Case #"<<++cas<<": ";
       printf("Case #%d: ",++cas);
        int l=a.size(),s=0;
        for(int i=0;i<l;i++)
            s+=abs(a[i]-b[i]);
        if(l==2){
            if(check())
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else{
            if(s&1)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }
    }
    return 0;
}





