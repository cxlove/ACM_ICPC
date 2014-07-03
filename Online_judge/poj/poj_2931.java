import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
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
	static int N = 55;
	static int M = 105;
	static int f[] = new int [M];
	static BigInteger pow[] = new BigInteger[M];
	BigInteger surreal_number (int n) {
		BigInteger ret = BigInteger.ZERO;
		int k = 103 , i = 0;
		while (i < n && f[i] == f[0]) {
			if (f[i] == 0) ret = ret.add (pow[k]);
			else ret = ret.subtract (pow[k]);
			i ++;
		}
		while (i < n) {
			k = k - 1;
			if (f[i] == 0) ret = ret.add (pow[k]);
			else ret = ret.subtract(pow[k]);
			i ++;
		}
		return ret;
	}
	BigInteger gao (InputReader cin) {
		int a = cin.nextInt () , b = cin.nextInt () , c = cin.nextInt();
		for (int i = 0 ; i < a ; i ++) {
			String s = cin.next();
			if (s.charAt(0) == 'W') f[i] = 0;
			else f[i] = 1;
		}
		BigInteger ans = surreal_number (a);
		for (int i = 0 ; i < b ; i ++) {
			String s = cin.next();
			if (s.charAt(0) == 'W') f[i] = 0;
			else f[i] = 1;
		}
		ans = ans.add (surreal_number (b));
		for (int i = 0 ; i < c ; i ++) {
			String s = cin.next();
			if (s.charAt(0) == 'W') f[i] = 0;
			else f[i] = 1;
		}
		ans = ans.add (surreal_number(c));
		return ans;
	}
    void solve (InputReader cin , PrintWriter cout) {  
    	pow[0] = BigInteger.ONE;
    	for (int i = 1 ; i < M ; i ++)
    		pow[i] = pow[i - 1].multiply(BigInteger.valueOf(2));
    	String Test = cin.next();int cas = cin.nextInt();
    	BigInteger a1 = gao (cin) , a2 = gao (cin);
    	cout.print(Test + " " +  cas + ": ");
    	cout.println (a1.compareTo(a2) >= 0 ? "Yes" : "No");
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