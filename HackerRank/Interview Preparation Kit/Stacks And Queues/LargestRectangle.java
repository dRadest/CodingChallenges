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
        long maxRectangle = 0; // hold the max calculated area 
        for(int i=0; i<h.length; i++){
            long currentHeight = h[i];
            long multiply = 1; // how many rectangles fit current height
            // looking backward
            int index = i-1;
            while(index >= 0 && h[index] >= h[i]){
                multiply++;
                index--;
            }
            // looking backward
            index = i+1;
            while(index < h.length && h[index] >= h[i]){
                multiply++;
                index++;
            }
            if(maxRectangle < (currentHeight*multiply)){
                maxRectangle = currentHeight * multiply;
            }
        }
        return maxRectangle;


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
