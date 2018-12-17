import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // swaps elements at indecies 1 and 2
    static void swap(int[] arr, int index1, int index2) {
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }

    // Complete the minimumSwaps function below.
    static int minimumSwaps(int[] arr) {
        int rightPosition = arr.length-1;
        int leftPosition = 0;
        int minSwaps = 0;
        while(leftPosition < arr.length){
            int value = leftPosition+1; // value that should be at this position
            if(arr[leftPosition] == value){ // advance left position
                leftPosition++;
                continue;
            }
            // decrement tightposition until value reached
            while(arr[rightPosition]!=value){ 
                rightPosition--;
            }
            if(rightPosition != leftPosition){
                swap(arr, leftPosition, rightPosition);
                minSwaps++;
            }
            // move right position back to the end
            rightPosition = arr.length-1;
            // increment left position
            leftPosition++;
        }
        return minSwaps;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        int res = minimumSwaps(arr);

        bufferedWriter.write(String.valueOf(res));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
