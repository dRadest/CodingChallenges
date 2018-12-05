import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for(int a0 = 0; a0 < T; a0++){
            int n = in.nextInt();
            int q[] = new int[n];
            int nSwaps = 0;
            for(int q_i=0; q_i < n; q_i++){
                q[q_i] = in.nextInt();
            }
            calc(q);
        }
    }
    public static void calc(int[] a){
	    int swaps = 0;
	    for (int i = a.length - 1; i >= 0; i--) {
	        if (a[i] - (i + 1) > 2) {
	            System.out.println("Too chaotic");
	            return;
	        }
	        for (int j = Math.max(0, a[i] - 2); j < i; j++)
	            if (a[j] > a[i]) 
	            	swaps++;
	    }
	    System.out.println(swaps);
	}
}
