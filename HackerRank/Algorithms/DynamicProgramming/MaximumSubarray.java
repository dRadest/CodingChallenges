import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    private static int maxSumSubarray(int[] arr){
        int f = arr[0];
        int ans = f;
        for(int i=1; i<arr.length; i++){
            f = Math.max(arr[i], f + arr[i]);
            ans = Math.max(ans, f);
        }
        return ans;
    }

    // Complete the maxSubarray function below.
    static int[] maxSubarray(int[] arr) {
        // find maximum subsequence
        int maxElement = arr[0];
        int sumSubsequence = 0;
        for(int i=0; i<arr.length; i++){
            // add all the positive integers
            if(arr[i] > 0){
                sumSubsequence += arr[i];
            }
            if(arr[i] > maxElement){
                maxElement = arr[i];
            }
        }
        int[] result = new int[2];
        result[1] = sumSubsequence;
        // no positive elements
        if(maxElement <= 0){
            result[0] = maxElement;
            result[1] = maxElement;
            return result;
        }
        result[0] = maxSumSubarray(arr);
        return result; 
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int[] arr = new int[n];

            String[] arrItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int i = 0; i < n; i++) {
                int arrItem = Integer.parseInt(arrItems[i]);
                arr[i] = arrItem;
            }

            int[] result = maxSubarray(arr);

            for (int i = 0; i < result.length; i++) {
                bufferedWriter.write(String.valueOf(result[i]));

                if (i != result.length - 1) {
                    bufferedWriter.write(" ");
                }
            }

            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
