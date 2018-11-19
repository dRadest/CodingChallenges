import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {
    
    static int[] componentsInGraph(int[][] gb) {
        int n = gb.length;
        int nvertices = 2*n + 1;
        int[] parents = new int[nvertices]; // initialized to zero
        for(int i=0; i<gb.length; i++){
            int a = gb[i][0];
            int b = gb[i][1];
            
            // mark vertices if not yet marked
            if(parents[a] == 0) parents[a] = a;
            if(parents[b] == 0) parents[b] = a;
            
            // update the representative element of each disjoint set
            int low = Math.min(parents[a], parents[b]);
            int high = Math.max(parents[a], parents[b]);
            for(int j=0; j<nvertices; j++){
                if(parents[j] == high){
                    parents[j] = low;
                }
            }
        }
        //convert int[] to Integer[] in order to use Collections.frequency(Integer[], int)
        Integer[] newArray = new Integer[nvertices];
        int i = 0;
        for (int value : parents) {
            newArray[i++] = value;
        }
        
        List<Integer> ints = Arrays.asList(newArray);
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;

        for(int item : newArray) {
            if(item != 0) { // belongs to a set (i.e. is connected)
                int frequency = Collections.frequency(ints, item);
                min = Math.min(min, frequency);
                max = Math.max(max, frequency);
            }
        }
        int[] result = {min, max};
        return result;

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {

        int n = Integer.parseInt(scanner.nextLine().trim());

        int[][] gb = new int[n][2];

        for(int i=0; i<n; i++){
            gb[i][0] = scanner.nextInt();
            gb[i][1] = scanner.nextInt();
        }
        scanner.close();
        
        int[] result = componentsInGraph(gb);
        System.out.println(result[0] + " " + result[1]);
    }
}
