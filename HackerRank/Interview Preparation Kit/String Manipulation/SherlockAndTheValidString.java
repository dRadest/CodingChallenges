import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the isValid function below.
    static String isValid(String s) {
        // count num of occurances of each char
        int[] count = new int[123];
        for(int i=0; i<s.length(); i++){
            count[s.charAt(i)]++;
        }
        // sort the array and grab the max value
        Arrays.sort(count);
        int maxOccurance = count[122];
        // find minimum occurance number
        int minOccurance = 0;
        int i=97;
        while(i<123){
            if(count[i]>0){
                minOccurance = count[i];
                break;
            }
            i++;
        }
        // if all chars occur same number of times
        if(maxOccurance == minOccurance){
            return "YES";
        }
        // calculate how many chars occur with min/max occurance value
        // if there are characters with different occurance, the answer is NO
        int minChars = 0, maxChars = 0, allChars = 0;
        for(i=97; i<123; i++){
            if(count[i] > 0){
                allChars++;
            }
            if(count[i] == minOccurance){
                minChars++;
            }else if(count[i] == maxOccurance){
                maxChars++;
            }
        }
        if(minChars + maxChars != allChars){
            return "NO";
        }
        if(minOccurance == 1 && minChars == 1){
            return "YES";
        }
        if(maxChars == 1 && maxOccurance == (minOccurance+1)){
            return "YES";
        }
        return "NO";
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scanner.nextLine();

        String result = isValid(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
