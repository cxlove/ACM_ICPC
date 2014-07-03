#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
int cmp(const void *p1,const void *p2){ 
	return *(double*)p1-*(double*)p2;
}
int main(){
	int i,n;
	double a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lf",&a[i]);
	qsort(a,n,sizeof(double),cmp);
	for(i=n;i>=2;i--)   
		a[i-2]=2.0*sqrt(a[i-1]*a[i-2]);
	printf("%0.3f\n",a[0]);
	return 0;
}