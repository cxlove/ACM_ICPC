#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n;
bool len[100];
bool flag[1000];
string ch;
bool cmp(const string &a,const string &b)
{
	return a.length()<b.length();
}
bool check(string s1,string s2)
{
	int no=0,i=0,j=0;
	while(j<s2.length())
	{
		if(s1[i]==s2[j])
		{
			i++;
			j++;
		}
		else
		{
			j++;
			no++;
		}
	}
	if(no==1)  return true;
	else  return false;
}
int main()
{
	string s;
	memset(len,false,sizeof(len));
	memset(flag,false,sizeof(flag));
	cin>>n;cin>>ch;
	vector<string>word;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		len[s.length()]=true;
		word.push_back(s);		
	}	
	for(int i=0;i<n;i++)
	{
		if(word[i]==ch)
		{
			flag[i]=true;
		}
	}
	int i;
	for( i=ch.length()+1;;i++)
	{
		if(len[i]==false)  break;
		
		bool mark=false;
		for(int j=0;j<n;j++)
		{
			if(word[j].length()!=i)  continue;
			for(int k=0;k<n;k++)
			{
				if(word[j].length()==word[k].length()+1&&flag[k])
				{  
					if(check(word[k],word[j]))
					{
						flag[j]=true;
						mark=true;
						break;
					}
				}
			}
			
		}	
		if(!mark)
			break;
	}
	for(int j=0;j<n;j++)
	 if(flag[j]&&word[j].length()==i-1)
	    cout<<word[j]<<endl;
//	system("pause");
	return 0;
}
