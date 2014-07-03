#include<iostream>
#include <cstdio>
#include <climits>
#define MAX_LINE 18
#define MAX_T 9
#define MAX_SN 0X40000
using namespace std;
int exp[MAX_LINE+1]={0,0X1,0X2,0X4,0X8,0X10,0X20,0X40,0X80,
                     0X100,0X200,0X400,0X800,0X1000,0X2000,0X4000,
                     0X8000,0X10000,0X20000};
int tri[MAX_T+1][3]=
{
    {0,0,0},{exp[1],exp[2],exp[3]},{exp[4],exp[5],exp[8]},
    {exp[3],exp[5],exp[6]},{exp[6],exp[7],exp[9]},
    {exp[10],exp[11],exp[16]},{exp[8],exp[11],exp[12]},
    {exp[12],exp[13],exp[17]},{exp[9],exp[13],exp[14]},
    {exp[14],exp[15],exp[18]}   
};
int linePID[MAX_LINE+1][2]=
{
    {0,0},{1,2},{1,3},{2,3},{2,4},{2,5},{3,5},{3,6},{4,5},{5,6},
    {4,7},{4,8},{5,8},{5,9},{6,9},{6,10},{7,8},{8,9},{9,10}   
};
int f[MAX_SN+5],caseN,stepN;
int takeStep(int state,int lineEXP)
{
        int num=0,count,triID;
        for(int i=1;i<=MAX_T;i++)
        {
             count=0,triID=-1;
             for(int j=0;j<3;j++)
             {
                     if(tri[i][j]==lineEXP)
                     triID=j;
                     else if(state&tri[i][j])
                     count++;      
             }
             if(triID==-1)continue;
             if(count==2)num++;          
        }
        return num;
}
int dpSolve(int curState)
{
    if(f[curState]!=INT_MIN)
    return f[curState];
    int maxVal=INT_MIN,i,curVal,extra;
    for(i=1;i<=MAX_LINE;i++)
    {
          curVal=0;
          if(!(curState&exp[i]))
          {
                 extra=takeStep(curState,exp[i]);
                 if(extra>0)
                 curVal=extra+dpSolve(curState|exp[i]);
                 else
                 curVal=extra-dpSolve(curState|exp[i]);
                 if(curVal>maxVal)
                 maxVal=curVal;                     
          }                       
    }  
    f[curState]=maxVal;
    return maxVal;
}
int main()
{
    // freopen ("input.txt" , "r" , stdin);
    int cn,i,j,from ,to,curVal,curState,totalVal,which;
    for(i=0;i<=MAX_SN;i++)
    {
         f[i]=INT_MIN;                     
    }
    f[0X3ffff]=0;
    cin >>caseN;
    for(cn=1;cn<=caseN;cn++)
    {
       totalVal=0,curState=0,which=1;
       cin >>stepN;
       for(i=1;i<=stepN;i++)
       {
          curVal=0;
          cin >>from>>to;
          for(j=1;j<=MAX_LINE;j++)
          {
               if(linePID[j][0]==from&&
                  linePID[j][1]==to)
               {
                   curVal=takeStep(curState,exp[j]);
                   curState|=exp[j];
                   break;                    
               }                       
          } 
          if(curVal>0)totalVal+=which*curVal;
          else which*=-1;
       }    
       // cout << which << " " << totalVal << endl;
       char who;
       int resp=totalVal+which*dpSolve(curState);
       who=(resp>0)?'A':'B';
       // cout << resp << endl;
       cout <<"Game "<<cn<<": "<<who<<" wins."<<endl;                
    }
   
   //system("pause");
    return 0;   
}