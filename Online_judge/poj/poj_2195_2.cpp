#include <iostream>  

#include <cstring>  

#include <cstdio>  

using namespace std;  

   

const int N = 105;  

const int INF = 1000000000;  

   

int E[N][N];  

bool map[N][N];  

bool vis_x[N], vis_y[N];  

int lx[N], ly[N];  

   

int match[N];  

char maze[N][N];  

int row, col;  

int man_count, house_count;  

int slack;  

   

int abs(int a)  

{  

    if (a < 0)  

        return -a;  

    return a;  

}  

   

bool dfs(int u, int n)  

{  

    int tmp;  

    vis_x[u] = true;  

   

    for (int i = 0; i < n; i++)  

    {  

        if (!vis_y[i])  

        {  

            tmp = lx[u] + ly[i] - E[u][i];  

            if (tmp == 0)  

            {  

                vis_y[i] = true;  

                if (match[i] == -1 || dfs(match[i], n))  

                {  

                    match[i] = u;  

                    return true;  

                }  

            }  

            else 

                slack = max(tmp, slack);  

        }  

    }  

   

    return false;  

}  

   

//最小权匹配  

void KM(int n)  

{  

    for (int i = 0; i < n; i++)  

    {  

        lx[i] = INF; //-inf  

        ly[i] = 0;  

        for (int j = 0; j < n; j++)  

            lx[i] = min(lx[i], E[i][j]); //若求最大权匹配用max  

    }  

    memset(match, -1, sizeof(match));  

    for (int i = 0; i < n; i++)  

    {     

        while (1)  

        {  

            memset(vis_x, false, sizeof(vis_x));  

            memset(vis_y, false, sizeof(vis_y));  

               

            slack = -INF; //inf  

            if (dfs(i, n))  

                break;  

   

            for (int i = 0; i < n; i++)  

            {  

                if (vis_x[i]) lx[i] -= slack;  

                if (vis_y[i]) ly[i] += slack;  

            }  

        }  

    }  

       

}  

   

int main()  

{  

    while (scanf("%d%d", &row, &col))  

    {  

        if (row == 0 && col == 0)  

            break;  

   

        memset(E, 0, sizeof(E));  

        man_count = 0;  

        house_count = 0;  

        for (int i = 0; i < row; i++)  

        {  

            getchar();  

            for (int j = 0; j < col; j++)  

                scanf("%c", &maze[i][j]);  

        }  

   

        //构图  

        for (int i = 0; i < row; i++)  

            for (int j = 0; j < col; j++)  

                if (maze[i][j] == 'm')  

                {  

                    house_count = 0;  

                    for (int a = 0; a < row; a++)  

                        for (int b = 0; b < col;  b++)  

                            if (maze[a][b] == 'H')  

                                E[man_count][house_count++] = abs(a-i) + abs(b-j);  

   

                    man_count++;  

                }  

   

   

        KM(man_count);  

        int ans = 0;  

        for (int i = 0; i < man_count; i++)  

            ans += E[match[i]][i];  

   

        printf("%d\n", ans);  

    }  

    return 0;  

} 

