import java.util.*;
import java.io.*;
import java.math.*;
public class Main {
    
    public static void main(String[] args) {
        Scanner cin = new Scanner (System.in);
        int t = cin.nextInt() ;
        for (int cas = 1 ; cas <= t ; cas ++) {
            int n = cin.nextInt();
            BigInteger a = cin.nextBigInteger() , x = cin.nextBigInteger() , b = cin.nextBigInteger() , y = cin.nextBigInteger();
            a = a.subtract(BigInteger.ONE);
            b = b.subtract(BigInteger.ONE);
            x = x.subtract(BigInteger.ONE);
            y = y.subtract(BigInteger.ONE);
            boolean ans = false;
            for (int i = 0 ; i < n ; i ++) {
                boolean ok = true;
                for (int j = 0 ; j < n ; j ++) {
                    int t1 = a.testBit(j) == b.testBit(j) ? 1 : 0;
                    int t2 = x.testBit((i + j) % n) == y.testBit((i + j) %n) ? 1 : 0;
                    if (t1 != t2) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    ans = true;
                    break;
                }
            }
            System.out.println("Case " + cas + ": " + (ans ? "Yes" : "No"));
        }
    }
}