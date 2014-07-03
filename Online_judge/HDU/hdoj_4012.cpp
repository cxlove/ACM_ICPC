#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<string>
using namespace std;
struct Node{
    int val,step;
}s,e,u,v;
char str[20];
bool flag[1<<16];
int n;
int bfs(){
    queue<Node>que;
    while(!que.empty())
        que.pop();
    que.push(s);
    memset(flag,false,sizeof(flag));
    flag[0]=true;
    while(!que.empty()){
        u=que.front();
        que.pop();
        if(u.val==(1<<(2*n))-1)
            return u.step;
        for(int i=0;i<2*n;i++){
            v=u;v.step++;
            if((1<<i)&u.val) continue;
            int tmp=0;
            for(int j=i;j<(i/n+1)*n;j++){
                if((1<<j)&u.val)
                    break;
                if(str[j]==str[i]) tmp|=1<<j;
            }
            for(int j=i-1;j>=(i/n)*n;j--){
                if((1<<j)&u.val)
                    break;
                if(str[j]==str[i]) tmp|=1<<j;
            }
            for(int j=tmp;j;j=tmp&(j-1)){
                if(flag[u.val|j])
                    break;
                flag[u.val|j]=true;
                v.val=(u.val|j);            
                que.push(v);
            }
            if(i>=n)
                continue;
            if(u.val&(1<<(i+n)))
                continue;
            tmp=0;
            for(int j=i;j<n;j++){
                if(((1<<j)&u.val)||((1<<(j+n))&u.val))
                    break;    
                if(str[j]==str[i]) tmp|=(1<<j);
                if(str[j+n]==str[i]) tmp|=(1<<(j+n));
            }
            for(int j=i-1;j>=0;j--){
                if(((1<<j)&u.val)||((1<<(j+n))&u.val))
                    break;
                if(str[j]==str[i]) tmp|=(1<<j);
                if(str[j+n]==str[i]) tmp|=(1<<(j+n));
            }
            for(int j=tmp;j;j=tmp&(j-1)){
                if(flag[u.val|j])
                    continue;
                flag[u.val|j]=true;
                v.val=(u.val|j);
                que.push(v);
            }
        }
    }
}
int main(){
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s%s",str,str+n);
        s.val=s.step=0;
        printf("Case #%d: %d\n",++cas,bfs());
    }
    return 0;
}
