#include <cstdio>  
int main()  
{  
    int n, m;  
    while (scanf("%d%d", &m,&n)!=EOF)  
    {  
        int tot=n*m-((n-1)>>1)*((n-1)>>1);  
        printf("%d\n", tot);  
    }  
    return 0;  
}  