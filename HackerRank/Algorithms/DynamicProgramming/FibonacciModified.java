import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static String fibonacciModified(int t1, int t2, int n) {
        BigInteger a = new BigInteger(Integer.toString(t1));
        BigInteger b = new BigInteger(Integer.toString(t2));
        BigInteger c = new BigInteger("0");
        if(n==0){
            return a.toString();
        }
        for(int i=2; i<n; i++){
            c = b.multiply(b);
            c = c.add(a);
            a = b;
            b = c;
        }
        return b.toString();
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t1 = in.nextInt();
        int t2 = in.nextInt();
        int n = in.nextInt();
        String result = fibonacciModified(t1, t2, n);
        System.out.println(result);
        in.close();
    }
}
