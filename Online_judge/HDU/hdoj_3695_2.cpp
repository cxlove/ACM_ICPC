#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int nMax=1003;
const int mMax=6000000;
int len2;
char str1[mMax],str2[mMax],str3[mMax];
void change(){
    int len1=strlen(str1),num,i,j;
    len2=0;
    for(i=0;i<len1;i++){
        if(str1[i]>='A'&&str1[i]<='Z'){
            str2[len2++]=str1[i];
            continue;
        }
        if(str1[i]=='['){
            i++;
            num=0;
            for(;str1[i]>='0'&&str1[i]<='9';i++){
                num=num*10+str1[i]-'0';
            }
            int ll=len2;
            for(j=ll;j<ll+num;j++){
                str2[j]=str1[i];
                len2++;
            }
            i+=1;
        }
    }
    str2[len2]='\0';
    for(i=0;i<len2;i++){
        str3[i]=str2[len2-i-1];
    }
    str3[len2]='\0';
}

class node{
public:
    int id;
    int vis;  //前缀记录标志
    node *next[26],*fail;
    node(){
        vis=0;
        fail=NULL;
        for(int i=0;i<26;i++)next[i]=NULL;
    }
}*root,*que[mMax];

void insert(char *s){    //构造前缀树
    int i;
    node *r=root;
    int l=strlen(s);
    for(i=0;i<l;i++){
        int loc=s[i]-'A';
        if(r->next[loc]==NULL){
            r->next[loc]=new node();
        }
        r=r->next[loc];
    }
    r->vis++;
}

void acAuto(){      //用bfs为每个节点设定fail指针
    int i,head=0,tail=0;
    node *p,*tmp;
    root->fail=NULL;
    que[tail++]=root;
    while(head<tail){
        tmp=que[head++];
        for(i=0;i<26;i++){
            if(tmp->next[i]==NULL)continue;
            if(tmp==root){
                tmp->next[i]->fail=root;
            }
            else {
                for(p=tmp->fail;p!=NULL;p=p->fail){
                    if(p->next[i]!=NULL){
                        tmp->next[i]->fail=p->next[i];
                        break;
                    }
                }
                if(p==NULL){
                    tmp->next[i]->fail=root;
                }
            }
            que[tail++]=tmp->next[i];
        }
    }
}

int search(char *msg){
    int i,idx,ans=0;
    node *p=root,*tmp;
    for(i=0;msg[i];i++){
        idx=msg[i]-'A';
        while(p->next[idx]==NULL&&p!=root){
            p=p->fail;
        }
        p=p->next[idx];
        if(p==NULL)p=root;
        for(tmp=p;tmp!=NULL&&tmp->vis!=-1;tmp=tmp->fail){
            ans+=tmp->vis;
            tmp->vis=-1;
        }
    }
    return ans;
}
int main(){
    int cas,n,i,ans;
    char str[nMax];
    scanf("%d",&cas);
    while(cas--){
        ans=0;
        scanf("%d",&n);
        root=new node();
        while(n--){
            scanf("%s",str);
            insert(str);
        }
        acAuto();
        scanf("%s",str1);
        change();
        ans+=search(str2);
        ans+=search(str3);
        printf("%d\n",ans);
    }
    return 0;
}
