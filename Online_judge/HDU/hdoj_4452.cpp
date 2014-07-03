#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#define LL long long
#define MOD 31536000
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int way[4][2]={0,1,-1,0,0,-1,1,0};
int n;
int id(char ch)
{
    if(ch=='E') return 0;
    if(ch=='N') return 1;
    if(ch=='W') return 2;
    return 3;
}
int main()
{
    while(scanf("%d",&n)!=EOF&&n)
    {
        int d1,d2,x1=1,y1=1,x2=n,y2=n,s1,s2,t1,t2;
        char str[5];
        scanf("%s%d%d",str,&s1,&t1);d1=id(str[0]);
        scanf("%s%d%d",str,&s2,&t2);d2=id(str[0]);
        int q;
        scanf("%d",&q);
        for(int i=1;i<=q;i++)
        {
            x1+=s1*way[d1][0];y1+=s1*way[d1][1];
            if(x1>n){d1=(d1+2)%4;x1=2*n-x1;}
            if(x1<=0){d1=(d1+2)%4;x1=2-x1;}
            if(y1>n){d1=(d1+2)%4;y1=2*n-y1;}
            if(y1<=0){d1=(d1+2)%4;y1=2-y1;}
            x2+=s2*way[d2][0];y2+=s2*way[d2][1];
            if(x2>n){d2=(d2+2)%4;x2=2*n-x2;}
            if(x2<=0){d2=(d2+2)%4;x2=2-x2;}
            if(y2>n){d2=(d2+2)%4;y2=2*n-y2;}
            if(y2<=0){d2=(d2+2)%4;y2=2-y2;}
            if(x1==x2&&y1==y2){swap(d1,d2);}
            else
            {
                if(i%t1==0) d1=(d1+1)%4;
                if(i%t2==0) d2=(d2+1)%4;
            }
        }
        printf("%d %d\n%d %d\n",x1,y1,x2,y2);
    }
    return 0;
}