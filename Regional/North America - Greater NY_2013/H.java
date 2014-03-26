import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
import java.math.*;
public class H{
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        int t = 1;
        Task solver = new Task();
        while ((t --) > 0)
            solver.solve(in, out);
        out.close();
    }
}
class Task{
    static int N = 100005;
    BigInteger powmod (int a , int b) {
        BigInteger ret = BigInteger.valueOf (1);
        BigInteger A = BigInteger.valueOf (a);
        while (b > 0) {
            if (b % 2 == 1) ret = ret.multiply (A);
            A = A.multiply (A);
            b = b / 2;
        }
        return ret;
    }
    BigInteger com (int n , int m) {
        m = Math.min (m , n - m);
        BigInteger ret = BigInteger.valueOf (1);
        for (int a = n , b = m ; b > 0 ; a -- , b --) {
            ret = ret.multiply (BigInteger.valueOf (a));
        }
        for (int b = m ; b > 0 ; b --) {
            ret = ret.divide (BigInteger.valueOf (b));
        }
        return ret;
    }
    void solve (InputReader cin , PrintWriter cout) {
        int t = cin.nextInt ();
        while ((t --) > 0) {
            int id = cin.nextInt () , p = cin.nextInt () , n = cin.nextInt () , m = cin.nextInt ();
            cout.print (id + " ");
            if (m > n) cout.println (0);
            else {
                BigInteger tmp = powmod (p ,  n - m).multiply (com (n , m));
                cout.println (tmp);
            }
        }
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