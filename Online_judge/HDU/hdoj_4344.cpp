#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cstdlib>
#include<vector>
#define C    240
#define TIME 10
#define LL long long
using namespace std;
LL ans;
LL gcd(LL a, LL b){
    if(a==0) return 1;
    if(a<0) return gcd(-a,b);
    return b==0?a:gcd(b,a%b);
}
LL MultMod(LL a,LL b,LL n){
    a%=n;
    b%=n;
    LL ret=0;
    while(b){
        if(b&1){
            ret+=a;
            if(ret>=n) ret-=n;
        }
        a=a<<1;
        if(a>=n) a-=n;
        b=b>>1;
    }
    return ret;
}
LL PowMod(LL a,LL n,LL m){
    LL ret=1;
    a=a%m;
    while(n>=1){
        if(n&1)
            ret=MultMod(ret,a,m);
        a=MultMod(a,a,m);
        n=n>>1;
    }
    return ret;
}
bool Witness(LL a,LL n){
    LL t=0,u=n-1;
    while(!(u&1)){
        t++;
        u/=2;
    }
    LL x0=PowMod(a,u,n);
    for(int i=1;i<=t;i++){
        LL x1=MultMod(x0,x0,n);
        if(x1==1&&x0!=1&&x0!=(n-1))
            return true;
        x0=x1;
    }
    if(x0!=1)
        return true;
    return false;
}
bool Miller_Rabin(LL n,int t){
    if(n==2) return true;
    if((n&1)==0)  return false;
    srand(time(NULL));
    for(int i=0;i<t;i++){
        LL a=rand()%(n-1)+1;
        if(Witness(a,n))
            return false;
    }
    return true;
}
LL Pollard_Rho(LL n,LL c){
    LL i=1,x=rand()%n,y=x,k=2;
    while(1){
        i++;
        x=(MultMod(x,x,n)+c)%n;
        LL d=gcd(y-x,n);
        if(d!=1&&d!=n)
            return d;
        if(x==y)
            return n;
        if(i==k){
            y=x;
            k*=2;
        }
    }
}
struct Node{
    LL prime,cnt;
}tmp;
vector<Node>fac;
void get_fact(LL n,LL c){
    if(n==1) return;
    LL p=n;
//    cout<<n<<endl;
    while(p>=n) p=Pollard_Rho(p,c--);
    if(p==1){
        get_fact(n,c);
        return;
    }
    if(Miller_Rabin(p,TIME)){
        tmp.prime=p;
        tmp.cnt=0;
        while(n%p==0){
            n/=p;
            tmp.cnt++;
        }
        fac.push_back(tmp);
    }
    if(n!=1&&Miller_Rabin(n,TIME)){
        tmp.prime=n;
        tmp.cnt=1;
        fac.push_back(tmp);
        return ;
    }
    get_fact(n,c);
}
int main(){
    srand(time(NULL));
    LL n;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%I64d",&n);
        fac.clear();
        get_fact(n,C);
        if(fac.size()==1)
            printf("1 %I64d\n",n/fac[0].prime);
        else{
            printf("%d ",fac.size());
            LL sum=0;
            for(int i=0;i<fac.size();i++)
                sum+=PowMod(fac[i].prime,fac[i].cnt,n);
            printf("%I64d\n",sum);
        }
    }
    return 0;
}
