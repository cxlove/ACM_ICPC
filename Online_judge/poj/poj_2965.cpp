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
int a[4][4];
char str[5][5];
int main(){
    for(int i=0;i<4;i++)
        cin>>str[i];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(str[i][j]=='+'){
                a[i][j]=!a[i][j];
                for(int k=0;k<4;k++){
                    a[i][k]=!a[i][k];
                    a[k][j]=!a[k][j];
                }
            }
        }
    }
    vector<pair<int,int> >v;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(a[i][j])
                v.pb(mp(i+1,j+1));
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;
    return 0;
}