#include <iostream>
#include <algorithm>

using namespace std;

struct A
{
    int p, m;
};

bool cmp( A x, A y );

int main()
{
    int v, n;
    while( cin >> v && v )
    {
        cin >> n;
        A treasure[n];
        for( int i = 0; i < n; ++i )
        {
            cin >> treasure[i].p >> treasure[i].m;
        }
        sort( treasure, treasure + n, cmp );
        int sum = 0;
        for( int i = 0; i < n && v > 0; ++i )
        {
            if( treasure[i].m >= v )
            {
                sum += treasure[i].p * v;
                v = 0;
            }
            else
            {
                sum += treasure[i].m * treasure[i].p;
                v -= treasure[i].m;
            }
        }
        cout << sum << endl;
    }
    return 0;
}

bool cmp( A x, A y )
{
    return x.p > y.p;
}