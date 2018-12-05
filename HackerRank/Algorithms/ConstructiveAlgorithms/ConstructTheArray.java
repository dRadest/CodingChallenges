import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the countArray function below.
    static long countArray(int n, int k, int x) {
        // Return the number of ways to fill in the array.
        long total=0;
        long[][] dp=new long[n][3];

        for(long[] i:dp)
            Arrays.fill(i,0);

        dp[1][1]=1;                 // because array always strts with 1
        int i;

        for(i=2;i<n;i++)
        {
                // to calculate for value 1
            dp[i][1]=(dp[i-1][2]*(k-1))%1000000007;    

                //to calculate other than 1        
            dp[i][2]=(dp[i-1][1] + (dp[i-1][2]*(k-2)))%1000000007;   
        }

        if(x==1)
            total=((k-1)*dp[i-1][2])%1000000007;
        else
            total=((k-2)*dp[i-1][2] + dp[i-1][1])%1000000007;

        return (total); 

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nkx = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nkx[0]);

        int k = Integer.parseInt(nkx[1]);

        int x = Integer.parseInt(nkx[2]);

        long answer = countArray(n, k, x);

        bufferedWriter.write(String.valueOf(answer));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
