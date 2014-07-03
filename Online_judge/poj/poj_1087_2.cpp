#include <iostream>
#include <string>
#include <cstring>
#define MAX 500
using namespace std;
int pnum;
int dnum; 
int anum; 
string plug[MAX]; 
string type[MAX]; 
string dev[MAX]; 
string inadapt[MAX]; 
string outadapt[MAX]; 
bool map[MAX][MAX]; 
bool state[MAX];
bool flag[MAX]; 
int  res[MAX]; 
void DFS(string type, int j, int d)
{
 int i,k;
 string temp;
 for(i = 0; i< anum; i++)
  if(type == outadapt[i] && flag[i] == true)
  {
   flag[i] = false;
   temp= inadapt[i];
   for(k = 0; k< pnum; k++)
   {
    if(temp == plug[k])
     map[d][k] = true;
   }
   DFS(inadapt[i], i,d);
  }

}

bool find(int i)
{
 int j;
 for(j = 0; j< pnum; j++)
  if(map[i][j] == true && state[j] == false)
  {
   state[j] = true;
   if(res[j] == -1 || find(res[j]) == true)
   {
    res[j] = i;
    return true;
   }
  }
  return false;
}


int main()
{ 
 
  int i,j,match;
  string temp;
  memset(map, false, sizeof(map));
  for(i=0 ;i< MAX; i++)
   res[i] = -1;

  cin>>pnum;
  for(i=0; i<pnum; i++)  
   cin>>plug[i];  
  cin>>dnum;
  for(i=0; i<dnum; i++) 
   cin>>dev[i]>>type[i];
  cin>>anum;
  for(i=0; i<anum; i++) 
   cin>>outadapt[i]>>inadapt[i];


  for(i = 0; i<dnum; i++)
   for(j = 0; j< anum; j++)
    if(type[i] == outadapt[j])
    {
     memset(flag, true, sizeof(flag));
     DFS(outadapt[j],j,i);
    }

  for(i=0; i<dnum; i++)
   for(j=0; j< pnum; j++)
    if(type[i] == plug[j])
     map[i][j] = true;

  match = 0;
  for(i = 0; i<dnum; i++)
  {
   memset(state, false , sizeof(state));
   if(find(i))
    match++;
  }
  cout<<dnum-match<<endl;
 
 return 0;
}
