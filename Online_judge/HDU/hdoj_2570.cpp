#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    int t,n,v,w;
    int a[105];
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&v,&w);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        int ans=v,sum=a[0]*v;
        if(a[0]>w){
            printf("0 0.00\n");
            continue;
        }
        for(int i=1;i<n;i++){
            if((sum+a[i]*v+0.0)/(ans+v)>w)
                break;
            sum+=a[i]*v;
            ans+=v;
        }
        printf("%d %.2f\n",ans,sum/100.0/ans);
    }
    return 0;
}