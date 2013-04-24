#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int p[10];
int ok[256],mask[256];
vector<vector<int> >ans;
int main(){
    memset(p,-1,sizeof(p));
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int m;
        scanf("%d",&m);
        p[m]=i;
    }
    for(int i=0;i<256;i++){
        int t=i,bit[3],len=0;
        ok[i]=true;mask[i]=0;
        if(t==0){
            if(p[0]==-1) ok[i]=false;
            else mask[i]|=1<<p[0];
        }
        while(t){
            int m=t%10;
            if(p[m]==-1) ok[i]=false;
            else mask[i]|=1<<p[m];
            t/=10;
        }
    }
    for(int a=0;a<256;a++){
        if(ok[a]==false) continue;
        for(int b=0;b<256;b++){
            if(ok[b]==false) continue;
            for(int c=0;c<256;c++){
                if(ok[c]==false) continue;
                if((mask[a]|mask[b]|mask[c])!=(1<<n)-1) continue;
                for(int d=0;d<256;d++){
                    int t1=a,t2=b,t3=c,t4=d,bit[15],len=0; 
                    if(t1==0) bit[len++]=0; else while(t1) bit[len++]=t1%10,t1/=10;
                    if(t2==0) bit[len++]=0; else while(t2) bit[len++]=t2%10,t2/=10;
                    if(t3==0) bit[len++]=0; else while(t3) bit[len++]=t3%10,t3/=10;
                    if(t4==0) bit[len++]=0; else while(t4) bit[len++]=t4%10,t4/=10;
                    bool flag=true;
                    for(int i=0;i<len/2;i++)
                        if(bit[i]!=bit[len-1-i])
                            flag=false;
                    if(flag){
                        //for(int i=0;i<len;i++) cout<<bit[i];cout<<endl;
                        vector<int>ip;
                        ip.push_back(d);
                        ip.push_back(c);
                        ip.push_back(b);
                        ip.push_back(a);
                        ans.push_back(ip);
                    }
                }
            }
        }
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d.%d.%d.%d\n",ans[i][0],ans[i][1],ans[i][2],ans[i][3]);
    return 0;
}