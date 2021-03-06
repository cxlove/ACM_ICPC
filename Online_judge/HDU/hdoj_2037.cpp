#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int N;
struct show
{
    int start;
    int end;
};
show shows[110];
int cmp(const void* a,const void* b)
{
    show c=*(show*)a;
    show d=*(show*)b;
    if(c.end==d.end)
    {
        return c.start-d.start;
    }
    else
    return c.end-d.end;
}
int main()
{
    int i;
    while(scanf("%d",&N)!=EOF)
    {
        if(N==0)break;
        int number=0;
        for(i=0;i<N;i++)
        {
            scanf("%d %d",&shows[i].start,&shows[i].end);
        }
        qsort(shows,N,sizeof(shows[0]),cmp);
        int temp=0;
        for(i=0;i<N;i++)
        {
            if(shows[i].start>=temp)
            {
                number++;
                temp=shows[i].end;
            }
        }
        printf("%d\n",number);
    }
    return 0;
}