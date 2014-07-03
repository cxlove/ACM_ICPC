#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
struct Node{
    string phone;
    int t;
    int num;
}a[50005];
int n,ans[20];
bool cmp(Node n1,Node n2){
    return n1.t<n2.t;
}
map<string,int> st;
int main(){
    int h,m,s;
    char str[100];
    while(cin>>n){
        int cnt=0,i;
        while(cin>>str){
            if(strcmp(str,"#end")==0)
                break;
            sscanf(str,"%d:%d:%d",&h,&m,&s);
            a[cnt].t=h*3600+m*60+s;
            cin>>a[cnt].phone>>a[cnt].num;
            cnt++;
        }
        sort(a,a+cnt,cmp);
        memset(ans,0,sizeof(ans));
        st.clear();
        for( i=0;i<cnt;i++){
            if(st.count(a[i].phone))
            {
                if(a[i].t-st.find(a[i].phone)->second>=60)
                {
        //            printf("%d %d\n",i,a[i].num);
                    ans[a[i].num]++;
                    st.find(a[i].phone)->second=a[i].t;
                }
            }
            else{
                st.insert(make_pair(a[i].phone,a[i].t));
                ans[a[i].num]++;
            }
        }
        printf("The result is :\n");
        for( i=1;i<=n;i++){
             printf("%02d : ",i);
            for(int j=1;j<=ans[i];j++)
                printf("*");
            printf("\n");
        }
    }
    return 0;
}



