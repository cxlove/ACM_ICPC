#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#define inf 110000000
#define M 10005
#define N 10005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define MOD 1000000007
using namespace std;
int init[24],goal[24];
int a[8]={0,1,2,7,16,21,22,23};
int b[16]={3,4,5,6,8,9,10,11,12,13,14,15,17,18,19,20};
int gao(int b){
    if(b==0||b==2) return 3;
    if(b==1||b==7) return 6;
    if(b==16||b==22) return 17;
    else return 20;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<24;i++)
            scanf("%d",&init[i]);
        for(int i=0;i<8;i++)
            if(init[a[i]]==0)
                swap(init[a[i]],init[gao(a[i])]);
        for(int i=0;i<24;i++)
            scanf("%d",&goal[i]);
        for(int i=0;i<8;i++)
            if(goal[a[i]]==0)
                swap(goal[a[i]],goal[gao(a[i])]);
        bool ans=true;
        for(int i=0;i<8&&ans;i++){
        //    cout<<init[a[i]]<<" "<<goal[a[i]]<<endl;
            if(init[a[i]]!=goal[a[i]])
                ans=false;
        }
        if(!ans){puts("Y");continue;}
        int cnt1=0,cnt2=0,pos1=0,pos2=0;
        for(int i=1;i<16;i++){
            if(init[b[i]]==0){pos1=i;continue;}
            for(int j=0;j<i;j++)
                if(init[b[j]]>init[b[i]])
                   cnt1++;
        }
        for(int i=1;i<16;i++){
            if(goal[b[i]]==0){pos2=i;continue;}
            for(int j=0;j<i;j++)
                if(goal[b[j]]>goal[b[i]])
                   cnt2++;
        }
        if((abs(pos1/4-pos2/4)+cnt1-cnt2)%2==0) puts("N");
        else puts("Y");
    }
    return 0;
}


