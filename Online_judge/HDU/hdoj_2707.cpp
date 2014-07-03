#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

char code[32];

int main()
{
    char c;
    int x,y,cnt;

    code[0]=' ';
    for (char i='A'; i<='Z'; i++) code[i-64]=i;
    code[27]='\'';
    code[28]=',';
    code[29]='-';
    code[30]='.';
    code[31]='?';
    while (!feof(stdin))
    {
        c=getchar();
        if (c=='#') break;

        x=0; y=0;
        while (c!='*')
        {
            while (c!=' ' && c!='*' && c!='#') c=getchar();
            if (c=='*') break;
            if (c=='#') return 0;
            y++; x<<=1; //printf("|");putchar(c); printf("|");
            cnt=0;
            while (c==' ') cnt++,c=getchar();
            //printf("cnt=%d\n",cnt);
            if ((cnt%2)==0) x^=1;
            if (y==5)
            {
                putchar(code[x]);
                x=y=0;
            }
        }
        if (y!=0) putchar(code[x<<(5-y)]);
        putchar('\n');
    }
    return 0;
}
