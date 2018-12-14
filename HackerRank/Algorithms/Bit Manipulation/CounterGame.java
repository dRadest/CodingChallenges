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

    // Complete the counterGame function below.
    static String counterGame(long input) {
        if(input == 1) {
            return "Richard";
        }
        
        int cnt = 0;
        BitSet bitset = new BitSet();
        bitset = convert(input);
        while(input != 1) {
            if(bitset.cardinality() == 1) { // input is power of 2
                input = input >> 1; // divide by 2
                bitset = convert(input);
                cnt++;
            } else {
                // find the index of a bit set to 1 that is not the last bit
                int index = 0;
                for (int i = bitset.nextSetBit(0); i >= 0; i = bitset.nextSetBit(i+1)) {
                        index = i;
                }
                bitset.flip(index); // set that bit to zero (i.e. substract)
                input = convert(bitset);
                cnt++;
            }
        }
        
        if(cnt % 2 == 0) {
            return "Richard";
        } else
            return "Louise";

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            long n = scanner.nextLong();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            String result = counterGame(n);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
