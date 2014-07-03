#include<cstdio>
#include<iostream>
using namespace std;
#define N 500
int main()
{   
	int n;   
	char s[7];   
	while(scanf("%s%d",s,&n)!=EOF)
	{      
		char result[N]={0};      
		int x=0;    
		int sumBit=0;    
		int sum=0,carry=0;      
		int flag=0,zeroBit=0,dpBit=0; 
		for(int i=5;i>=0;i--)                   
			if(!flag && s[i]=='0') zeroBit++;          
			else          
			{      
				flag=1;     
				if(s[i]=='.') 
					dpBit=5-i;                    
			}      
			for(int i=0;i<6;i++)       
				if(s[i]!='.')        
					x=x*10+s[i]-'0';   
		result[0]=1;     
		for(int i=0;i<n;i++)   
		{   
	

			for(int j=0;j<=sumBit;j++)  
			{              
				sum=result[j]*x+carry;        
				carry=0;             
				if(sum>9)             
				{                
					result[j]=sum%10;    
					carry=sum/10;          
					if(j==sumBit) sumBit++;      
				}              
				else      
					result[j]=sum;     
			}      
		}
		if(x==0)  printf("0\n");
		else
		{
		int d=sumBit-n*dpBit+1;     
		if(d<=0)        
		{       
			putchar('.');    
			for(int i=0;i<-d;i++) putchar('0');       
		}       
		for(int i=sumBit;i>=0;i--)      
		{         
			if(zeroBit*n-1==i) break;   
			if(n*dpBit-1==i) putchar('.');
			printf("%d",result[i]);   
	
		}       
		printf("\n"); 
		}
	}   
	return 0;
}