#include<iostream>
#include<string>
#include<math.h>
#define maxn 16
const int wx[5]={1,0,-1,0,0};
const int wy[5]={0,1,0,-1,0};
using namespace std;
struct gauss{
    int cnt,n,a[maxn*maxn][maxn*maxn+1],num[maxn][maxn];
    void init(){
        cin>>n;
        memset(a,0,sizeof(a));
        cnt=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;cnt++,j++){
                char ch;
                cin>>ch;
                num[i][j]=cnt;
                a[cnt][n*n]=ch=='w'?1:0;
                }
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                for (int k=0;k<5;k++){
                    int x=i+wx[k],y=j+wy[k];
                    if (x<0||y<0||x>=n||y>=n) continue;
                    a[num[x][y]][num[i][j]]=1;
                }
        return;
    }
    int solve(){
        int i,j;
        for (i=0,j=0;i<cnt&&j<cnt;j++){
            int maxi;
            for (maxi=i;maxi<cnt;maxi++)
                if (a[maxi][j]) break;    
            if (a[maxi][j]){
                for (int k=j;k<=cnt;k++)
                    swap(a[maxi][k],a[i][k]);
                for (int k=i+1;k<cnt;k++)
                    if (a[k][j])
                        for (int jj=j;jj<=cnt;jj++)
                            a[k][jj]^=a[i][jj];
                i++;
            }
        }
        for (int k=i;k<cnt;k++) if (a[k][cnt]) return -1;
        int ans=a[cnt-1][cnt];
        for (int i=cnt-2;i>=0;i--){
            for (int j=i+1;j<cnt;j++)
                a[i][cnt]^=(a[j][cnt]&&a[i][j]);
            ans+=a[i][cnt];
            }
        return ans;
    }
};
int main(){
    gauss g;
    int testcase;
    cin>>testcase;
    while (testcase--){
        g.init();
        int ans=g.solve();
        if (ans==-1) cout<<"inf";
        else cout<<ans;
        cout<<endl;
    }
    return 0;
}
       