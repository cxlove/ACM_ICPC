import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
import java.math.*;
public class Main {
    static Scanner cin = new Scanner (System.in);
    static BigInteger cnt[][] = new BigInteger [26][105];
    static String to[] = {"ACM-ICPC" , "BIDU" , "consonant:BCDFGHJKLMNPQRSTVXZWY" , "D41D8CD98F00B204E9800998ECF8427E"
            , "2.718281828459..." , "0xFACEB00C" , "1E100.net" , "\\Huge{String}" , "InternationalCollegiateProgrammingContest" 
            , "JinKeLa" , "KeepItSimpleStupid" , "1000mL" , "Micro$oftCorp" , "" , "Oops" , "pneumonoultramicroscopicsilicovolcanoconiosis" 
            , "A" , "P" , "M" , "TheQuickBrownFoxJumpsOverTheLazyDog" , "\\bigcup" , "vowel:AEIOU" , "WWW" 
            , "X-ray" , "YOOOOOO!" , "ZheJiangUniversity"};
    static boolean is (char ch) {
        if (ch >= 'A' && ch <= 'Z') return true;
        return false;
    }
    static String s;
    static void dfs (int r , int n , BigInteger k) {
        if (n == -1) {
            System.out.print ((char)(r + 'A'));
            return ;
        }
//        System.out.println (r + " " + n + " " + k);
        for (int i = 0 ; i < to[r].length() ; i ++) {
            char ch = to[r].charAt(i);
            BigInteger t = BigInteger.ONE;
            if (is (ch)) t = cnt[ch - 'A'][n];
            if (k.compareTo(t) <= 0) {
                if (!is (ch)) {
                    System.out.print(ch);
                }
                else dfs (ch - 'A' , n - 1 , k);
                return ;
            }
            else k = k.subtract(t);
        }
    }
    public static void main(String[] args) {
        for (int i = 0 ; i < 26 ; i ++)
            cnt[i][0] = BigInteger.ONE;
        for (int i = 1 ; i <= 100 ; i ++) {
            for (int j = 0 ; j < 26 ; j ++) {
                cnt[j][i] = BigInteger.ZERO;
                for (int k = 0 ; k < to[j].length () ; k ++) {
                    char ch = to[j].charAt(k);
                    if (is (ch)) {
                        cnt[j][i] = cnt[j][i].add (cnt[ch - 'A'][i - 1]);
                    }
                    else cnt[j][i] = cnt[j][i].add (BigInteger.ONE);
                }
            }
        }
        int first = 1;
        while (cin.hasNext()) {
            if (first == 0) s = cin.nextLine();
            s = cin.nextLine();
            first = 0;
            int n = cin.nextInt() , m = cin.nextInt();
            BigInteger k = cin.nextBigInteger();
            BigInteger len = BigInteger.ZERO;
            for (int i = 0 ; i < s.length() ; i ++) {
                char ch = s.charAt(i);
                if (is (ch)) len = len.add (cnt[ch - 'A'][n]);
                else len = len.add (BigInteger.ONE);
            }
            k = k.add (BigInteger.ONE);
            BigInteger t = BigInteger.valueOf(m - 1);
            t = t.min(len.subtract(k));
            for (BigInteger i = BigInteger.ZERO ; i.compareTo(t) <= 0 ; i = i.add(BigInteger.ONE)) {
                BigInteger tot = k.add (i);
//                System.out.println (tot);
                for (int j = 0 ; j < s.length() ; j ++) {
                    BigInteger r = BigInteger.ONE;
                    char ch = s.charAt (j);
                    if (is (ch)) r = cnt[ch - 'A'][n];
                    if (tot.compareTo(r) <= 0) {
                        if (!is (ch)) {
                            System.out.print (ch);
                        }
                        else {
                            dfs (ch - 'A' , n - 1 , tot);
                        }
                        break;
                    }
                    else tot = tot.subtract(r);
                }
            }
            System.out.println("");
        }
//        InputStream inputStream = System.in;
//        OutputStream outputStream = System.out;
//        InputReader in = new InputReader(inputStream);
//        PrintWriter out = new PrintWriter(outputStream);
//        int t = 1;
//        Task solver = new Task();
//        while ((t --) > 0)
//            solver.solve(in, out);
//        out.close();
    }
}
class Task{
    void solve (InputReader cin , PrintWriter cout) {
        
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