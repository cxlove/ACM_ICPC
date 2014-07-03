import java.util.Arrays;
import java.util.Scanner;

public class Main {
    void flood(int x, int y, int c) {
        if (x < 1 || y < 1 || x > n || y > n)
            return;
        if (vis[x][y] == 1)
            return;
        if (map[x][y]!=c) {
            vis[x][y]=2;
            return;
        }
        vis[x][y] = 1;
        flood(x - 1, y, c);
        flood(x + 1, y, c);
        flood(x, y - 1, c);
        flood(x, y + 1, c);
    }
    boolean color[] = new boolean[10];
    int h() {
        int res = 0;
        Arrays.fill(color, false);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (vis[i][j]!=1&&!color[map[i][j]]) {
                    res++;
                    color[map[i][j]] = true;
                }
        return res;
    }
    int lim;
    boolean flag, de;
    int dfs(int d) {
        
        int h = h();
        if (h == 0) {
            flag = true;
            return d;
        }
        if (d+h>lim)
            return d + h;
        int res = 1 << 28;    
        int tvis[][] = new int[10][10];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)     
                tvis[i][j] = vis[i][j];
        for (int k = 0; k < 6; k++) {
            int cnt=0;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (vis[i][j] == 2&&map[i][j]==k){
                        flood(i,j,k);
                        cnt++;
                    }
            if(cnt==0)
                continue;
            int tp = dfs(d + 1);
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++) 
                    vis[i][j] = tvis[i][j];
            if (flag)
                return tp;
            res = Math.min(tp, res);
        }
        return res;
    }

    int map[][] = new int[10][10], n;
    int vis[][] = new int[10][10];
    Scanner scan = new Scanner(System.in);
    void work() {
        flag = false;
        for (int i = 1; i <= n; i++)
            Arrays.fill(vis[i], 0);
        flood(1,1,map[1][1]);
        lim = h();
        while (!flag) 
            lim = dfs(0);
        System.out.println(lim);
    }
    void run() {
        while (true) {
            n = scan.nextInt();
            if (n == 0)
                break;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    map[i][j] = scan.nextInt();
            work();
        }
    }
    public static void main(String[] args) {
        new Main().run();
    }
}
