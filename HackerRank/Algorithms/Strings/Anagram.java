import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the anagram function below.
    static int anagram(String s) {
        if(s.length() % 2 != 0){
            return -1;
        }
        int changes = 0;
        // split the string into two
        String str1 = s.substring(0, s.length()/2);
        String str2 = s.substring(s.length()/2);
        // a-z is 97-122 
        int[] chars = new int[123]; 
        // keep track of number of differences between two strings
        for(int i=0; i<str1.length(); i++){
            char fchar = str1.charAt(i);
            char schar = str2.charAt(i);
            chars[(int)fchar]++;
            chars[(int)schar]--;
        }
        for(int i=97; i<123; i++){
            changes += Math.abs(chars[i]);
        }
        // just need to change 1 char of 2
        return (changes / 2);
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String s = scanner.nextLine();

            int result = anagram(s);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
