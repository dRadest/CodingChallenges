import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static String larrysArray(int[] A) {
        // Complete this function
        int n = A.length;
        for (int i=0; i<n-2; i++){
            for (int j=n-2-1; j>=i; j--){
                while (A[j]>A[j+1]||A[j]>A[j+2]) {
                    int temp = A[j];
                    A[j] = A[j+1];
                    A[j+1] = A[j+2];
                    A[j+2] = temp;
                }
            }
        }        
        String answer = "NO";
        if (A[n-2]<A[n-1])
            answer = "YES";
        return answer;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            int[] A = new int[n];
            for(int A_i = 0; A_i < n; A_i++){
                A[A_i] = in.nextInt();
            }
            String result = larrysArray(A);
            System.out.println(result);
        }
        in.close();
    }
}
