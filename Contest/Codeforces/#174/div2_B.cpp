#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<ctime>
using namespace std;
int main() {
    int A=0, F=0, I=0;
    int n;
    scanf("%d", &n);
    scanf("\n");
    for(int i=0; i<n; ++i){
        char c;
        scanf("%c", &c);
        if(c=='A'){
            A++;
        }else if(c=='F'){
            F++;
        }else {
            I++;
        };
    }
    if(I>1){
        printf("0\n");
    }
    else if(I==1){
        printf("1\n");
    }
    else printf("%d\n", A);
    return 0;
}