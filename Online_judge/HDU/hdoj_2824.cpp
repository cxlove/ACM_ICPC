#include<iostream>
#include<cstdio>
#include<cmath>
#define LL long long
#define N 3000000
using namespace std;
LL a[N+5];
bool flag[N+5];
void Init(){
    for(int i=2;i<=N;i++)
        a[i]=i;
    for(int i=2;i<=N;i++)
        if(a[i]==i){
            a[i]=i-1;
            for(int j=2;j*i<=N;j++)
                a[i*j]=a[i*j]/i*(i-1);
        }
        for(int i=2;i<=N;i++)
            a[i]+=a[i-1];
}
int main(){
    Init();
    int A,B;
//    cout<<a[N]<<endl;
    while(scanf("%d%d",&A,&B)!=EOF)
        printf("%I64d\n",a[B]-a[A-1]);
    return 0;

}