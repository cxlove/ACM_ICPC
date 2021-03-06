#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int t,n,k;
struct Node{
    int p,d;
    bool operator<(const Node t) const{
        return p!=t.p?p>t.p:d>t.d;
    }
}temp;
void scanf_(int &num){
    char in; 
    while((in=getchar())>'9'||in<'0');
    num=in-'0';  
    while(in=getchar(),in>='0'&&in<='9')  
        num*=10,num+=in-'0';
} 
void printf_(int num){
    int ans[10],top=0;
    while(num!=0){
        ans[top++]=num%10;
        num/=10;
    }
    if(top==0)
        putchar('0');
    for(int i=top-1;i>=0;i--){
        char ch=ans[i]+'0';
        putchar(ch);
    }
}
int main(){
    scanf_(t);
    while(t--){
        priority_queue<Node>que;
        while(!que.empty())
            que.pop();
        scanf_(n);
        for(int i=0;i<n;i++){
            scanf_(temp.p);scanf_(temp.d);
            que.push(temp);
        }
        k=1;
        while(!que.empty()){
            temp=que.top();
            que.pop();
            if(k&1){
                temp.p+=temp.d;
                que.push(temp);
            }
            k++;
        }
        printf_(temp.p);
        putchar('\n');
    }
    return 0;
}