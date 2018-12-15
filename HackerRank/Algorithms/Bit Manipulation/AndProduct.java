import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    public static long nextPowerOf2(long n){ 
        int count = 0; 

        // First n in the below  
        // condition is for the  
        // case where n is 0 
        if (n > 0 && (n & (n - 1)) == 0) 
            return n; 

        while(n != 0) { 
            n >>= 1; 
            count += 1; 
        } 

        return 1 << count; 
    }

    // Complete the andProduct function below.
    static long andProduct(long a, long b) {
        long v = (a^b);
        // find next power of two
        v = nextPowerOf2(v);
        v--;
        v = ~v;
        long result = a&v;
        return result;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int nItr = 0; nItr < n; nItr++) {
            String[] ab = scanner.nextLine().split(" ");

            long a = Long.parseLong(ab[0]);

            long b = Long.parseLong(ab[1]);

            long result = andProduct(a, b);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
