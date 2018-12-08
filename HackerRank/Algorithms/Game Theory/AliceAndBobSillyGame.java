import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    static int getNumOfPrimes(int n){
        int primes = 0;
        boolean[] catch_the_sieve = new boolean[n+1];
        for (int x = 2; x <= n; x++){
            if (catch_the_sieve[x] == false){
                primes++;
                for (int i = x; i <= n; i += x){
                    catch_the_sieve[i] = true;
                    }
                }
            }
        return primes;
    }

    /*
     * Complete the sillyGame function below.
     */
    static String sillyGame(int n) {
        if(n == 1){ // Alice unable to make a move
            return "Bob";
        }
        int numofprimes = getNumOfPrimes(n);
        if(numofprimes % 2 == 0){
            return "Bob";
        }
        return "Alice";

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int g = Integer.parseInt(scanner.nextLine().trim());

        for (int gItr = 0; gItr < g; gItr++) {
            int n = Integer.parseInt(scanner.nextLine().trim());

            String result = sillyGame(n);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();
    }
}
