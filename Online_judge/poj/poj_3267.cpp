#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	//ifstream cin("a.txt");
	int w, l, len, d[320], minx;
	char ch[320];
	string str[630];
	cin>>w>>l;
	for (int i = 1; i <= l; i++)
		cin>>ch[i];
	for (int i = 1; i <= w; i++)
		cin>>str[i];
	memset(d, 0, sizeof(d));
	for (int j = 1; j <= l; j++)
	{
		minx = 100000;
		for (int i = 1; i <= w; i++)
		{
			len = (int)str[i].length();
			int n = j, temp = 0;
			for (int k = len - 1; k >= 0; k--)
			{
				while (ch[n] != str[i][k])
				{
					n--;
					if (n <= k - 1)break;
				}
				if (n <= k - 1)
				{
					temp = 1;break;
				}
				n--;
			}
			if (temp)continue;
			minx = min(minx, d[n] + (j - n) - len);
		}
		d[j] = min(d[j - 1] + 1, minx);
	}
	printf("%d\n", d[l]);
	return 0;
}
