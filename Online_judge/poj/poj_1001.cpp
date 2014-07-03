//先把转为整数，在套用模板，最后把点的位置算出来加上去就行了。
//高精度不套用模板就是自残+浪费啊！ >_<

#include<iostream>
#include<string.h>
using namespace std;
int result1[200],result2[200];
char R[6];
int R1[6];
int flag=0;
int markN;
void reset()
{
    for(int i=0;i<200;i++)
    {
        result1[i]=result2[i];
    }
    memset(result2,0,sizeof(result2));
}
//如果最后几位是0的话应该省去
int main()
{
    int n,i,j,mark,len;
    while(cin>>R>>n)
    {
       markN=n;
       mark=-1;
       len=strlen(R);
       for(i=0;i<len;i++)
       {
            if(R[i]=='.')
            mark=i;
       }//找到小数点
       int t=5;
       for(i=len-1;i>mark;i--)
       {
           R1[t]=R[i]-'0';t--;
       }
       for(i=mark-1;i>=0;i--)
       {
           R1[t]=R[i]-'0'; t--;
       }
       if(mark>=0)
       mark=len-mark-1;//小数点的位数
       else
       mark=0;
       for(i=199;i>=194;i--)
       {
           result2[i]=R1[i-194];
       }
       int k;
       n--;
       while(n--)//表示乘积的次数
       {
           reset();
           k=flag=0;
           for(i=5;i>=0;i--)
           {
               for(j=199;j>=0;j--)
               {
                   result2[j-k]+=result1[j]*R1[i];
               }
               k++;
           }
           for(i=199;i>=0;i--)
           {
               result2[i]+=flag;
               if(result2[i]>=10)
               {
                   flag=result2[i]/10;
                   result2[i]%=10;
               }
               else
               flag=0;
           }
       }
       mark=mark*markN;
       int sum=0;
       for(int h=0;h<200;h++)
       {
           if(result2[h]==0)
           sum++;
       }
       if(sum==200)
       {
           cout<<0<<endl;
       }
       else
       {
       for(i=0;i<=199;i++)
       if(result2[i]!=0||i==200-mark)
       break;

       int k1=199;
       if(mark!=0)
       {
           for(k1=199;k1>=200-mark;k1--)
           if(result2[k1]!=0)
           break;
       }
       for(j=i;j<=k1;j++)
       {
              if(j==200-mark)
              cout<<"."<<result2[j];
              else
              cout<<result2[j];
       }
      cout<<endl;
       }
      memset(result2,0,sizeof(result2));
      memset(R1,0,sizeof(R1));
      memset(R,0,sizeof(R));
      memset(result1,0,sizeof(result1));
    }
    return 0;
}
          
