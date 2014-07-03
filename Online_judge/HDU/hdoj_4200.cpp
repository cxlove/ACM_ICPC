#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,d;
int a[105][105],cnt,ttt[105];
int ta[105][105],x[105],ans[105],var0;  
vector<int>aa;
void debug(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}
void dfs(int v){  
    if(v>n){  
        int temp=0;  
        for(int i=1;i<=n;i++)  
            x[i]=ans[i];  
        for(int i=1;i<=n;i++)  
            for(int j=1;j<=n+1;j++)  
                ta[i][j]=a[i][j];          
        for(int i=var0-1;i>=1;i--){  
            for(int j=i+1;j<=n;j++)  
                ta[i][n+1]^=(x[j]&&ta[i][j]);  
            x[i]=ta[i][n+1];  
        }  
        for(int i=1;i<=n;i++)  
            if(x[i])  
                temp++;  
        if(temp<cnt){
            for(int i=1;i<=n;i++)
                ttt[i]=x[i];
            cnt=temp;
        }
        return ;  
    }  
    ans[v]=0;  
    dfs(v+1);  
    ans[v]=1;  
    dfs(v+1);  
}  
void gauss(){  
    int i,j,jj;  
    for(i=1,j=1,jj=1;i<=n&&jj<=n;jj++){ 
        int k=i;  
        for(;k<=n;k++)  
            if(a[k][j])  
                break;  
        if(a[k][j]){  
            for(int r=1;r<=n+1;r++)  
                swap(a[i][r],a[k][r]);  
            for(k=1;k<=n;k++)  
                if(k!=i&&a[k][j]){  
                    for(int r=1;r<=n+1;r++)  
                        a[k][r]^=a[i][r];  
                }  
                i++;  j++;
        } 
        else{
            int val=n-jj+j;
            for(int cow=1;cow<=n;cow++)
                swap(a[cow][j],a[cow][val]);
        }
    }  
    //debug();
    if(i==n+1){  
        cnt=0;  
        for(int r=1;r<=n;r++)  
            if(a[r][n+1])  
                cnt++;  
        printf("%d\n",cnt);  
        return ;  
    } 
    if(i<=n){
        for(int r=i;r<=n;r++)
            if(a[r][n+1]){
                printf("impossible\n");
                return ;
            }
    }
    var0=i;  
    cnt=1<<30;  
    dfs(i);      
    printf("%d\n",cnt);  
}  
int main(){
    int t;
//    freopen("D.in","r",stdin);
//    freopen("test.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&d);
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i][n+1]);
        for(int i=1;i<=n;i++)
            for(int j=Max(1,i-d);j<=Min(n,i+d);j++)
                a[i][j]=1;
        gauss();
    }
    return 0;
}