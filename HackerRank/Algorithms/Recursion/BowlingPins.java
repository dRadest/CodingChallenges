import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    // array to hold calculated Grundy numbers
    static int[] grundy = new int[301];

    // helper method to calculate mex of a given set of numbers
    static int calculateMex(Set<Integer> set){
        int mex = 0;
        while(set.contains(mex)){
            mex++;
        }
        return mex;
    }

    // helper method to get Grundy number
    private static int getGrundy(int n){
        if(grundy[n] != 0)
            return grundy[n];
        if(n == 0){
            grundy[0] = 0;
            return 0;
        }
        if (n == 1){
            grundy[1] = 1;
            return (1);
        }
        if (n == 2){
            grundy[2] = 2;
            return (2);
        }

        Set<Integer> set = new HashSet<Integer>();
        for(int i = 1, j = 0, k = 0; i <= n; i++){
            // split the pile of pins into groups accordingly
            int x, y;
            if(i <= n / 2){
                x = getGrundy(j);
                y = getGrundy(n - j - 2);
                j++;
            } else {
                x = getGrundy(k);
                y = getGrundy(n - k - 1);
                k++;
            }
            set.add(x ^ y);
        }
        grundy[n] = calculateMex(set);
        return grundy[n];
    }
    
    /*
     * Complete the isWinning function below.
     */
    static String isWinning(int n, String config) {
        List<Integer> list = new ArrayList<Integer>();
        int count = 0;
        // counting individual piles of pins
        for(int i = 0; i < config.length(); i++){
            char ch = config.charAt(i);
            if(ch == 'I'){
                //If I is found then check further - for contingous I's
                count++;
            }else{
                // else if count not 0(when consequtive X's found) 
                // put in list and initialize to 0
                if(count != 0){
                    list.add(count);
                }
                count = 0;
            }
        }
        // do same for last heap [we can resolve this by explicity adding a X at end]
        if(count > 0){
            list.add(count);
        }

        int result = 0;
        for(int i = 0; i < list.size(); i++){
            //doing XOR sum of Grundy numbers of each heap size [continous I's]
            result ^= getGrundy(list.get(i));
        }
        if(result <= 0){
            //If result of XOR sum of all piles is zero or less 
            // opponent has last move and we lose
            return "LOSE";
        }
        else{
            //Otherwise if the result of XOR sum of all piles is non-zero
            // last move is ours and we win
            return "WIN";
        }

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = Integer.parseInt(scanner.nextLine().trim());

        for (int tItr = 0; tItr < t; tItr++) {
            int n = Integer.parseInt(scanner.nextLine().trim());

            String config = scanner.nextLine();

            String result = isWinning(n, config);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();
    }
}
