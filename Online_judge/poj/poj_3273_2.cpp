#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,val[100005];
int main(){
    scanf("%d%d",&n,&m);
    int low=0,high=0;
    for(int i=0;i<n;i++){
        scanf("%d",&val[i]);
        low=max(low,val[i]);
        high+=val[i];
    }
    while(low<high){
        int mid=(high+low)/2;
        int sum=0,cnt=1;
        for(int i=0;i<n;i++){
            sum+=val[i];
            if(sum>mid){
                        sum=val[i];
                        cnt++;
            }
        }
        if(cnt<=m) high=mid-1;
        else   low=mid+1;
    }
    printf("%d\n",low);
    return 0;
   }
    
    
    
