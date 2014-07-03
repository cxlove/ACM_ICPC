#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<algorithm>
using namespace std;

#define lint __int64
lint ans[1000], cnt;
lint G, L, a, b, sq;

lint gcd(lint a,lint b)
{
    if ( b == 0 )
        return a;
    return gcd ( b, a % b );
}


lint mod_mult ( lint a, lint b, lint n )
{
    lint ret = 0;
    a = a % n;
    while ( b >= 1 )
    {
        if ( b & 1 )
		{
            ret += a;
            if ( ret >= n ) ret -= n;
        }
        a = a << 1;
        if ( a >= n ) a -= n;
        b = b >> 1;
    }
    return ret;
}


lint mod_exp ( lint a, lint b, lint n )
{
    lint ret = 1;
    a = a % n;
    while ( b >= 1 )
    {
        if ( b & 1 )
            ret =  mod_mult(ret,a,n);
        a = mod_mult(a,a,n);
        b = b >> 1;
    }
    return ret;
}


bool witness ( lint a, lint n )
{
	int i, t = 0;
    lint m = n - 1, x, y;
    while ( m % 2 == 0 ) { m >>= 1; t++; }
    x = mod_exp (a, m, n);

    for ( i = 1; i <= t; i++ )
    {
        y = mod_exp ( x, 2, n );
        if( y==1 && x!=1 && x!=n-1 )
            return true;
        x = y;
    }
    if ( y != 1 ) return true;
    return false;
}

bool miller_rabin ( lint n, int times = 10 )
{
	if ( n == 2 ) return true;
    if ( n == 1 || n % 2 == 0 ) return false;

    srand ( time(NULL) );
    for ( int i = 1; i <= times; i++ )
    {
        lint a = rand() % (n-1) + 1;
        if ( witness(a,n) ) return false;
    }
    return true;
}

lint rho ( lint n, int c )
{
    lint i, k, x, y, d;
    srand ( time(NULL) );
    i = 1;  k = 2;
    y = x = rand() % n;
    while ( true )
    {
        i++;
        x = (mod_mult(x,x,n)+c) % n;
        d = gcd ( y - x, n );
        if ( d > 1 && d < n ) return d;
        if ( y == x ) break;
        if ( i == k ) { y = x; k *= 2; }
	}
	return n;
}


void pollard ( lint n, int c )
{
    if ( n == 1 )  return;
    if ( miller_rabin(n) ) { ans[cnt++] = n; return; }
    lint m = n;
    while ( m >= n )
        m = rho ( m, c-- );
    pollard ( m, c );
    pollard ( n / m, c );
}

void choose ( lint s, lint val )
{
    if ( s >= cnt )
    {
        if ( val > a && val <= sq )
            a = val;
        return;
    }
    choose ( s + 1, val );
    choose ( s + 1, val * ans[s] );
}

int main()
{
    while ( scanf("%I64d%I64d",&G,&L) != EOF )
    {
        if ( L == G )
        {
            printf("%I64d %I64d\n",L,G);
            continue;
        }
        L /= G;
        cnt = 0;
        pollard ( L, 107 );
        sort ( ans, ans + cnt );
        int i, j = 0;
        for ( i = 1; i < cnt; i++ )
        {
            while ( ans[i-1] == ans[i] && i < cnt )
                ans[j] *= ans[i++];
            if ( i < cnt ) ans[++j] = ans[i];
        }

        cnt = j + 1; a = 1;
        sq = (lint)sqrt(L+0.0);
        choose ( 0, 1 );
        printf("%I64d %I64d\n", a*G, L/a*G);
    }
    return 0;
}
