#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#define LL long long
using namespace std;
LL ans1,ans2;
LL t,a,b,n;
vector<int>aa;
void dfs(bool kind,int idx,LL num){
    if(idx==aa.size()){
        if(kind){
            ans1-=a/num;
            ans2-=b/num;
        }
        else{
            ans1+=a/num;
            ans2+=b/num;
        }
        return;
    }
    dfs(!kind,idx+1,num*aa[idx]);
    dfs(kind,idx+1,num);
}
int main(){
    scanf("%I64d",&t);
    for(LL tt=1;tt<=t;tt++){
        scanf("%I64d%I64d%I64d",&a,&b,&n);
        a--;
        aa.clear();
        LL k=n;
        for(int i=2;i<=sqrt(k*1.0);i++){  
            if(n%i==0){  
                while(n%i==0) n=n/i;  
                aa.push_back(i);  
            }  
        }  
        if(n!=1)
            aa.push_back(n);
        ans1=ans2=0;
        dfs(0,0,1);
        printf("Case #%I64d: %I64d\n",tt,ans2-ans1);
    }
    return 0;

}