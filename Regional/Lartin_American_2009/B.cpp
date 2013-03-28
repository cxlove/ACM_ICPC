/*
ID:cxlove
Prob:B Brothers
Algorithm:brute force
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,r,c,k;
int a[105][105],b[105][105];
int way[4][2]= {0,1,0,-1,1,0,-1,0};
int main()
{
    //freopen("input.txt","r",stdin);
    while(scanf("%d%d%d%d",&n,&r,&c,&k)!=EOF)
    {
        if(!n&&!r&&!c&&!k) break;
        for(int i=1; i<=r; i++)
        {
            for(int j=1; j<=c; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(int t=0; t<k; t++)
        {
            for(int i=1; i<=r; i++)
            {
                for(int j=1; j<=c; j++)
                {
                    bool flag=false;
                    for(int z=0; z<4; z++)
                    {
                        int x=i+way[z][0],y=j+way[z][1];
                        if(x>=1&&x<=r&&y>=1&&y<=c&&a[i][j]==(a[x][y]+1)%n)
                        {
                            b[i][j]=a[x][y];
                            flag=true;
                            break;
                        }
                    }
                    if(!flag) b[i][j]=a[i][j];
                }
            }
            memcpy(a,b,sizeof(b));

        }
        for(int i=1; i<=r; i++)
        {
            for(int j=1; j<=c; j++)
                printf("%d%c",a[i][j],j==c?'\n':' ');
        }
    }
    return 0;
}