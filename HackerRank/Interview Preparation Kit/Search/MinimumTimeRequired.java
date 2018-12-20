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
        // find machines with min and max production
        Arrays.sort(machines);
        long minMachine = machines[0];
        long maxMachine = machines[machines.length-1];
        // similar to binary search logic
        // search for the minimum time (day) within min and max value
        long minDay = (long)Math.floor(machines[0]*goal/machines.length);
        long maxDay = (long)Math.floor(machines[0]*goal);
        while(minDay != maxDay){
            long day = (maxDay+minDay)/2;
            long sum = 0;
            for(int i=0; i<machines.length; i++){
                sum += (long)Math.floor(day/machines[i]);
            }
            if(sum >= goal){
                maxDay = day;
            }else{
                minDay = day + 1;
            }
        }
        return minDay;

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
