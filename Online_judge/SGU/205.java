import java.util.*;
import java.io.*;
import java.math.*;
public class Main {
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
	static int inf = 1000000009;
	void solve(InputReader in,PrintWriter out){
		int n = in.nextInt();
		int x[] = new int [1005];
		int a[][] = new int [130][130];
		int pre[][] = new int [1005][130];
		int dp[][] = new int [1005][130];
		for (int i = 0 ; i < n ; i ++)
			x[i] = in.nextInt();
		int row = in.nextInt(), col = in.nextInt();
		for (int i = 0 ; i < row ; i ++){
			for (int j = 0 ; j < col ; j ++){
				a[i][j] = in.nextInt();
			}
		}
		for (int i = 0 ; i <= n ; i ++){
			for (int j = 0 ; j < col ; j ++){
				dp[i][j] = inf;
			}
		}
		dp[0][0]=0;
		for (int i = 0 ; i < n ;i ++){
			for (int j = 0 ; j < col ; j ++){
				for(int k = 0 ; k < col ; k ++){
					int r = j % row;
					if(dp[i][j] + Math.abs(x[i] - a[r][k]) < dp[i + 1][k]){
						dp[i + 1][k] = dp[i][j] + Math.abs(x[i] - a[r][k]);
						pre[i + 1][k] = j;
					}
				}
			}
		}
		int ans = inf, idx = -1;
		for (int i = 0; i < col ; i ++){
			if (dp[n][i] < ans){
				ans = dp[n][i];
				idx = i;
			}
		}
		out.println(ans);
		Vector ret = new Vector ();
		while (ret.size() < n){
			ret.addElement(idx);
			idx = pre[n - ret.size() + 1][idx]; 
		}
		for (int i = ret.size() - 1 ; i > 0 ; i --){
			out.print(ret.elementAt(i)+" ");
		}
		out.println(ret.elementAt(0));
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
    public long nextLong() {
    	return Long.parseLong(next());
    }
    public double nextDouble() {
    	return Double.parseDouble(next());
    }
}
