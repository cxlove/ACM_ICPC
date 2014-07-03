#include <iostream>
#include <algorithm>
#include <cstdlib>
#include<stdio.h>
using namespace std;

const int n = 9;
int board[9][9];
char ch[10];

bool ok(int x, int y)
{
        // 3 * 3
        for (int i = x / 3 * 3; i < x / 3 * 3 + 3; ++i)
        {
                for (int j = y / 3 * 3; j < y / 3 * 3 + 3; ++j)
                {
                        if (x == i && y == j)
                                continue;
                        if (board[x][y] == board[i][j])        // the number has been used
                                return false;
                }
        }
        int temp = board[x][y];
        // check the row
        for (int j = 0; j < n; ++j)
        {
                if (j == y)
                        continue;
                if (board[x][j] == temp)
                        return false;
        }
        // check the column
        for (int i = 0; i < n; ++i)
        {
                if (i == x)
                        continue;
                if (board[i][y] == temp)
                        return false;
        }
        return true;        // ok
}

int dfs(int location)
{
        if (location == -1)
                return 1;
        
        if (board[location / n][location % n] != 0)        // has number
                return dfs(location - 1);
        else
        {
                for (int i = 1; i <= n; ++i)        // try
                {
                        board[location / n][location % n] = i;
                        if (ok(location / n, location % n))
                        {
                                if (dfs(location - 1))
                                        return 1;
                        }
                        board[location / n][location % n] = 0;
                }
        }
        return 0;
}

int main()
{
        int nCases;
        scanf("%d", &nCases);
        while (nCases--)
        {
                for (int i = 0; i < n; ++i)
                {
                        scanf("%s", ch);
                        for (int j = 0; j < n; ++j)
                        {
                                board[i][j] = ch[j] - '0';
                        }
                }

                dfs(80);
                
                for (int i = 0; i < n; ++i)
                {
                        for (int j = 0; j < n; ++j)
                        {
                                printf("%d", board[i][j]);
                        }
                        printf("\n");
                }
        }
        
        return 0;
}

