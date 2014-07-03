#include <iostream>
using namespace std;
const int maxn=300;
int x[maxn],y[maxn];
int n,m,mx,my,q;
struct Matrix
{
int x1,x2,y1,y2;
void init(){scanf("%d%d%d%d",&x1,&y1,&x2,&y2);}
} reg[maxn];
int bianma[maxn][maxn],area[maxn][maxn];
int compint(const void *a,const void *b)
{
return *((int*)a)-*((int*)b);
}
int inmat(const Matrix &c,int x1,int y1,int x2,int y2)
{
return x1>=c.x1&&y1>=c.y1&&x2<=c.x2&&y2<=c.y2;
}
void prework()
{
int i,j,k1,k2;
for (i=0;i<n;i++) reg[i].init();
mx=my=0;
for (i=0;i<n;i++)
{
   x[mx++]=reg[i].x1;
   x[mx++]=reg[i].x2;
   y[my++]=reg[i].y1;
   y[my++]=reg[i].y2;
}
qsort(x,mx,sizeof(int),compint);
qsort(y,my,sizeof(int),compint);
j=0;
for (i=1;i<mx;i++) if (x[i]==x[i-1]) j++;else x[i-j]=x[i];
mx-=j;
j=0;
for (i=1;i<my;i++) if (y[i]==y[i-1]) j++;else y[i-j]=y[i];
my-=j;
memset(bianma,0,sizeof(bianma));
for (k1=0;k1+1<mx;k1++) for (k2=0;k2+1<my;k2++) area[k1][k2]=(x[k1+1]-x[k1])*(y[k2+1]-y[k2]);
for (j=0;j<n;j++)
   for (k1=0;k1+1<mx;k1++)
    for (k2=0;k2+1<my;k2++)
     if (inmat(reg[j],x[k1],y[k2],x[k1+1],y[k2+1]))
      bianma[k1][k2]+=(1<<j);
}
void work()
{
int i,j,k,k1,k2;
for (i=0;i<m;i++)
{
   scanf("%d",&q);
   int tot=0;
   k=0;
   for (j=0;j<q;j++){int num;scanf("%d",&num);k+=(1<<(num-1));}
   for (k1=0;k1+1<mx;k1++) for (k2=0;k2+1<my;k2++) if ((bianma[k1][k2]&k)!=0) tot+=area[k1][k2];
   printf("Query %d: %d\n",i+1,tot);
}
}
int main()
{
int cas=0;
while(scanf("%d%d",&n,&m),n||m)
{
   cas++;
   printf("Case %d:\n",cas);
   prework();
   work();
   printf("\n");
}
return 0;
}