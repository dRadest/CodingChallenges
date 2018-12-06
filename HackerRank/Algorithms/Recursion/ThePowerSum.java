import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    static int countExpressions(int x, int n, int s, int v){
        if(s == x){
            return 1;
        }else {
            v++;
            int answer = 0;
            while(s + Math.pow(v, n) <= x){
                answer += countExpressions(x, n, s + (int)Math.pow(v, n), v);
                v++;
            }
            return answer;
        }
    }

    // Complete the powerSum function below.
    static int powerSum(int X, int N) {
        int s = 0;
        int v = 0;
        return countExpressions(X, N, s, v);


    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int X = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int N = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int result = powerSum(X, N);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
