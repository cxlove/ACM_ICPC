#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
using namespace std;
map<int,int>m;
int ch[30]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
int que[5005];
int main(){
    int t,a,b;
    char str[10];
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        for(int i=0;i<a;i++) scanf("%d",&que[i]);
        m.clear();
        for(int i=0;i<b;i++){
            scanf("%s",str);
            int tmp=0;
            for(int j=0;j<strlen(str);j++)
                tmp=tmp*10+ch[str[j]-'a'];
            m[tmp]++;
        }
        for(int i=0;i<a;i++){
            if(m.find(que[i])==m.end()) printf("0\n");
            else printf("%d\n",m[que[i]]);
        }
    }
    return 0;
}
