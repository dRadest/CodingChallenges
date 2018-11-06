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

    // Complete the dynamicArray function below.
    static List<Integer> dynamicArray(int n, List<List<Integer>> queries) {
        // ArrayList vector to store the sequences
        ArrayList<Integer>[] group = new ArrayList[n];
        for(int i=0; i<n; i++){
            group[i] = new ArrayList<Integer>();
        }
        
        int lastAnswer = 0;
        // ArrayList of integers to store results
        List<Integer> result = new ArrayList<Integer>();
        // traverse through the sequences
        for(List<Integer> list : queries){
            int type = list.get(0);
            int x = list.get(1);
            int y = list.get(2);
            int j = (x^lastAnswer)%n;
            if(type == 1){ // add y to the end of the j-th sequence
                group[j].add(y);
            }
            else if(type == 2){ 
                // get the last answer at the specific index
                lastAnswer = group[j].get(y%group[j].size());
                // add it to the results
                result.add(lastAnswer);
            }
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nq = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(nq[0]);

        int q = Integer.parseInt(nq[1]);

        List<List<Integer>> queries = new ArrayList<>();

        IntStream.range(0, q).forEach(i -> {
            try {
                queries.add(
                    Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                        .map(Integer::parseInt)
                        .collect(toList())
                );
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        List<Integer> result = dynamicArray(n, queries);

        bufferedWriter.write(
            result.stream()
                .map(Object::toString)
                .collect(joining("\n"))
            + "\n"
        );

        bufferedReader.close();
        bufferedWriter.close();
    }
}