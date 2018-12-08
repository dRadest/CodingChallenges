import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    /*
     * Complete the zeroMoveNim function below.
     */
    static char zeroMoveNim(int[] p) {
        int xorsum = 0;
        for(int pi : p){
            if(pi % 2 == 0){ // even
                xorsum ^= (pi-1);
            }else { // odd
                xorsum ^= (pi+1);
            }
        }
        if(xorsum == 0){
            return 'L';
        }
        return 'W';

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int g = Integer.parseInt(scanner.nextLine().trim());

        for (int gItr = 0; gItr < g; gItr++) {
            int pCount = Integer.parseInt(scanner.nextLine().trim());

            int[] p = new int[pCount];

            String[] pItems = scanner.nextLine().split(" ");

            for (int pItr = 0; pItr < pCount; pItr++) {
                int pItem = Integer.parseInt(pItems[pItr].trim());
                p[pItr] = pItem;
            }

            char result = zeroMoveNim(p);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();
    }
}
