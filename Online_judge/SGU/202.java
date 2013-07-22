import java.util.*;
import java.io.*;
import java.math.*;
public class Solution {
  public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task solver = new Task();
		solver.solve(in, out);
		out.close();
	}
}
class Task{
	static int dp [][] = new int [70][70];
	static int pre[][] = new int [70][70];
	static int inf = 100000009;
	static int N,M;
	Stack s[] = new Stack [70];
	int dfs(int n,int m){
		if(dp[n][m]!=-1)
			return dp[n][m];
		dp[n][m]=inf;
		for(int i=1;i<n;i++){
			int t=dfs(i,m)*2+dfs(n-i,m-1);
			if(t<dp[n][m]){
				dp[n][m]=t;
				pre[n][m]=i;
			}
		}
		return dp[n][m];
	}
	void move(int u,int v){
		System.out.print("move " + s[u].peek() + " from " + u + " to " + v);
		if(!s[v].empty())
			System.out.print(" atop " + s[v].peek());
		s[v].push(s[u].pop());
		System.out.println();
	}
	void gao(int u,int v,int n,int m){
		if(n==1){
			move(u,v);
			return ;
		}
		if(s[u].size()<pre[n][m]) return ;
		for(int mid=1;mid<=M;mid++){
			if(mid==u||mid==v) continue;
			if(s[mid].empty()||((int)(s[mid].peek())>(int)(s[u].elementAt(s[u].size()-pre[n][m])))){
				gao(u,mid,pre[n][m],m);
				gao(u,v,n-pre[n][m],m-1);
				gao(mid,v,pre[n][m],m);
				return ;
			}
		}
	}
	void solve(InputReader in,PrintWriter out){
		N=in.nextInt();M=in.nextInt();
		for(int i=1;i<=N;i++)
			for(int j=1;j<=M;j++)
				dp[i][j]=-1;
		for(int i=1;i<=N;i++)
			dp[i][1]=dp[i][2]=inf;
		dp[1][1]=0;
		for(int i=2;i<=M;i++)
			dp[1][i]=1;
		dfs(N,M);
		System.out.println(dp[N][M]);
		for(int i=1;i<=M;i++)
			s[i]=new Stack();
		for(int i=N;i>=1;i--)
			s[1].push(i);
		gao(1,M,N,M);
	}
}
class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }
}
