#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char str[120000];
char word[250000];
int p[250000];
int main(){
    while(scanf("%s",str)!=EOF){
        int len=strlen(str);
        word[0]='%';
        for(int i=0;i<len;i++){
            word[2*i+1]='#';
            word[2*i+2]=str[i];            
        }
        word[2*len+1]='#';
        int mx=0,id=0;
        for(int i=1;i<=len*2;i++){
            if(mx>i)
                p[i]=min(p[2*id-i],mx-i);
            else
                p[i]=1;
            for(;word[i+p[i]]==word[i-p[i]];p[i]++) ;
            if(p[i]+i>mx){
                mx=p[i]+i;
                id=i;
            }
        }
        int ans=0;
        for(int i=1;i<=2*len;i++){
            if(p[i]-1>ans)
                ans=p[i]-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
