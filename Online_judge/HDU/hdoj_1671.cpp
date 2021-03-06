/*hdu 1671 phone list Trie树的应用 2011.10.15*/
 
#include <iostream>
#define MAX 10
using namespace std;
bool flag;

typedef struct Trie_Node
{
    bool isphone;
    struct Trie_Node *next[MAX];    
}Trie;

void insert(Trie *root,char *phone)
{
    Trie *p=root;
    while(*phone!='\0')
    {
        if(p->next[*phone-48]==NULL)
        {
            Trie *temp=(Trie *)malloc(sizeof(Trie));
            temp->isphone=false;
            for(int i=0;i<MAX;i++)
            {
                temp->next[i]=NULL;
            }
            p->next[*phone-48]=temp;    
        }
        if(p->isphone==true)
            flag=true;
        p=p->next[*phone-48];
        phone++;
    }
    p->isphone=true;
    for(int i=0;i<MAX;i++)
    {
        if(p->next[i]!=NULL)
        {
            flag=true;
            break;
        }
    }    
}

void del(Trie *root)
{
    for(int i=0;i<MAX;i++)
    {
        if(root->next[i]!=NULL)
        {
            del(root->next[i]);
        }
    }
    free(root);
}

int main(int argc, char *argv[])
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i;
        int n;
        char phone[11];
        Trie *root=(Trie *)malloc(sizeof(Trie));
        root->isphone=false;
        flag=false;
        for(i=0;i<MAX;i++)
        {
            root->next[i]=NULL;
        }
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",phone);
            if(flag!=true)
            {
                insert(root,phone);
            }
        }
        if(flag==true)
            printf("NO\n");
        else
            printf("YES\n");
        del(root);               //必须释放空间，否则会报Memory Limited的错误
    }
    return 0;
}