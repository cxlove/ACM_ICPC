#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
char str1[1000][65],str2[65],temp1[65],temp2[65];
int comp(const void *a,const void *b )
{
	return strcmp((char *)a,(char *)b);
}
int main(){
	int n,m,sum=0;
	scanf("%d%d",&n,&m);
	getchar();
	for(int i=0;i<n;i++)
		gets(str1[i]);
    qsort(str1,n,65*sizeof(char),comp);
	for(int i=0;i<m;i++){
		gets(str2);
		int low=0,high=n-1,mid;
		while(low+1<high){
			mid=(low+high)>>1;
			if(strcmp(str1[mid],str2)>0)
				high=mid;
			else
				low=mid;
		}
		strncpy(temp1,str1[low],strlen(str2));
		strncpy(temp2,str1[high],strlen(str2));
		temp1[strlen(str2)]=temp2[strlen(str2)]='\0';
		if(strcmp(temp1,str2)==0||strcmp(temp2,str2)==0)
			sum++;
	}
	printf("%d\n",sum);
//	system("pause");
	return 0;
}