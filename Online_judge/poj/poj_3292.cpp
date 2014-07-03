#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1000005;
int a[N],c[N]={0};
void Init(){
    for(int i=5;i<N;i+=4){
        a[i]=1;
        for(int j=5;j*j<=i;j+=4){
            if(i%j==0){
                a[i]=j;
                break;
            }
        }
    }
    for(int i=5;i<N;i+=4){
        c[i]=c[i-4];
        if(a[i]!=1&&a[i/a[i]]==1)
            c[i]++;
    }
}
int main(){
    int n;
    Init();
    while(cin>>n&&n)
        cout<<n<<" "<<c[n]<<endl;
    return 0;
}