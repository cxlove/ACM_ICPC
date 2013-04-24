#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#define test puts("OK");
using namespace std;
const int N = 1000005;
struct Node{
    char ch;
    Node *next,*pre;
    Node(){}
    Node(char c):ch(c){next=pre=NULL;}
}*head,*now;
char str[N];
void dfs(Node *p){
    printf("%c",p->ch);
    if(p->next) dfs(p->next);
    delete(p);
}
int main(){
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        head=new Node(' ');
        now=head;
        for(int i=0;str[i];i++){
            if(str[i]=='<'){
                if(now->pre!=NULL)
                    now=now->pre;
            }
            else if(str[i]=='>'){
                if(now->next!=NULL)
                    now=now->next;
            }
            else if(str[i]=='-'){
                if(now==head) continue;
                Node *p=now->pre;
                Node *c=now->next;
                p->next=c;
                if(c) c->pre=p;
                delete(now);
                now=p;
            }
            else{
                Node *cur=new Node(str[i]);
                Node *c=now->next;
                now->next=cur;
                cur->pre=now;
                cur->next=c;
                if(c)c->pre=cur;
                now=cur;
            }
            //dfs(head);puts("");
        }
        printf("Case %d:",++cas);
        dfs(head);puts("");
    }
    return 0;
}