#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<map>
#include<string>
#define inf 1<<30
#define eps 1e-7
#define LD long double
#define LL long long
#define maxn 1005
using namespace std;
int n,len[8];
int depth;
bool flag;
char dna[8][6];
int get_h(int *l){
    int ans=0;
    for(int i=0;i<n;i++)
        ans=max(ans,l[i]);
    return ans;
}
bool check(int *l,int state){
    int ch=0;
    for(int i=0;i<n;i++)
        if(((1<<i)&state)==0)
            continue;
        else if(l[i]==0)
            return false;
        else if(ch==0||(int)dna[i][len[i]-l[i]]==ch)
            ch=(int)dna[i][len[i]-l[i]];
        else 
            return false;
    return true;
}
void IDAstar(int *l,int tmp_depth){
    if(flag)
        return;
    if(get_h(l)>tmp_depth)
        return;
    if(tmp_depth==0){
        flag=true;
        return;
    }
    bool mark[8];    
    memset(mark,false,sizeof(mark));
    for(int i=0;i<n;i++)
        if(mark[i]==false&&l[i]){
            int tmp[8];
            for(int j=0;j<n;j++)
                tmp[j]=l[j];
            mark[i]=true;
            char ch=dna[i][len[i]-l[i]];
            tmp[i]--;
            for(int j=i+1;j<n;j++)
                if(!mark[j]&&dna[j][len[j]-l[j]]==ch&&l[j]){
                    mark[j]=true;
                    tmp[j]--;
                }
            IDAstar(tmp,tmp_depth-1);
        }
    /*for(int i=1;i<(1<<n);i++)
        if(check(l,i)){
            int tmp[8];
            for(int i=0;i<8;i++)
                tmp[i]=l[i];
            for(int j=0;j<n;j++)
                if(i&(1<<j))
                    tmp[j]--;
            IDAstar(tmp,tmp_depth-1);
        }*/
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int low=0;
        for(int i=0;i<n;i++){
            scanf("%s",dna[i]);
            len[i]=strlen(dna[i]);
            low=max(low,len[i]);
        }
        flag=false;
        for(depth=low;;depth++){
        
            IDAstar(len,depth);
            if(flag){
                printf("%d\n",depth);
                break;
            }
        }
    }
    return 0;
}