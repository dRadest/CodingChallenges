import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // returns element at the specified index in the array
    static long getElement(long x){
        long a = x % 8;
        
        if(a == 0 || a == 1)
            return x;
        if(a == 2 || a == 3)
            return 2;
        if(a == 4 || a == 5)
            return (x+2);
        return 0;
    }

    // Complete the xorSequence function below.
    static long xorSequence(long l, long r) {
        long result = getElement(r) ^ getElement(l-1);
        return result;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String[] lr = scanner.nextLine().split(" ");

            long l = Long.parseLong(lr[0]);

            long r = Long.parseLong(lr[1]);

            long result = xorSequence(l, r);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
