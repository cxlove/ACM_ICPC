/*
ID:cxlove
Prob:E Electric Bill
Algorithm:binary search
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a,b;
int c[]= {200,29700,4950000};
int s[]= {200,29900,4979900};
int check(int s)
{
    int ans;
    if(s>1000000) ans=4979900+(s-1000000)*7;
    else if(s>10000) ans=29900+(s-10000)*5;
    else if(s>100) ans=200+(s-100)*3;
    else ans=s*2;
    return ans;
}
int main()
{
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        if(!a&&!b) break;
        int s=0;
        if(a>4979900) s+=(a-4979900)/7+1000000;
        else if(a>29900) s+=(a-29900)/5+10000;
        else if(a>200) s+=(a-200)/3+100;
        else s+=a/2;
        int low=0,high=s/2,mid,ans;
        while(low<=high)
        {
              mid=(low+high)>>1;
              int t=check(s-mid)-check(mid);
              if(t==b)
              {
                ans=check(mid);
                break;
              }
              else if(t<b)
              {
                high=mid-1;
              }
              else low=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
