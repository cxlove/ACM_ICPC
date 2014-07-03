#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define N 1000005
using namespace std;
char str[N];
int next[N];
void get_next(char *s,int len){
    next[0]=-1;
    int i=0,j=-1;
    while(i<len){
        if(j==-1||s[i]==s[j]){
            i++;j++;
            if(s[i]==s[j])next[i]=next[j];
            else next[i]=j;
        }
        else j=next[j];
    }
}
int min_max_express(char *s,int len,bool flag){
    int i=0,j=1,k=0;
    while(i<len&&j<len&&k<len){
        int t=s[(j+k)%len]-s[(i+k)%len];
        if(t==0) k++;
        else{
            if(flag){
                if(t>0) j+=k+1;
                else i+=k+1;
            }
            else{
                if(t>0) i+=k+1;
                else j+=k+1;
            }
            if(i==j) j++;
            k=0;
        }
    }
    return min(i,j);
}
int main(){
    while(scanf("%s",&str)!=EOF){
        int len=strlen(str);
        int min_express=min_max_express(str,len,true);
        int max_express=min_max_express(str,len,false);
        get_next(str,len);
        int l=len-next[len];
        int ans=len%l?1:len/l;
        printf("%d %d %d %d\n",min_express+1,ans,max_express+1,ans);
    }
    return 0;
}
