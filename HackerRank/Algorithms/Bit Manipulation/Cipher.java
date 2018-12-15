import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the cipher function below.
    static String cipher(int k, String s) {
        int n = s.length() - k + 1;
        
        int[] arr = new int[n];
        int[] res = new int[n];
        StringBuffer sb = new StringBuffer();
        
        for(int i=0; i<n; i++) {
            arr[i] = Character.getNumericValue(s.charAt(i));
            if(i == 0) {
                res[0] = arr[0];
            }
            else if(i < k) {
                res[i] = arr[i] ^ arr[i-1];
            }
            else {
                res[i] = arr[i] ^ arr[i-1] ^ res[i-k];
            }
            sb.append(res[i]);
        }
        
        String ans = sb.toString();
        return ans;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nk = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nk[0]);

        int k = Integer.parseInt(nk[1]);

        String s = scanner.nextLine();

        String result = cipher(k, s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
