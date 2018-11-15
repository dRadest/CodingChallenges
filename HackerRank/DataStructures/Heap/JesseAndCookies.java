import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    /*
     * Complete the cookies function below.
     */
    static int cookies(int k, int[] A) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        // add all the elements from A to heap
        for(int i=0; i<A.length; i++){
            minHeap.add(A[i]);
        }
        initialize number of operations to zero
        int operations = 0;
        if(minHeap.peek() >= k){ // already sorted
            return operations;
        }
        // combine cookies while possible
        while(minHeap.size() >= 2 && minHeap.peek() < k){
            int first = minHeap.poll();
            int second = minHeap.poll();
            int newElement = first + 2 * second;
            minHeap.add(newElement);
            operations++;
        }
        // reached k and performed at least one operation
        if(minHeap.peek() >= k && operations > 0){
            return operations;
        }
        return -1;

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nk = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nk[0].trim());

        int k = Integer.parseInt(nk[1].trim());

        int[] A = new int[n];

        String[] AItems = scanner.nextLine().split(" ");

        for (int AItr = 0; AItr < n; AItr++) {
            int AItem = Integer.parseInt(AItems[AItr].trim());
            A[AItr] = AItem;
        }

        int result = cookies(k, A);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();
    }
}
