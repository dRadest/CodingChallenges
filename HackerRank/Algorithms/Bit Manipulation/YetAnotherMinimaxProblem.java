import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // converts value from decimal to binary
    // represented by a BitSet
    public static BitSet convert(long value) {
        BitSet bits = new BitSet();
        int index = 0;
        while (value != 0L) {
            if (value % 2L != 0) {
                bits.set(index);
            }
            ++index;
            value = value >>> 1;
        }
        return bits;
    }

    // converts binary represented by a BitSet to decimal
    public static long convert(BitSet bits) {
        long value = 0L;
        for (int i = 0; i < bits.length(); ++i) {
            value += bits.get(i) ? (1L << i) : 0L;
        }
        return value;
    }

    // Complete the anotherMinimaxProblem function below.
    static int anotherMinimaxProblem(int[] arr) {
        /* split numbers into big and small set 
        ** the ones with highest set bit go to big set
        ** the ones with lowest set bit go to small set
        */
        ArrayList<BitSet> big = new ArrayList<BitSet>();
        ArrayList<BitSet> small = new ArrayList<BitSet>();
        ArrayList<BitSet> all = new ArrayList<BitSet>();
        // determine minimum and maximum set bit position
        BitSet firstbs = convert(arr[0]);
        int min = firstbs.length();
        int max = firstbs.length();
        all.add(firstbs);
        for(int i=1; i<arr.length; i++){
            BitSet current = convert(arr[i]);
            if(current.length() < min){
                min = current.length();
            } else if(current.length() > max){
                max = current.length();
            }
            // add all numbers to the big set at first
            all.add(current);
        }
        if(min == max && max == 0){
            return 0;
        }

        while(min == max){ // strip the leading bits
            all.get(0).set(all.get(0).length()-1, false);
            min = all.get(0).length();
            max = all.get(0).length();
            for(int i=1; i<all.size(); i++){
                all.get(i).set(all.get(i).length()-1, false);
                if(all.get(i).length() < min){
                    min = all.get(i).length();
                } else if(all.get(i).length() > max){
                    max = all.get(i).length();
                }
            }
        }
        // split bitsets into two sets
        for(BitSet curbs : all){
            if(curbs.length() < max){
                small.add(curbs);
            } else {
                big.add(curbs);
            }
        }
        
        // find the minimum xor value between two sets
        int a = (int)convert(small.get(0));
        int b = (int)convert(big.get(0));
        int smallest = a^b;
        for(int i=0; i<small.size(); i++){
            a = (int)convert(small.get(i));
            for(int j=0; j<big.size(); j++){
                b = (int)convert(big.get(j));
                if((a^b) < smallest){
                    smallest = a^b;
                }
            }
        }
        return smallest;
    }




    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] a = new int[n];

        String[] aItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int aItem = Integer.parseInt(aItems[i]);
            a[i] = aItem;
        }

        int result = anotherMinimaxProblem(a);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
