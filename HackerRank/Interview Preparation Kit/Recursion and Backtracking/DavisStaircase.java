import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    
    static int[] ways = new int[37];
	
	static int numWays(int n) {	
		if(n < 0)
			return 0;
		if(n == 0)
			return 1;
		if(ways[n] != -1)
			return ways[n];
		return ways[n] = numWays(n-1) + numWays(n-2) + numWays(n-3);
	}

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int s = in.nextInt();
        for(int a0 = 0; a0 < s; a0++){
            int n = in.nextInt();
            Arrays.fill(ways, -1);
		    System.out.println(numWays(n));
        }
    }
}
