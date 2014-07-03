#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
char a[100],b[100];
int sum,size;
struct node
{
    bool vis;
    node* next[26];
}mem[100000];
node*root;
node* new_node()
{
    return mem+(size++);
}
void insert(char *str)
{
    node*p = root;
    while(*str)
    {
        int t = *str-'a';
        if(p->next[t]==NULL)
        {
            node*q = new_node();
            q->vis = 0;
            memset(q->next,0,sizeof(q->next));
            p->next[t] = q;
            p = q;
        }
        else
        {
            p = p->next[t];
        }
        str++;
    }
    p->vis = 1;
}
int find(char*str)
{
    node*p = root;
    char*q = str;
    while(*str)
    {
        int t = *str-'a';
        if(p->next[t]==NULL)
        {
            insert(q);
            return 1;
        }
        p = p->next[t];
        str++;
    }
    if(p->vis)
        return 0;
    insert(q);
    return 1;
}
void slove(int len,int in)
{
    int i;
    for(i=0;i<len;++i)//+1-2
    {
        if(i<in) b[i] = a[i];
        else b[i] = a[len-1-i+in];
    }
    b[len] = '\0';sum += find(b);
    for(i=0;i<len;++i)//-1+2
    {
        if(i<in) b[i] = a[in-1-i];
        else b[i] = a[i];
    }
    b[len] = '\0';sum += find(b);
    
    for(i=0;i<len;++i)//-1-2
    {
        if(i<in) b[i] = a[in-1-i];
        else b[i] = a[len-1-i+in];
    }
    b[len] = '\0';sum += find(b);
    
    for(i=0;i<len;++i)//+2+1
    {
        if(i<len-in) b[i] = a[in+i];
        else b[i] = a[i+in-len];
    }
    b[len] = '\0';sum += find(b);
    
    for(i=0;i<len;++i)//+2-1
    {
        if(i<len-in) b[i] = a[in+i];
        else b[i] = a[len-i-1];
    }
    b[len] = '\0';sum += find(b);
    
    for(i=0;i<len;++i)//-2+1
    {
        if(i<len-in) b[i] = a[len-1-i];
        else b[i] = a[i+in-len];
    }
    b[len] = '\0';sum += find(b);
    for(i=0;i<len;++i)
    {
        if(i<len-in) b[i] = a[len-1-i];
        else b[i] = a[len-i-1];
    }
    b[len] = '\0';sum += find(b);
}
int main()
{
    int time,i,j;
    scanf("%d",&time);
    while(time--)
    {
        size = 0;
        root = new_node();
        for(i=0;i<26;++i)
            root->next[i] = NULL;
        scanf("%s",a);
        insert(a);sum = 1;
        int len = strlen(a);
        for(i=1;i<len;++i)
        {
            slove(len,i);
        }
        printf("%d\n",sum);
    }
    return 0;
}