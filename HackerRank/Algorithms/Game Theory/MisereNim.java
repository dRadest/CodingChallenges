import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the misereNim function below.
    static String misereNim(int[] s) {
        int n = s.length;
        if(n == 1){
            if(s[0] > 1){
                return "First";
            } else {
                return "Second";
            }
        }
        
        int totalStones = s[0];
        int xorvalue = s[0];
        for(int i=1; i<n; i++){
            totalStones += s[i];
            xorvalue ^= s[i];
        }
        if (totalStones == n) {
            if(totalStones % 2 == 0){
                return "First";
            } else {
                return "Second";
            }
        }
        
        if(xorvalue > 0){
            return "First";
        }
        return "Second";


    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int[] s = new int[n];

            String[] sItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int i = 0; i < n; i++) {
                int sItem = Integer.parseInt(sItems[i]);
                s[i] = sItem;
            }

            String result = misereNim(s);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
