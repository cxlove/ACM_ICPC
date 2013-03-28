/*
ID:cxlove
Prob:J Jingle Composing
Algorithm:burte force
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
map<char,int>m;
char str[10000];
int main()
{
    m['W']=64;m['H']=32;m['Q']=16;m['E']=8;m['S']=4;m['T']=2;m['X']=1;
    while(scanf("%s",str)!=EOF)
    {
        if(str[0]=='*') break;
        int s=0;
        int ans=0;
        for(int i=0;str[i];i++)
        {
            if(str[i]=='/')
            {
                if(s==64) ans++;
                s=0;
            }
            else s+=m[str[i]];
        }
        if(s==64) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
