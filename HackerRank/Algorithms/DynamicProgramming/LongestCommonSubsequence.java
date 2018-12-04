import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static int[] longestCommonSubsequence(int[] a, int[] b) {
        int m = a.length;
    	int n = b.length;
    	int[][] L = new int[m+1][n+1];
    	  
        // Following steps build L[m+1][n+1] in bottom up fashion. Note
        // that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] 
        for (int i=0; i<=m; i++)
        {
            for (int j=0; j<=n; j++)
            {
                if (i == 0 || j == 0)
                    L[i][j] = 0;
                else if (a[i-1] == b[j-1])
                    L[i][j] = L[i-1][j-1] + 1;
                else
                    L[i][j] = Math.max(L[i-1][j], L[i][j-1]);
            }
        }
  
        // Following code is used to construct LCS
        int index = L[m][n];
  
        // Create a character array to store the lcs 
        int[] lcs = new int[index];
  
        // Start from the right-most-bottom-most corner and
        // one by one store characters in lcs[]
        int i = m, j = n;
        while (index > 0)
        {
            // If current character in X[] and Y are same, then
            // current character is part of LCS
            if (L[i-1][j] == L[i][j])
            {
                i--;
                   
            }
  
            // If not same, then find the larger of two and
            // go in the direction of larger value
            else if (L[i][j-1] == L[i][j])
                j--;
            else{
                                // Put current character in result
                lcs[index-1] = a[i-1];
                 
                // reduce values of i, j and index
                i--; 
                j--; 
                index--; 
            }
        }
        
        return lcs;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n];
        for(int a_i = 0; a_i < n; a_i++){
            a[a_i] = in.nextInt();
        }
        int[] b = new int[m];
        for(int b_i = 0; b_i < m; b_i++){
            b[b_i] = in.nextInt();
        }
        int[] result = longestCommonSubsequence(a, b);
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + (i != result.length - 1 ? " " : ""));
        }
        System.out.println("");


        in.close();
    }
}
