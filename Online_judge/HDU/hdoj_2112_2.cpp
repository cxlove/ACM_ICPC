#include<stdio.h>  

#include<string.h>  

char word[160][300] = {0},a[300],b[300],start[300],end[300],p,q;  

int map[160][160],c,des[160],dis[160],n;  

int inf = 0x7fffffff;  

int obtain( char str[] )//将地名用数字代替  

{  

    int f = 1,pos = 0;  

    for( int i = 2 ; i <= c; ++i )  

    {  

         if( !strcmp( word[i],str ) )  

         {  

             f = 0;  

             pos = i;  

             break;  

         }  

     }  

     if( f )  

     {  

         ++c;  

         strcpy( word[c],str );  

         pos = c;  

     }  

     return pos;  

}  

int Dijkstra(  )  

{  

    int i ;  

    dis[p] = 0;  

    for(  i = 1; i <= c; ++i )  

    {  

         int min = inf,pos = 0;  

         for( int j = 1; j <= c; ++j )  

         {  

              if( !des[j] )  

                  if( dis[j] != inf )  

                      if( min > dis[j] )  

                      {  

                          min = dis[j];  

                          pos = j;  

                      }  

          }  

          des[pos] = 1;  

          if( des[q] )  

              return dis[q];  

          for( int j = 1; j <= c; ++j )  

          {  

               int t;  

               if( !des[j] )  

                   if( map[pos][j] != inf )  

                       if( ( t = map[pos][j] + dis[pos] ) < dis[j] )  

                           {  

                               dis[j] = t;  

                               }  

           }  

     }  

     if( i > c )  

         return -1;  

}  

int main( )  

{  

    while( scanf( "%d",&n ) , n != -1 )  

    {  

           c = 0;  

           memset( word,160,sizeof( word[0][0] ) );  

           for( int i = 0; i <= 155; ++i )  

           {  

                for( int j = 0; j <= 155; ++j )  

                     map[i][j]  = inf;  

                des[i] = 0;  

                dis[i] = inf;  

            }  

           scanf( "%s%s",start,end );  

           for( int i = 1; i <= n; ++i )  

           {  

                int x,y,val;  

                scanf( "%s%s%d",a,b,&val );  

                x = obtain( a );  

                y = obtain( b );  

                if( val < map[x][y] && x != y )  

                    map[x][y] = map[y][x] = val;  

            }  

            p = obtain ( start );  

            q = obtain ( end );  

            if( q == p )  

            {  

                printf( "0\n" );  

                continue;  

            }  

            int res  = Dijkstra();  

            printf( "%d\n",res );  

           }  

    return 0;  

} 
