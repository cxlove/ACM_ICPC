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
    
    void solve (InputReader cin , PrintWriter cout) {
        BigInteger n = cin.nextBigInteger();
        int k = cin.nextInt();
        BigInteger ans = BigInteger.ZERO;
        BigInteger t = BigInteger.valueOf(1 << k);
        n = n.divide(BigInteger.valueOf(1 << (k - 1)));
        while (!n.equals(BigInteger.ZERO)) {
            ans = ans.add(n.add(BigInteger.ONE).divide(BigInteger.valueOf(2)));
            n = n.divide(t);
        }
        cout.println(ans);
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