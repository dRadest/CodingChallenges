import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the makeAnagram function below.
    static int makeAnagram(String a, String b) {
        // array to keep track of number of occurances of each char
        int[] count = new int[123];
        int i;
        // increment for chars in a
        for(i=0; i<a.length(); i++){
            count[a.charAt(i)]++;
        }
        // decrement for chars in b
        for (i = 0; i < b.length(); i++) {
            count[b.charAt(i)]--;
        }
        int total = 0;
        // non-zero values have to be removed to make anagram
        for(i=97; i<123; i++){
            total += Math.abs(count[i]);
        }
        return total;

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String a = scanner.nextLine();

        String b = scanner.nextLine();

        int res = makeAnagram(a, b);

        bufferedWriter.write(String.valueOf(res));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
