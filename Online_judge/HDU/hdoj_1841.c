

#include<stdio.h>
#define max(a,b) a>b?a:b
char str1[1000001],str2[1000001];
int fail[1000001],i,j;
int kmp(char *str,char *pat,int l1,int l2)
{
     i=0;
     memset(fail,-1,sizeof(fail));
    fail[0]=-1;
     for(j=1;j<l2;j++){
         for(i=fail[j-1];i>=0 && pat[i+1]!=pat[j];i=fail[i]);
         fail[j]=(pat[i+1]==pat[j])?i+1:-1;
     }
     for(i=j=0;i<l1&&j<l2;i++)
         if(str[i]==pat[j]) j++;
         else if(j)
             j=fail[j-1]+1,i--;
         if(pat[j])  return -1;
         else return i-j;
    
 }


int main()
{
    int n,pos,l1,l2,v,u;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",str1);
        scanf("%s",str2);
        l1=strlen(str1);
        l2=strlen(str2);

        u=0;pos=kmp(str1,str2,l1,l2);
        if(pos!=-1)
            u=l2;
        else if(i==l1 && j>0 &&(str1[l1-1]==str2[j-1])) u=j;
        v=0;pos=kmp(str2,str1,l2,l1);
         if(pos!=-1) v=l1;
         else if(i==l2 && j>0 && (str2[l2-1]==str1[j-1])) v=j;

         printf("%d\n",l1+l2-(max(u,v)));
    }
    return 0;
}


