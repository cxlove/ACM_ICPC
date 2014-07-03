#include<stdio.h>
int n,p[155]={0},m,i;
int main(){
	while(scanf("%d",&n)!=EOF&&n){
		m=1;
		for(i=1;i<n-1;i++){
			p[i]=(p[i-1]+m-1)%(n-i);
			if(p[i]==0){
				i=0;
				m++;
			}
		}
		printf("%d\n",m);
	}
	return 0;
}