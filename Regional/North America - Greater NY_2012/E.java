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
        int t = 1;
        Task solver = new Task();
        while ((t --) > 0)
            solver.solve(in, out);
        out.close();
    }
}
class Node {
    BigInteger a , b;
    Node () {}
    Node (BigInteger _a , BigInteger _b) {
        a = _a; b = _b;
    }
    Node gao () {
        BigInteger c = a , d = b;
        BigInteger gcd = c.gcd(d);
//        System.out.println (a + " " + b + " " + gcd);
        c = c.divide (gcd);
        d = d.divide (gcd);
        return new Node (c , d);
    }
    Node mut (Node c) {
        Node ans = new Node (a.multiply(c.a) , b.multiply(c.b));
        return ans.gao ();
    }
    Node add (Node c) {
        Node ans = new Node (b.multiply(c.a).add (a.multiply(c.b)) , b.multiply(c.b));
        return ans.gao ();
    }
    void out () {
        if (a.compareTo(BigInteger.ZERO) == 0) System.out.println (0);
        else if (b.compareTo(BigInteger.ONE) == 0) System.out.println(a);
        else System.out.println (a + "/" + b);
    }
}
class Task{ 
    static int N = 400;
    Node f[][] = new Node [N + 5][N + 5];
    void solve (InputReader cin , PrintWriter cout) {
        for (int i = 0 ; i <= N ; i ++) {
            for (int j = 1 ; j <= i + 1 ; j ++)
                f[i][j] = new Node ();
        }
        f[0][1] = new Node (BigInteger.ONE , BigInteger.ONE);
        for (int i = 1 ; i <= N ; i ++) {
            f[i][1] = new Node (BigInteger.ZERO , BigInteger.ONE);
            for (int j = 2 ; j <= i + 1 ; j ++) {
                f[i][j] = f[i - 1][j - 1].mut (new Node (BigInteger.valueOf (i) , BigInteger.valueOf(j)));
                f[i][j] = f[i][j].gao ();
                f[i][1] = f[i][1].add (f[i][j]);
            }
            f[i][1].a = f[i][1].b.subtract(f[i][1].a);
            f[i][1] = f[i][1].gao ();
        }
        int t = cin.nextInt ();
        for (int i = 1 ; i <= t ; i ++) {
            int cas = cin.nextInt ();
            int m = cin.nextInt() , k = cin.nextInt ();
            System.out.print(cas + " ");
            f[m][k].out ();
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