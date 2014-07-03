import java.util.*;
import java.io.*;
import java.math.*;
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		int t = in.nextInt();
		Task solver = new Task();
		while ((t --) > 0)
			solver.solve(in, out);
		out.close();
	}
}
class Task{
	static int N = 10005;
	int next[] = new int [N];
	void get_next (String s , int l) {
		int i = 0 , j = -1;
		next[0] = j;
		while (i < l) {
			if (j == -1 || s.charAt(i) == s.charAt(j)) {
				i ++ ; j ++;
				if (i < l && j < l) {
					if (s.charAt(i) != s.charAt(j)) next[i] = j;
					else next[i] = next[j];
				}
				else next[i] = j;
			}
			else j = next[j];
		}
	}
	int kmp (String s , int ls , String e , int le) {
		int i = 0 , j = 0 , cnt = 0;
		while (i < ls && j < le) {
			if (i == -1 || s.charAt(i) == e.charAt(j)) {
				i ++ ; j ++ ;
				if (i == ls) {
					cnt ++;
					i = next[i];
				}
			}
			else i = next[i];
		}
		return cnt;
	}
	void solve (InputReader cin , PrintWriter cout) {
		String s = cin.next() , e = cin.next();
		get_next (s , s.length());
		cout.println(kmp (s , s.length() , e , e.length()));
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
    public BigInteger nextBigInteger() {
    	return new BigInteger(next());
    }
}