import java.util.*;
import java.io.*;
import java.math.*;
public class Main {
    
    public static void main(String[] args) {
        Scanner cin = new Scanner (System.in);
        int t = cin.nextInt();
        while ((t --) != 0) {    
            int m = cin.nextInt();
            int n =cin.nextInt();
            BigInteger ans = BigInteger.ONE;
            for (int i = 1 ; i < n ; i ++) {
                ans = ans.multiply(BigInteger.valueOf(m));
            }
            BigInteger ret = BigInteger.valueOf(n);
            BigInteger g = ret.gcd(ans);
            System.out.println(ret.divide(g) + "/" + ans.divide(g));
        }
    }
}