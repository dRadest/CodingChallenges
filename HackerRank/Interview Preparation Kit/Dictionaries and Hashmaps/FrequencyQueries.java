import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

public class Solution {

    // Complete the freqQuery function below.
    static List<Integer> freqQuery(int[][] queries) {
        final Map<Integer, Integer> valueToFreq = new HashMap<>();
        final Map<Integer, Integer> freqToOccurrence = new HashMap<>();
        final List<Integer> frequencies = new ArrayList<>();

        int key;
        int value;
        Integer oldFreq;
        Integer newFreq;
        Integer oldOccurrence;
        Integer newOccurrence;
        for (int[] query : queries) {
            key = query[0];
            value = query[1];
            if (key == 3) { // check
                if (value == 0) {
                    frequencies.add(1);
                }
                frequencies.add(freqToOccurrence.get(value) == null ? 0 : 1);
            } else { // insert or delete
                oldFreq = valueToFreq.get(value);
                oldFreq = oldFreq == null ? 0 : oldFreq;
                oldOccurrence = freqToOccurrence.get(oldFreq);
                oldOccurrence = oldOccurrence == null ? 0 : oldOccurrence;

                // update frequency accordingly
                if (key == 1) { 
                    newFreq = oldFreq + 1;
                } else {
                    newFreq = oldFreq - 1;
                }
                newOccurrence = freqToOccurrence.get(newFreq);
                newOccurrence = newOccurrence == null ? 0 : newOccurrence;

                if (newFreq < 1) {
                    valueToFreq.remove(value);
                } else {
                    valueToFreq.put(value, newFreq);
                }

                if ((oldOccurrence - 1) < 1) {
                    freqToOccurrence.remove(oldFreq);
                } else {
                    freqToOccurrence.put(oldFreq, oldOccurrence - 1);
                }
                freqToOccurrence.put(newFreq, newOccurrence + 1);
            }
        }
        return frequencies;


    }

    public static void main(String[] args) throws IOException {
        try (BufferedReader bufferedReader = new BufferedReader(
                    new InputStreamReader(System.in))) {
            
            int q = Integer.parseInt(bufferedReader.readLine().trim());
            int[][] queries = new int[q][2];
           
            for (int i = 0; i < q; i++) {
                String[] query = bufferedReader.readLine().split(" ");
                queries[i][0] = Integer.parseInt(query[0]);
                queries[i][1] = Integer.parseInt(query[1]);
            }
          
            List<Integer> ans = freqQuery(queries);
          
            try (BufferedWriter bufferedWriter = new BufferedWriter(
                        new FileWriter(System.getenv("OUTPUT_PATH")))) {
            
                bufferedWriter.write(ans.stream().map(Object::toString)
                            .collect(joining("\n")) + "\n");
            }
        }
    }
}