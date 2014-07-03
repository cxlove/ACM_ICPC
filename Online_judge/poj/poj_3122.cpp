#include <stdio.h>
#include <stdlib.h>
 
#define maxpc 10000
#define pi 3.1415926535897932384626433832795
 
double pie[maxpc];
int piec,peoplec;
 
int test(double size)
{
    int i;
    int pc=0;
 
    //不需要考虑1e-xx的误差，二分已解决
    for(i=0;i<piec && pie[i]>=size && pc<peoplec;i++) 
        pc=pc+(int)(pie[i]/size);
     
    return pc>=peoplec;
}
 
int cmp(const void *a,const void *b)
{
    if(*(double*)a>*(double*)b) return -1;
    else if(*(double*)a==*(double*)b) return 0;
    else return 1;
}
 
int main()
{
    int cc;
    int i,r;
    double from,mid,to;
 
    scanf("%d",&cc);
    for(;cc;cc--)
    {
        from=0;
        to=0;
        scanf("%d%d",&piec,&peoplec);
        peoplec++;
        for(i=0;i<piec;i++)
        {
            scanf("%d",&r);
            pie[i]=r*r*pi;
        }
         
        qsort(pie,piec,sizeof(double),cmp);
 
        to=pie[0]+1;
        while(to-from>1e-6)
        {
            mid=(from+to)/2;
            if(test(mid)) from=mid;
            else to=mid;
        }
 
        printf("%.4f\n",(from+to)/2);
    }
 
    return 0;
}