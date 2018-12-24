import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    static class Plant{
        int pesticide;
        int days;
        public Plant(int p, int d){
            this.pesticide = p;
            this.days = d;
        }
    }

    // Complete the poisonousPlants function below.
    static int poisonousPlants(int[] p) {
        Stack<Plant> s = new Stack<>();
        int maxdays = 0;
        for(int pesticide : p){
            int days = 0;
            while(!s.empty() && pesticide <= s.peek().pesticide){
                days = Math.max(days, s.pop().days);
            }
            if(s.empty()){
                days = 0;
            }else{
                days += 1;
            }
            maxdays = Math.max(maxdays, days);
            s.push(new Plant(pesticide, days));
        }
        return maxdays;


    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] p = new int[n];

        String[] pItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int pItem = Integer.parseInt(pItems[i]);
            p[i] = pItem;
        }

        int result = poisonousPlants(p);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
