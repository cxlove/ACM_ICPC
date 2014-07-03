#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char str[5000];
char tt[5000];
int main()
{
int T;
int iCase=0;
bool start;
int i;
scanf("%d",&T);
while(T--)
{
iCase++;
scanf("%s",&str);
start=false;
int len=strlen(str);
int t=0;
for(i=2;i<len;i++)
{
if(start==false&&str[i-2]==':'&&str[i-1]=='/'&&str[i]=='/') {start=true;continue;}
if(start&&(str[i]=='/'||str[i]==':')) break;
if(start) tt[t++]=str[i];
} 
tt[t]='\0';
printf("Case #%d: %s\n",iCase,tt); 

} 
return 0; 

}