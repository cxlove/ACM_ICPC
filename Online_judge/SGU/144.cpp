#include <iostream>
#include <cstdio>
using namespace std;
int x,y,d;
double z;
int main(){
    cin>>x>>y>>z;
    d=(y-x)*60;
    printf("%.7f\n",1-(d-z)*(d-z)*1.0/d/d);
    return 0;
}
