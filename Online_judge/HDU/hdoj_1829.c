
#include<stdio.h> 
int father[2005],sex[2005]; 
int find(int a) {   
    int s=0;    
    int temp=a;   
    while(a!=father[a])   {     
        if(s==sex[a])  s=0;    
        else s=1;      
        a=father[a];     }   
    father[temp]=a;  
    sex[temp]=s;    
    return a; 
} 
int main() {  
    int t,n,m,ra,rb,i,j=0,a,b,flag;  
    scanf("%d",&t);   
    while(t--)     {      
        flag=1;      
        scanf("%d%d",&n,&m);    
        for(i=1;i<=n;i++)         {      
            father[i]=i;             sex[i]=0;    
        }        
        for(i=1;i<=m;i++)         {     
            scanf("%d%d",&a,&b);        
            if(flag)             {     
                ra=find(a);                  
                rb=find(b);                     
                if(ra==rb)                 {       
                    if(sex[a]==sex[b])  flag=0;             
                }                 else                {       
                    father[ra]=rb;                 
                    if(sex[a]!=sex[b])  sex[ra]=0;           
                    else  sex[ra]=1;                 }        
            }   
        }         printf("Scenario #%d:\n",++j);      
        if(flag)         {        
            printf("No suspicious bugs found!\n\n");         }       
        else        {             printf("Suspicious bugs found!\n\n");   
        }     }     return 0; } 
