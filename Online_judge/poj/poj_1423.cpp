#include <stdio.h>
#include <math.h>

int n;
const double e = 2.7182818284590452354, pi = 3.141592653589793239;

double f( int a )
{
    return log10( sqrt( 2 * pi * a ) ) + a * log10( a / e );
}

int main()
{
    int cas, ans;
    double i, s;
    
    scanf( "%d", &cas );
    
    while( cas-- )
    {
        scanf( "%d", &n );
        if( n < 100000 )
        {
            for( s=0, i=1; i<=n; i++ )
                s += log10( i );
        }
        else s = f( n );
        ans = (int)s;
        if( ans <= s )
            ans++;
        
        printf( "%d\n", ans );
    }
    
    return 0;
}
