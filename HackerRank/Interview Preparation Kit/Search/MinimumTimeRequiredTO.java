/*
** passes 10/14 testcases
*/

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the minTime function below.
    static long minTime(long[] machines, long goal) {
        // index = machine, value = count
        long[] nummachines = new long[100001];
        for(long m : machines){
            nummachines[(int)m]++;
        }
        // keep track of items produced each day
        // index = day, value = items produced 
        long[] itemsProduced = new long[100001];
        for(int i=1; i<100001; i++){
            itemsProduced[i] = itemsProduced[i-1];
            for(int j=0; j<=i; j++){
                if(nummachines[j] > 0 && i%j == 0){
                    itemsProduced[i] += nummachines[j];
                }
            }
            if(itemsProduced[i] >= goal){
                return i;
            }
        }
        return 100000;

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nGoal = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nGoal[0]);

        long goal = Long.parseLong(nGoal[1]);

        long[] machines = new long[n];

        String[] machinesItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            long machinesItem = Long.parseLong(machinesItems[i]);
            machines[i] = machinesItem;
        }

        long ans = minTime(machines, goal);

        bufferedWriter.write(String.valueOf(ans));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
