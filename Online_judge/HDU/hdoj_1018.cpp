#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
    int t;
    double n;
    const double PI=3.1415926;
    double sum;
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=(log(sqrt(2*PI*n))+n*log(n)-n)/log(10.0);
        sum++;
        printf("%d\n",int(sum));
    }return 0;
}
