#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
struct Node{
    char name[25];
    int rp;
};
vector<Node>a[10005];
int n,m;
int main(){
    char str[100];
    while(scanf("%d%d",&n,&m)!=EOF){
        Node temp;
        for(int i=1;i<=n;i++)
            a[i].clear();
        for(int i=1;i<=n;i++){
            int k;
            scanf("%d",&k);
            while(k--){
                scanf("%s%d",temp.name,&temp.rp);
                a[i].push_back(temp);
            }
        }
        while(m--){
            scanf("%s",str);
            int i,j;
            if(strcmp(str,"GETON")==0){            
                scanf("%d%s%d",&i,temp.name,&temp.rp);
                a[i].push_back(temp);
            }
            else if(strcmp(str,"JOIN")==0){
                scanf("%d%d",&i,&j);
                while(!a[j].empty()){
                    temp=a[j].back();
                    a[j].pop_back();
                    a[i].push_back(temp);
                }
            }
            else{
                scanf("%d",&i);
                int mmax=100000,pos;
                for(int k=0;k<a[i].size();k++)
                    if(a[i][k].rp<mmax||(a[i][k].rp==mmax&&strcmp(a[i][k].name,a[i][pos].name)>0)){
                        mmax=a[i][k].rp;
                        pos=k;
                    }
                    printf("%s\n",a[i][pos].name);
                    a[i].erase(a[i].begin()+pos);
            }
        }
    }
    return 0;
}
