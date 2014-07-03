#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>
#define LL  long long
#define MOD 29
#define eps 1e-6
#define N 100010
#define zero(a)  fabs(a)<eps
using namespace std;
int n,val[105];
int c1[20005],c2[20005];
vector<int>v;
int main(){
    while(scanf("%d",&n)!=EOF){
        int sum=0;
        for(int i=0;i<n;i++){
            scanf("%d",&val[i]);
            sum+=val[i];
        }
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(int i=-val[0];i<=val[0];i+=val[0])
            c1[i+sum]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum*2;j++)
                for(int k=-val[i];k<=val[i]&&j+k>=0&&j+k<=sum*2;k+=val[i])
                    c2[j+k]+=c1[j];
            for(int j=0;j<=2*sum;j++){
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        v.clear();
        for(int i=sum+1;i<=2*sum;i++)
            if(!c1[i])
                v.push_back(i-sum);
        printf("%d\n",v.size());
        if(v.size()){
            for(int i=0;i<v.size()-1;i++)
                 printf("%d ",v[i]);
            printf("%d\n",v[v.size()-1]);
        }
    }
    return 0;
}