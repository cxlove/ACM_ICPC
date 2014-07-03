#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#define MAX_LEN 1111
char psd[MAX_LEN];
const char end[]="end";
const char s1[]="aeiou";
int c1(){
 int i,j;
 for(i=0;psd[i]!='\0';i++)
  for(j=0;s1[j]!='\0';j++)
   if(psd[i]==s1[j])
    return 1;
 return 0;
}
int c2(){
 int i,j,cnt1,cnt2,tag;
 cnt1=cnt2=0;
 for(i=0;psd[i]!='\0';i++){
  for(j=0,tag=0;s1[j]!='\0';j++)
   if(psd[i]==s1[j]){
    cnt1++;
    cnt2=0;
    tag=1;
    break;
   }
  if(tag==0){
   cnt1=0;
   cnt2++;
  }
  if(cnt1>=3 || cnt2>=3)
   return 0;
 }
 return 1;
}
int c3(){
 int i;
 for(i=1;psd[i]!='\0';i++)
  if(psd[i]==psd[i-1])
   if(psd[i]!='e' && psd[i]!='o')
    return 0;
 return 1;
}
int main(){
 while(scanf("%s",psd),strcmp(psd,end)){
  if(c1() && c2() && c3())
   printf("<%s> is acceptable.\n",psd);
  else
   printf("<%s> is not acceptable.\n",psd);
 }
 return 0;
}
 