import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the luckBalance function below.
    static int luckBalance(int k, int[][] contests) {
        // save important contest's luck in a list
        List<Integer> importantLuck = new ArrayList<Integer>();
        int totalLuck = 0; // keep track of total luck
        int i;
        // traverse contests
        for(i=0; i<contests.length; i++){
            int luck = contests[i][0];
            int importance = contests[i][1];
            totalLuck += luck;
            if(importance == 1){
                importantLuck.add(luck);
            }
        }
        // wins required
        int wins = importantLuck.size() - k;
        if(wins>0){
            // to maximize luck, win contests with lower luck first
            Collections.sort(importantLuck);
            i = 0;
            while(wins > 0 && i < importantLuck.size()){
                totalLuck -= 2*importantLuck.get(i);
                i++;
                wins--;
            }
        }
        return totalLuck;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nk = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nk[0]);

        int k = Integer.parseInt(nk[1]);

        int[][] contests = new int[n][2];

        for (int i = 0; i < n; i++) {
            String[] contestsRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 2; j++) {
                int contestsItem = Integer.parseInt(contestsRowItems[j]);
                contests[i][j] = contestsItem;
            }
        }

        int result = luckBalance(k, contests);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
