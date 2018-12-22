import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the abbreviation function below.
    static String abbreviation(String a, String b) {

        boolean[][] isValid = new boolean[a.length() + 1][b.length() + 1];
        // initializing the first raw to all false; ie. if b is
        // not empty, isValid will always be false
        isValid[0][0] = true; // both zero length
        // array initialization - if a is non-empty but b is empty,
        // then isValid == true iff remaining(a) != contain uppercase
        boolean containsUppercase = false;
        for (int k = 1; k <= a.length(); k++) {
            int i = k - 1;
            // if current char is upper case
            if (a.charAt(i) <= 90 && a.charAt(i) >= 65 || containsUppercase) {
                containsUppercase = true;
                isValid[k][0] = false;
            } else
                isValid[k][0] = true;
        }

        // tabulation from start of string
        for (int k = 1; k <= a.length(); k++) {
            for (int l = 1; l <= b.length(); l++) {
                int i = k - 1;
                int j = l - 1;
                // when the characters are equal, set = previous character bool.
                if (a.charAt(i) == b.charAt(j)) {
                    isValid[k][l] = isValid[k - 1][l - 1];
                    continue;
                }
                // elif uppercase a == b, set = prev character bool. or just eat a.
                else if ((int) a.charAt(i) - 32 == (int) b.charAt(j)) {
                    isValid[k][l] = isValid[k - 1][l - 1] || isValid[k - 1][l];
                    continue;
                }
                // elif a is uppercase and no more b, or uppercase a is not b, then false
                else if (a.charAt(i) <= 90 && a.charAt(i) >= 65) {
                    isValid[k][l] = false;
                    continue;
                }
                // else just eat a
                else {
                    isValid[k][l] = isValid[k - 1][l];
                    continue;
                }
            }
        }
        return isValid[a.length()][b.length()] ? "YES" : "NO";


    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String a = scanner.nextLine();

            String b = scanner.nextLine();

            String result = abbreviation(a, b);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
