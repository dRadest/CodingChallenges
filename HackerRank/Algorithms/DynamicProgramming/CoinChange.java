import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static long getWays(int n, long[] c){
        int m = c.length;
        long[] table = new long[n+1];
 
        Arrays.fill(table, 0);  
 
        table[0] = 1;
        
        // iterative approach
        for (int i=0; i<m; i++) {
        	for (int j=(int)c[i]; j<=n; j++) {
        		table[j] += table[j-(int)c[i]];
        	}
        }
 
        return table[n];
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        long[] c = new long[m];
        for(int c_i=0; c_i < m; c_i++){
            c[c_i] = in.nextLong();
        }
        // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
        long ways = getWays(n, c);
        System.out.println(ways);
    }
}
