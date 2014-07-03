
#include<stdio.h> 
int n,a[70]; 
int flag[70]; 
int cmp(const int *a,const int *b)  {return *b-*a;} 
int dfs(int i,int count, int left,int len)
 {     
	if(count==0&&left==0)
		return 1;
	else
	{
		if(left==len||left==0)  {left=len;i=0;}
		else i++;
     	for(;i<n;i++)
		{
			if(flag[i]==0&&a[i]<=left)
			{
				if(i>0&&a[i]==a[i-1]&&flag[i-1]==0)  continue;
				flag[i]=1;
				if(dfs(i,count-1,left-a[i],len))  return 1;
				flag[i]=0;
				if(a[i]==left||left==len)  return 0;
			}
		}
		return 0;	
	}	
}
int main() 
{    
	int i,sum,m;  
	while(scanf("%d",&n),n!=0)   
	{       
		sum=0;       
		for(i=0;i<n;i++)   
		{        
			scanf("%d",&a[i]);     
			sum+=a[i];       
		} 
		qsort(a,n,sizeof(int),cmp);
		memset(flag,0,sizeof(flag));
	//	printf("%d\n",dfs(0,n,sum,sum));
	
	
		for(m=a[0];m<=sum;m++)       
		{                  
			if(sum%m!=0)  continue;          
		//	memset(flag,0,sizeof(flag));  	
		//	printf("%d\n",flag[30]);
			if(dfs(0,n,m,m))          
			{   			
				printf("%d\n",m);         
				break;            
			}     
		}   
	
	}     
	return 0;
 }
 