/*
ID:cxlove
PROB:POJ 3347 Kadj Squares
DATA:2012.2.10
HINT:计算几何，线段映射
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct squ{
	int len;
	int left,right;
}a[100];
int Abs(int a){return a<0?-a:a;}
int n;
int main(){	
	while(scanf("%d",&n),n!=0){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i].len);
			a[i].left=0;
			for(int j=0;j<i;j++)
				a[i].left=max(a[i].left,a[j].right-Abs(a[i].len-a[j].len));
			a[i].right=a[i].left+(a[i].len*2);
		}
		for(int i=1;i<n;i++){
			for(int j=0;j<i;j++){
				if(a[i].left<a[j].right&&a[i].len<a[j].len)
					a[i].left=a[j].right;
				if(a[i].left<a[j].right&&a[i].len>a[j].len)
					a[j].right=a[i].left;
			}
		}
		for(int i=0;i<n;i++)
			if(a[i].left<a[i].right)
				printf("%d ",i+1);
		printf("\n");
	}
	return 0;
}




