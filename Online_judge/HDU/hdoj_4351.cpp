#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<vector>
#define C    240
#define TIME 10
#define eps 1e-7
#define inf 1<<25
#define LL unsigned long long
using namespace std;
int change(int num){
    if(num<10)
       return num;
    int sum=0;
    while(num){
        sum+=num%10;
        num/=10;
    }
    return change(sum);
}
int main(){
    int t,n,a[100005],cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(cas)
           puts("");
        for(int i=1;i<=n;i++){
           scanf("%d",&a[i]);
           a[i]=change(a[i]);
        }
        int q,l,r;
        scanf("%d",&q);
        printf("Case #%d:\n",++cas);
        while(q--){
            scanf("%d%d",&l,&r);
            bool flag[10],ok=false;
            memset(flag,false,sizeof(flag));
            for(int i=l;i<=r;i++){
                int sum=0;
                for(int j=i;j<=r;j++){
                    sum=change(sum+a[j]);
                    flag[sum]=true;
                    if(flag[5]&&flag[6]&&flag[7]&&flag[8]&&flag[9]){
                        ok=true;
                        break;
                    }
                }
                if(ok)
                   break;
            }
            if(ok)
               printf("9 8 7 6 5\n");
            else{
                int cnt=0;
                for(int i=9;i>=0&&cnt<5;i--)
                    if(flag[i]){
                        cnt++;
                        printf("%d",i);
                        if(cnt!=5)
                            printf(" ");
                    }
                for(int i=cnt+1;i<=5;i++){
                    printf("-1");
                    if(i!=5)
                       printf(" ");
                }
                printf("\n");
            }
        }
    }
    return 0;
}




