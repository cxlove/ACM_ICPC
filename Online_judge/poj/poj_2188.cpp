#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int b[1010],N,change,a[1010],flag[1010],c[1010];

void merge(int p,int q,int r)
{
    int i,j=0;
    int beginA=p,endA=q,beginB=q+1,endB=r; 
    while(beginA<=endA && beginB<=endB) 
    {
        if(a[beginA]<=a[beginB]) 
        {
            b[j++]=a[beginA++];
        } 
       else 
       {
            b[j++]=a[beginB++];
            change += q - beginA + 1;
       }
    }
    while(beginA<=endA) 
    {
        b[j++]=a[beginA++];
    }
    while(beginB<=endB) 
    {
        b[j++]=a[beginB++];
    }
    for(i=0;i<j;i++)
    {
        a[p+i]=b[i];
    }
}

void mergeSort(int first, int last)
{
    int mid;
    if(first<last)
    {
        mid=(first+last)/2;
        mergeSort(first,mid);
        mergeSort(mid+1,last);
        merge(first,mid,last);
    }
}

int main()
{
    int i,x,y;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d %d",&a[i],&c[i]);
        flag[c[i]]=i;
    }
    for(i=0;i<N;i++)
    {
        a[i]=flag[a[i]];
    }
    change=0;
    mergeSort(0,N-1);
    printf("%d\n",change);
    system("PAUSE");
    return 0;
}

