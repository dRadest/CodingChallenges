import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    /*
     * Complete the travelAroundTheWorld function below.
     */
    static int travelAroundTheWorld(int[] a, int[] b, long c) {
        int n = a.length; // number of cities
        // the fuel used in a trip to the next city
        // (amount put in minus the amount consumed)
        int[] d = new int[n];
        for(int i=0; i<n; i++){
            d[i] = a[i] - b[i];
        }
        // the fuel needed to start at city i
        // and reach city 0
        long[] dmin = new long[n];
        dmin[n-1] = d[n-1];
        for(int i=n-2; i>=0; i--){
            dmin[i] = Math.min(d[i], d[i] + dmin[i+1]);
        }
        // second loop to be sure i covers the whole loop from any city
        dmin[n-1] = Math.min(d[n-1], d[n-1] + dmin[0]);
        for(int i=n-2; i>=0; i--){
            dmin[i] = Math.min(d[i], d[i] + dmin[i+1]);
        }
        // if for any city i needs more fuel than car can carry
        // the trip is impossible for all cities
        for(int i=0; i<n; i++){
            if((-dmin[i] + a[i]) > c){
                return 0;
            }
        }
        // any city i that car need to have 0 fuel to reach city 0
        // is a good starting point 
        int count = 0;
        for(int i=0; i<n; i++){
            if(dmin[i] >= 0){
                count++;
            }
        }
        return count;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nc = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nc[0].trim());

        long c = Long.parseLong(nc[1].trim());

        int[] a = new int[n];

        String[] aItems = scanner.nextLine().split(" ");

        for (int aItr = 0; aItr < n; aItr++) {
            int aItem = Integer.parseInt(aItems[aItr].trim());
            a[aItr] = aItem;
        }

        int[] b = new int[n];

        String[] bItems = scanner.nextLine().split(" ");

        for (int bItr = 0; bItr < n; bItr++) {
            int bItem = Integer.parseInt(bItems[bItr].trim());
            b[bItr] = bItem;
        }

        int result = travelAroundTheWorld(a, b, c);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();
    }
}
