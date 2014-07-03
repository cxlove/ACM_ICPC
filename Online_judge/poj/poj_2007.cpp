#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define PR 1e-6
#define N 55
int n;
struct TPoint{ 
	int x,y;}
ply[N],s;
char le[20];
double dot(double a1,double b1,double a2,double b2){  
	return a1*b2-a2*b1;}
double cross(TPoint a,TPoint b,TPoint c){   
	return dot(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);}
int dblcmp(double a){  
	if(fabs(a)<PR) return 0;   
	return a>0?1:-1;}
bool cmp(TPoint a,TPoint b){  
	return (dblcmp(cross(s,a,b)))>0;}
int main(){   
	int i,m=0;   
	scanf("%d%d",&s.x,&s.y); 
	while(~scanf("%d%d",&ply[m].x,&ply[m].y))    
		m++;   
	sort(ply,ply+m,cmp);
	//按逆时针排序  
	printf("(%d,%d)\n",s.x,s.y);  
	for(i=0;i<m;i++)  
		printf("(%d,%d)\n",ply[i].x,ply[i].y); 
	return 0;
}