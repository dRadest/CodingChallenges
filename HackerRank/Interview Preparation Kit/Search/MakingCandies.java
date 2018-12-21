import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // helper method that ceils the division of x and y
    static long divideToCeil(long x, long y) {
        return x / y + (x % y == 0 ? 0 : 1);
    }

    // Complete the minimumPasses function below.
    static long minimumPasses(long m, long w, long p, long n) {
        // if (m*w) > n, goal achieved in one pass
        if (BigInteger.valueOf(m).multiply(BigInteger.valueOf(w)).compareTo(BigInteger.valueOf(n)) > 0) {
            return 1;
        }

        long minPass = Long.MAX_VALUE;
        long currentPass = 0;
        long production = 0;
        while (true) {
            // remaining passes if production rate (m*w) stays the same 
            long remainPass = divideToCeil(n - production, m * w);
            minPass = Math.min(minPass, currentPass + remainPass);

            // just one pass left
            if (remainPass == 1) {
                break;
            }
            // can't afford to buy machines/hire workers
            if (production < p) {
                // extra passes to be performed with current rate (m*w)
                long extraPass = divideToCeil(p - production, m * w);
                // increment current pass and production
                currentPass += extraPass;
                production += extraPass * m * w;
                // if goal reached
                if (production >= n) {
                    minPass = Math.min(minPass, currentPass);
                    break;
                }
            }
            // buy as much as possible (greedy)
            production -= p;
            // increment the lowest value workers or machines
            if (m <= w) {
                m++;
            } else {
                w++;
            }
        }
        return minPass;


    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] mwpn = scanner.nextLine().split(" ");

        long m = Long.parseLong(mwpn[0]);

        long w = Long.parseLong(mwpn[1]);

        long p = Long.parseLong(mwpn[2]);

        long n = Long.parseLong(mwpn[3]);

        long result = minimumPasses(m, w, p, n);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
