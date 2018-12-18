import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    /*
     * method to check whether two strings are anagram of each other
     */
    static boolean areAnagram(String s1, String s2) {
        // if they are of different lengths, they cannot be anagrams
        if(s1.length() != s2.length()){
            return false;
        }
        // array to keep track of occurances of a character in each string
        int[] count = new int[123]; // only checking a-z (97-122)
        Arrays.fill(count, 0);

        // traverse all chars in strings
        for(int i=0; i<s1.length(); i++){
            count[s1.charAt(i)]++; // increment for s1
            count[s2.charAt(i)]--; // decrement for s2
        }
        // if any count non-zero, we don't have an anagram
        for(int i=0; i<123; i++){
            if(count[i] != 0){
                return false;
            }
        }
        return true;
    }

    // Complete the sherlockAndAnagrams function below.
    static int sherlockAndAnagrams(String s) {
        // check for every substring of equal length if they are anagrams
        // increment count accordingly
        int count = 0;
        for(int len=1; len < s.length(); len++){
            for(int i=0; i<s.length()-len; i++){
                String s1 = s.substring(i, i+len);
                for(int j=i+1; j<s.length()-len+1; j++){
                    String s2 = s.substring(j, j+len);
                    if(areAnagram(s1, s2)){
                        count++;
                    }
                }
            }
        }
        return count;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String s = scanner.nextLine();

            int result = sherlockAndAnagrams(s);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
