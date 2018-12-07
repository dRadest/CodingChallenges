import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    static int[] dp = new int[102];
    private static void populateDP(){
        // 0 losing position
        // 1 winning position
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 1;
        dp[5] = 1;
        for(int i=6; i<102; i++){
            if(dp[i-2] == 0 || dp[i-3] == 0 || dp[i-5] == 0){
                dp[i] = 1;
            }else {
                dp[i] = 0;
            }
        }
    }
    // Complete the gameOfStones function below.
    static String gameOfStones(int n) {
        if(dp[n] == 1){
            return "First";
        }else {
            return "Second";
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        populateDP();

        for (int tItr = 0; tItr < t; tItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            String result = gameOfStones(n);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
