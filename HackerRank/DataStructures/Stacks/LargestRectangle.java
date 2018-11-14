import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the largestRectangle function below.
    static long largestRectangle(int[] h) {
        int hsize = h.length;
        int[] height = new int[hsize + 1];
        int i;
        for(i=0; i<hsize; i++){
            height[i] = h[i];
        }
        height[hsize] = 0;
        
        Stack<Integer> stack = new Stack<Integer>();
        long sum = 0;
        
        i=0;
        while(i <= hsize){
            if(stack.isEmpty() || height[i] > height[stack.peek()]){
                stack.push(i);
                i++;
            }else {
                int t = stack.pop();
                sum = Math.max(sum, height[t]*(stack.isEmpty() ? i : i - stack.peek() - 1));
            }
        }
        return sum;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] h = new int[n];

        String[] hItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int hItem = Integer.parseInt(hItems[i]);
            h[i] = hItem;
        }

        long result = largestRectangle(h);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
