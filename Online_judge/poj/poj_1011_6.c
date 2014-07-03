
#include<stdio.h> 
int n,a[70],count,ip; 
int flag[70],mark; 
int cmp(const int *a,const int *b)  {return *b-*a;} 
int dfs(int count, int i,int left,int m)
 {     
	if(count==0&&left==0)
		return 1;
	else
	{
		if(left==m||left==0)  {left=m;i=0;}
		else i++;
     	for(;i<n;i++)
		{
			if(flag[i]==0&&a[i]<=left)
			{
				if(i>0&&a[i]==a[i-1]&&flag[i-1]==0)  continue;
				flag[i]=1;
				if(dfs(count-1,i,left-a[i],m))  return 1;
				flag[i]=0;
				if(a[i]==left||left==m)  return 0;
			}
		}
		return 0;
	
	}	
}
int main() 
{    
	int i,j,ii,sum,max,m;  
	while(scanf("%d",&n),n!=0)   
	{       
		sum=0;    
		max=0;    
		for(i=0;i<n;i++)   
		{         
			scanf("%d",&a[i]);   
			if(a[i]>max)  max=a[i];     
			sum+=a[i];       
		} 
		qsort(a,n,sizeof(int),cmp);
		
	//	printf("%d\n",dfs(n,0,sum,sum));
		mark=1;
		for(ii=n;ii>=1;ii--)       
		{                  
			if(sum/ii<max||sum%ii!=0)  continue;    
			m=sum/ii;         
			memset(flag,0,sizeof(flag));   
			
			if(dfs(n,0,m,m))          
			{     
				mark=0;
				printf("%d\n",m);         
				break;            
			}     
		}   
		if(mark)  printf("%d\n",sum);
	}     
	return 0;
 }
 