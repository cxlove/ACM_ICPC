#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 50000+5;
struct point{
 int x,y;
 bool operator <(const point &pu){
  if(y==pu.y)
   return x<pu.x;
  return y<pu.y;
 }
};
int Cross(point p0,point p1,point p2)//p0-p2以p0-p1为顺时针（逆时针）
{
 int x0,y0, x1,y1;
 x0 = p1.x-p0.x;
 y0 = p1.y-p0.y;
 x1 = p2.x-p0.x;
 y1 = p2.y-p0.y;
 return x0* y1 - y0 * x1;
}
int graham(point pnt[],int n,point res[])//凸包算法graham
{
 int i,len , k =0,top =1;
 sort(pnt,pnt+n);
 if(n==0)return 0;
  res[0] = pnt[0];
 if(n==1)return 1;
  res[1] =pnt[1];
 if(n== 2)return 2;
  res[2] = pnt[2];
 for(i = 2;i < n;i++){
  while(top && Cross(res[top-1],res[top],pnt[i])>= 0)
   top--;
  res[++top] = pnt[i];
 }
 len = top;res[++top] = pnt[n-2];
 for(i = n-3; i >= 0;i--){
  while(top!=len && Cross(res[top-1],res[top],pnt[i])>= 0)
   top--;
  res[++top] = pnt[i];
 }
 return top;
}
int dist(point a, point b){
 return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main(){
 //freopen("F:\\in.txt","r",stdin);
 int n;
 scanf("%d",&n);
 int i,j,k;
 point *pn = new point[n];
 point *res = new point[n];
 for(i=0;i<n;i++){
  scanf("%d%d",&pn[i].x,&pn[i].y);
 }
 int ans=0;
 int m= graham(pn,n,res);
 for(i=0;i<=m;i++){
  for(j=i+1;j<=m;j++){
   int temp=dist(res[i],res[j]);
   if(temp>ans) ans=temp;
  }
 }
 printf("%d\n",ans);
 return 0;
}