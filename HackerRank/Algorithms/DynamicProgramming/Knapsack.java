import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the unboundedKnapsack function below.
    static int unboundedKnapsack(int k, int[] arr) {
        int[] dp = new int[k+1];
        for(int i=1; i<=k; i++){
            for(int j=0; j<arr.length; j++){
                if(arr[j] <= i){
                    dp[i] = Math.max(dp[i], arr[j] + dp[i-arr[j]]);
                }
            }
        }
        return dp[k];


    }

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while(t-->0){
            int n = in.nextInt();
            int k = in.nextInt();
            int[] arr = new int[n];
            for(int arr_i = 0; arr_i < n; arr_i++){
                arr[arr_i] = in.nextInt();
            }
            int result = unboundedKnapsack(k, arr);
            System.out.println(result);
        }
        in.close();
    }
}
