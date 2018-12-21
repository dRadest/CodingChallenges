import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

/*
* algorithm explanation:
* http://blog.gainlo.co/index.php/2016/12/02/uber-interview-question-maximum-sum-non-adjacent-elements/
*/

public class Solution {

    // Complete the maxSubsetSum function below.
    static int maxSubsetSum(int[] arr) {
        // hold the maximum for previous one, two and current position
        int prevOne, prevTwo, result;
        prevOne = prevTwo = result = 0;
        for(int i=0; i<arr.length; i++){
            if(i == 0){ // position 0
                result = arr[0];
            }
            else if(i == 1){ // position 1
                result = Math.max(arr[0], arr[1]);
            }else{
                // current max is previous max or previous two plus current
                result = Math.max(prevOne, prevTwo + arr[i]);
                // because of possible negatives, check current position alone
                result = Math.max(result, arr[i]);
            }
            // shift previous one and two forward
            prevTwo = prevOne;
            prevOne = result;
        }
        return result;


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

        int res = maxSubsetSum(arr);

        bufferedWriter.write(String.valueOf(res));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
