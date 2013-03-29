#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>
#include<vector>
#include<cstring>
#define N 105
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define abs(a) ((a)<0?-(a):(a))
using namespace std;
vector<int>v;
vector<pair<int,int> >ans;
char str[N*10];
int t,cnt;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%s",&cnt,str);
        int len=strlen(str);
        str[len]=',';str[len+1]='\0';
        v.clear();ans.clear();
        int m=0;
        for(int i=0;str[i];i++){
            if(str[i]==',')
                v.pb(m),m=0;
            else m=m*10+str[i]-'0';
        }
        sort(v.begin(),v.end());
        v.resize(unique(v.begin(),v.end())-v.begin());
        //for(int i=0;i<v.size();i++) cout<<v[i]<<endl;
        int l=v[0],r=v[0];
        for(int i=1;i<v.size();i++){
            if(v[i]==r+1) r=v[i];
            else{
                ans.pb(mp(l,r));
                l=v[i];r=v[i];
            }
        }
        ans.pb(mp(l,r));
        for(int i=0;i<ans.size();i++){
            if(ans[i].first==ans[i].second)
                printf("%d",ans[i].first);
            else
                printf("%d-%d",ans[i].first,ans[i].second);
            printf("%c",i==ans.size()-1?'\n':',');
        }
    }
    return 0;
}