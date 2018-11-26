import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    static int getMedian(int[] freq,int d){
        int[] prefix_sum = new int[201];
        prefix_sum[0] = freq[0];
        for(int i=1;i<201;i++){
            prefix_sum[i] = prefix_sum[i-1] + freq[i];
        }
        int median;
        int a = 0;
        int b = 0;
        if(d%2==0){
            int first = d/2;
            int second = first+1;
            int i = 0;
            for(;i<201;i++){
                if(first<=prefix_sum[i]){
                    a = i;
                    break;
                }
            }
            for(;i<201;i++){
                if(second<=prefix_sum[i]){
                    b = i;
                    break;
                }
            }

        }else{
            int first = d/2 + 1;
            for(int i=0;i<201;i++){
                if(first<=prefix_sum[i]){
                    a = i;
                    break;
                }
            }
        }
        median = a + b;
        return median;
    }

    // Complete the activityNotifications function below.
    static int activityNotifications(int[] expenditure, int d) {
        int total = 0;
        int[] freq = new int[201];
        boolean first_time = true;
        int pop_element = 0;
        for (int index = d; index < expenditure.length; index++) {
            if (first_time) {
                first_time = false;
                for (int i = index - d; i <= index - 1; i++)
                    freq[expenditure[i]]++;
            } else {
                freq[pop_element]--;
                freq[expenditure[index - 1]]++;
            }
            int median = getMedian(freq, d);
            if (d % 2 == 0) {
                if (expenditure[index] >= median)
                    total++;
            } else {
                if (expenditure[index] >= 2 * median)
                    total++;
            }
            pop_element = expenditure[index - d];
        }
        return total;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nd = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nd[0]);

        int d = Integer.parseInt(nd[1]);

        int[] expenditure = new int[n];

        String[] expenditureItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int expenditureItem = Integer.parseInt(expenditureItems[i]);
            expenditure[i] = expenditureItem;
        }

        int result = activityNotifications(expenditure, d);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
