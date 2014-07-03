#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
LL extend_gcd(LL a,LL b, LL &x,LL &y){
    if(b==0){x=1;y=0;return a;}
    LL gcd=extend_gcd(b,a%b,x,y);
    LL t=x;
    x=y;
    y=t-a/b*y;
    return gcd;
}
int main(){
    int t;
    LL a[11],r[11],a1,a2,r1,r2,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%I64d%I64d",&n,&m);
        for(int i=0;i<m;i++)
            scanf("%I64d",&a[i]);
        for(int i=0;i<m;i++)
            scanf("%I64d",&r[i]);
        a1=a[0];r1=r[0];
        bool flag=false;
        for(int i=1;i<m;i++){
            a2=a[i];r2=r[i];
            LL x,y,t;
            LL gcd=extend_gcd(a1,a2,x,y);
            if((r2-r1)%gcd!=0)
                flag=true;
            if(flag)
                break;
            t=a2/gcd;
            if(t<0) t=-t;
            x=(x*(r2-r1))/gcd;
            x=(x%t+t)%t;
            r1=a1*x+r1;
            a1=(a1*a2)/gcd;
        }
        if(flag||r1>n)
            printf("0\n");
        else{
            if(r1==0) r1=a1;
            LL ans=(n-r1)/a1+1;
            printf("%I64d\n",ans);
        }

    }return 0;
}