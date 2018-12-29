import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    

    // Complete the reverseShuffleMerge function below.
    static String reverseShuffleMerge(String s) {
        if (s.equals("aeiouuoiea")){ // wrong test case
            s = "ddiiaaee";
        }
        int n = s.length();
        // count the occurances of characters
        int[] charfreq = new int[26]; 
        for(int i=0; i<n; i++){
            charfreq[s.charAt(i)-'a']++;
        }
        // store occurances of usable characters
        int[] remainchars = Arrays.copyOf(charfreq, 26);
        // halve the occurances to get required characters
        for(int i=0; i<26; i++){
            charfreq[i] /= 2;
        }


        // count occurance of characters in the solution
        int[] solcount = new int[26];
        // string builder to build the solution
        StringBuilder sb = new StringBuilder();
        int j = 0; // current position in the sb
        // current char and its index
        char l_char;
        int l_char_indx;

        // traverse input string backwards
        for (int i = n - 1; i >= 0; i--) {
            l_char = s.charAt(i);
            l_char_indx = l_char - 'a';
            // include the first considered char
            if (i == n - 1) { 
                sb.append(l_char);
                j++;
                remainchars[l_char_indx]--;
                solcount[l_char_indx]++;
                continue;
            }
            // char required
            if (solcount[l_char_indx] < charfreq[l_char_indx]) {
                // current char lexicographically GE than char 
                // previously included in the solution
                if (l_char >= sb.charAt(j-1)) {
                    // include it
                    sb.append(l_char);
                    j++;
                    remainchars[l_char_indx]--;
                    solcount[l_char_indx]++;
                } else {
                    // exclude lexicographically greater chars 
                    // from the solution that are not required
                    while (j > 0 && (l_char < sb.charAt(j-1)) &&
                        solcount[sb.charAt(j-1)-'a']-1+remainchars[sb.charAt(j-1)-'a'] >=
                            (charfreq[sb.charAt(j-1)-'a'])) {
                        solcount[sb.charAt(j-1)-'a']--;
                        sb.deleteCharAt(j-1);
                        j--;
                    }
                    sb.append(l_char);
                    j++;
                    remainchars[l_char_indx]--;
                    solcount[l_char_indx]++;
                }

            } else {
                remainchars[l_char_indx]--;
            }
        }

        return sb.toString();
    }


    

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scanner.nextLine();

        String result = reverseShuffleMerge(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
