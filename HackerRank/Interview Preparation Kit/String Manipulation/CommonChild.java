/*
** code adopted from: https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
*/

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    /* Utility function to get max of 2 integers */
    static int max(int a, int b) {
        return (a > b) ? a : b;
    }

    /* Returns length of LCS for X[0..n-1], Y[0..n-1] */
    static int lcs(char[] X, char[] Y, int n) {
        int L[][] = new int[n + 1][n + 1];

        /*
         * Following steps build L[n+1][n+1] in bottom up fashion. Note that L[i][j]
         * contains length of LCS of X[0..i-1] and Y[0..j-1]
         */
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    L[i][j] = 0;
                else if (X[i - 1] == Y[j - 1])
                    L[i][j] = L[i - 1][j - 1] + 1;
                else
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
        return L[n][n];
    }

    // Complete the commonChild function below.
    static int commonChild(String s1, String s2) {
        char[] X = s1.toCharArray();
        char[] Y = s2.toCharArray();
        int n = X.length;
        return lcs(X, Y, n);

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s1 = scanner.nextLine();

        String s2 = scanner.nextLine();

        int result = commonChild(s1, s2);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
