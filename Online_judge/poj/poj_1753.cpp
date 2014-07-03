#include <iostream>
using namespace std;
long flip[16]={0x105,0x415,0x1054,0x4050,0x10501,0x41504,0x105410,0x405040,0x1050100,0x4150400,
                       0x10541000,0x40504000,0x5010000,0x15040000,0x54100000,0x50400000 } ;
long add[16]={0x1,0x4,0x10,0x40,0x100,0x400,0x1000,0x4000,0x10000,
                       0x40000,0x100000,0x400000,0x1000000,0x4000000,0x10000000,0x40000000};
int step=16 ;
int search(long square ,int dep ,int fliped) // 递归搜索全部状态。
{
 square &= 1431655765 ;  // 这里是取模，防止+add[i]时进位。
 if(square==0 || square==1431655765)  
 { if(fliped<step) step=fliped; }
 if(dep==16) return 0;
 search( square,dep+1,fliped)  ;
 search( square+=flip[dep],dep+1,fliped+1) ;
 return 0;
}
int  main()
{
 long square=0 ; // 表示 棋盘阵列 。
 char c ;
 for(int i=0;i<16;) 
 {
  c=getchar();
  if(c=='w')  c=0; else if(c=='b') c=1; else continue ;
  square += c*add[i++] ;
 }
 search(square,0,0);    
 if ( step==16 ) printf("Impossible\n");
 else printf("%d\n",step);
 return 0;
}