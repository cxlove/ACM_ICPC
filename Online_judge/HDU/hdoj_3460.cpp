#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string w[10000];
int get(string a,string b){
    int i;
    for(i=0; i<a.length() && i<b.length() && a[i]==b[i]; i++);
    return a.length()-i+b.length()-i;
}
int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        int i;
        for(i=0; i<n; i++)
            cin>>w[i];
        sort(w,w+n);
        int sum=w[0].length()+1;
        int MAX=w[0].length();
        for(i=1; i<n; i++){
            sum+= get(w[i],w[i-1])+1;
            if(w[i].length()>MAX)
                MAX=w[i].length();
        }
        printf("%d\n",sum+w[n-1].length()-MAX);
    }
    return 0;
}