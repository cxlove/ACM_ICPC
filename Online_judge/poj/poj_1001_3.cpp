#include<cstdio>
#include<iostream>
using namespace std;
#define N 125
int main()
{   
	int n;   
	char s[7];   
	while(scanf("%s%d",s,&n)!=EOF)
	{      
		char result[N]={0}; //本来是int，换成char之后，内存占用还是没减少      
		int x=0;//x为字符串转换后的整数      
		int sumBit=0; //sumBit表示所求次方后总共有多少位    
		int sum=0,carry=0; //       
		int flag=0,zeroBit=0,dpBit=0; //zeroBit标示从字符串末尾开始的连续的0的个数,dpBit表示小数点的位数   
		for(int i=5;i>=0;i--)             //计算小数后面的0结尾的个数，控制输出       
			if(!flag && s[i]=='0') zeroBit++;          
			else          
			{      
				flag=1;     
				if(s[i]=='.') 
					dpBit=5-i;                //计算小数点后面有几位数，也是为了控制输出的       
			}      
			for(int i=0;i<6;i++)       
				if(s[i]!='.')        
					x=x*10+s[i]-'0'; //下面为整数高精度算法    
		result[0]=1;     
		for(int i=0;i<n;i++)   
		{   
			//cout<<sumBit<<endl;

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
		}        //下面为控制输出      
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
			//system("pause");
		}       
		printf("\n"); 
	}   
	return 0;
}