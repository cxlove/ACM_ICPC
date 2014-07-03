#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void del_0_after_point(char *s)
{
   int len = strlen(s); 
   char *p = s+len-1;
   if(strchr(s,'.'))
        while(*p =='0')
            *p-- = '\0';
   if(*p == '.')
        *p = '\0';     
}
int main()
{
    char a[100024],b[100024];
    char *a_x,*b_x;
    while(scanf("%s%s",a,b) != EOF)
    {
        a_x = a;
        b_x = b;
        while(*a_x == '0')
            a_x ++;
        while(*b_x == '0')
            b_x ++;
        del_0_after_point(a);
        del_0_after_point(b);
        puts(strcmp(a_x,b_x)==0?"YES":"NO");
    }
    return 0;
}