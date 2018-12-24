import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the riddle function below.
    static long[] riddle(long[] arr) {
        // complete this function

        // size of the input array
        int n = arr.length;

        // Used to find previous and next smaller
        Stack s = new Stack<>();

        // Arrays to store previous and next smaller
        long left[] = new long[n + 1];
        long right[] = new long[n + 1];

        // Initialize elements of left[] and right[]
        for (int i = 0; i < n; i++) {
            left[i] = -1;
            right[i] = n;
        }

        // Fill elements of left[] using logic discussed on
        // https://www.geeksforgeeks.org/next-greater-element/
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[(int)s.peek()] >= arr[i]){
                s.pop();
            }

            if (!s.empty()){
                left[i] = (int)s.peek();
            }

            s.push(i);
        }

        // Empty the stack as stack is going to be used for right[]
        while (!s.empty()){
            s.pop();
        }

        // Fill elements of right[] using same logic
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[(int)s.peek()] >= arr[i]){
                s.pop();
            }

            if (!s.empty()){
                right[i] = (int)s.peek();
            }

            s.push(i);
        }

        // Create and initialize answer array
        long ans[] = new long[n + 1];
        for (int i = 0; i <= n; i++){
            ans[i] = 0;
        }

        // Fill answer array by comparing minimums of all
        // lengths computed using left[] and right[]
        for (int i = 0; i < n; i++) {
            // length of the interval
            int len = (int)(right[i] - left[i] - 1);

            // arr[i] is a possible answer for this length
            // 'len' interval, check if arr[i] is more than
            // max for 'len'
            ans[len] = Math.max(ans[len], arr[i]);
        }

        // Some entries in ans[] may not be filled yet. Fill
        // them by taking values from right side of ans[]
        for (int i = n - 1; i >= 1; i--){
            ans[i] = Math.max(ans[i], ans[i + 1]);
        }

        long[] result = new long[n];
        for(int i=0; i<n; i++){
            result[i] = ans[i+1];
        }
        return result;

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        long[] arr = new long[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            long arrItem = Long.parseLong(arrItems[i]);
            arr[i] = arrItem;
        }

        long[] res = riddle(arr);

        for (int i = 0; i < res.length; i++) {
            bufferedWriter.write(String.valueOf(res[i]));

            if (i != res.length - 1) {
                bufferedWriter.write(" ");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
