#include<cstdio>
int main(){
    int a,b;
    while(scanf("%d%d",&a,&b) && a){
        if(!(a&1) || !(b&1)) printf("Wonderful!\n");
        else printf("What a pity!\n");
    }
    return 0;
}