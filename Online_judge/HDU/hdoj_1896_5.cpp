
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct Node{
    int p,d;
    bool operator<(const Node t) const{
        return p!=t.p?p>t.p:d>t.d;
    }
};
void scanf_(int &num){
    char in; 
    while((in=getchar())>'9'||in<'0');
    num=in-'0';  
    while(in=getchar(),in>='0'&&in<='9')  
        num*=10,num+=in-'0';
} 
int main(){
    int t,n;
    scanf_(t);
    while(t--){
        Node temp;
        priority_queue<Node>que;
        while(!que.empty())
            que.pop();
        scanf_(n);
        for(int i=0;i<n;i++){
            scanf_(temp.p);scanf_(temp.d);
            que.push(temp);
        }
        int k=1;
        while(!que.empty()){
            temp=que.top();
            que.pop();
            if(k&1){
                temp.p+=temp.d;
                que.push(temp);
            }
            k++;
        }
        printf("%d\n",temp.p);
    }
    return 0;
}