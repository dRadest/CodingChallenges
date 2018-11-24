import java.io.*;
import java.util.*;

public class Solution {

    private static final int RANGE = 100;

    public static void main(String[] args) {
        int k = RANGE; // counter size
        int n; // number of elements

        Scanner scn = new Scanner(System.in);

        n = scn.nextInt();

        // get unsorted array
        int[] A = new int[n];
        int[] C = new int[RANGE];
        for (int i = 0; i < n; i++){
            A[i] = scn.nextInt();
            scn.nextLine();
            C[A[i]]++;
        }
        for (int i = 1; i < k; i++) {
            C[i] += C[i-1];
        }
        // print sorted array
        for(int num : C){
            System.out.print(num + " ");
        }
    }
}

