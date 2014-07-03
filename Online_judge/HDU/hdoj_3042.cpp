#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define inf 1<<26
using namespace std;
int n,k,q,ans;
int slove(int pos,int temp){
    if(temp==n)
        return pos;
    if(pos%2==0)
        return temp/2+pos/2;
    slove(pos/2+1,temp/2);
}
int main(){    
    while(scanf("%d%d%d",&n,&k,&q)!=EOF){
        while(q--){
            int pos,t=1,temp;
            scanf("%d",&pos);
            for(temp=n;temp<k;temp+=temp);
            if(temp==k)
                ans=slove(pos,temp);
            else{
                temp/=2;
                if(pos<=(k-temp)*2)
                    ans=slove(pos,temp*2);
                else
                    ans=slove(pos-(k-temp),temp);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

    