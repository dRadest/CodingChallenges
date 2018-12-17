import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the hourglassSum function below.
    static int hourglassSum(int[][] arr) {
        // initial max is the sum of the first hour glass
        int max = arr[0][0] + arr[0][1] + arr[0][2] +
                    arr[1][1] + arr[2][0] + arr[2][1] + arr[2][2];
        // traverse through all the hourglasses
        for(int i=1; i<=arr.length-2; i++){ // row
            for(int j=1; j<=arr[0].length-2; j++){ // column
                // calculate the sum of the hourglass
                int sum = arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1] +
                    arr[i][j] + arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1];
                // if greater than max, assign it to the max
                if(sum > max){
                    max = sum;
                }
            }
        }
        return max;


    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int[][] arr = new int[6][6];

        for (int i = 0; i < 6; i++) {
            String[] arrRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 6; j++) {
                int arrItem = Integer.parseInt(arrRowItems[j]);
                arr[i][j] = arrItem;
            }
        }

        int result = hourglassSum(arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
