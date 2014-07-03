//Memory Time 
//476K    0MS 

#include<iostream>
#include<math.h>
using namespace std;

const int size=31269;

unsigned a[size];   //a[i] 表示第i组数字序列的长度
unsigned s[size];   //s[i] 表示前i组数字序列的长度
                     //第i组存放的数字序列为 [1,i]的正整数，但第i组的长度不一定是i
                     //例如数字13要被看做1和3两个位，而不是一个整体

/*打表，预先获取第2147483647个位的序列分组情况*/

void play_table(void)
{
	a[1]=s[1]=1;
	for(int i=2;i<size;i++)
	{
		a[i]=a[i-1]+(int)log10((double)i)+1;  //log10(i)+1 表示第i组数字列的长度 比 第i-1组 长的位数
		s[i]=s[i-1]+a[i];      //前i组的长度s[i] 等于 前i-1组的长度s[i-1] + 第i组的长度a[i]
	}                          //log()是重载函数，必须对int的i强制类型转换，以确定参数类型
	return;
}

/*计算序列第n个位置上的数字*/

int compute(int n)
{
	int i=1;
	while(s[i]<n)
		i++;    //确定整个数字序列的第n个位置出现在第i组

	int pos=n-s[i-1];   //pos为 整个数字序列的第n个位置 在 第i组中的下标值

	int len=0;
	for(i=1;len<pos;i++)  //从第1组开始遍历第i前的每一个组，利用log10(i)+1递推第i组的长度
		len+=(int)log10((double)i)+1;  //len为第i组(n所在的组)的长度

	return (i-1)/(int)pow((double)10,len-pos)%10;  
	       //之所以i-1，是因为前面寻找第i组长度时，i++多执行了一次
	       //i=i-1 此时i刚好等于第n位个置上的数 （数是整体，例如123一百二十三，i刚好等于123，但n指向的可能是1，2或3）
	       //pos为n指向的数字在第i组中的下标值
	       //len为第i组的长度
	       //那么len-pos就是第i组中pos位置后多余的数字位数
	       //则若要取出pos位上的数字，就要利用(i-1)/pow(10,len-pos)先删除pos后多余的数字
	       //再对剩下的数字取模，就可以得到pos
	       //例如要取出1234的2，那么多余的位数有2位：34。那么用1234 / 10^2，得到12，再对12取模10，就得到2

}          //pow()是重载函数，必须对int的i强制类型转换，以确定参数类型

int main(void)
{
	play_table();

	int test;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		cout<<compute(n)<<endl;
	}
	return 0;
}