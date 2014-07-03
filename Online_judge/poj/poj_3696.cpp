#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define N 100005
#define maxn 200005
#define LL long long
#define pb(a) push_back(a) 
using namespace std;
bool flag[N]={0};
int cnt=0,prime[N];
LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
}
void Prime(){
	for(int i=2;i<N;i++){
		if(flag[i]) continue;
		prime[cnt++]=i;
		for(int j=2;j*i<N;j++)
			flag[i*j]=true;
	}
}
LL get_eular(LL n){
	LL ret=1;
	for(int i=0;i<cnt&&prime[i]*prime[i]<=n;i++){
		if(n%prime[i]==0){
			ret*=prime[i]-1;
			n/=prime[i];
			while(n%prime[i]==0){
				n/=prime[i];
				ret*=prime[i];
			}
		}
	}
	if(n>1) ret*=n-1;
	return ret;
}
LL fac[N][2],tot;
void Split(LL n){
	tot=0;
	for(int i=0;i<cnt&&prime[i]*prime[i]<=n;i++){
		if(n%prime[i]==0){
			fac[tot][0]=prime[i];
			fac[tot][1]=0;
			while(n%prime[i]==0){
				n/=prime[i];
				fac[tot][1]++;
			}
			tot++;
		}
	}
	if(n>1){fac[tot][0]=n;fac[tot++][1]=1;}
}
vector<LL>fact;
void dfs(int idx,LL num){
	if(idx>=tot){
		fact.pb(num);
		return;
	}
	LL tmp=1;
	for(int i=0;i<=fac[idx][1];i++,tmp*=fac[idx][0])
		dfs(idx+1,num*tmp);
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
LL PowMod(LL a,LL b,LL MOD){
	LL ret=1;
	while(b){
		if(b&1) ret=MultMod(ret,a,MOD);
		a=MultMod(a,a,MOD);
		b>>=1;
	}
	return ret;
}
int main(){
	LL n;
	int cas=0;
	Prime();
	while(scanf("%I64d",&n)!=EOF&&n){
		LL p=(LL)9*n/gcd(8,n);
		printf("Case %d: ",++cas);
		if(gcd(10,p)!=1){
			printf("0\n");
			continue;
		}
		LL phi=get_eular(p);
		Split(phi);
		//cout<<phi<<endl;
		fact.clear();
		dfs(0,1);
		sort(fact.begin(),fact.end());
	//	for(int i=0;i<fact.size();i++) printf("%I64d\n",fact[i]);
		for(int i=0;i<fact.size();i++){
		//	cout<<fact[i]<<" "<<PowMod(10,fact[i],p)<<endl;
			if(PowMod(10,fact[i],p)==1){
				printf("%I64d\n",fact[i]);
				break;
			}
		}
	}
	return 0;
}
