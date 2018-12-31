import java.io.*;
import java.util.*;

public class Solution {
    
    static int numSwaps;
    static void bubbleSort(int[] a){
        int n = a.length;
        for (int i = 0; i < n; i++) {
           for (int j = 0; j < n - 1; j++) {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                numSwaps++;
            }
        }
        }
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] a = new int[n];
        for(int i=0; i<n; i++)
            a[i] = scn.nextInt();
        numSwaps = 0;
        bubbleSort(a);
        System.out.println("Array is sorted in " + numSwaps + " swaps.");
        System.out.println("First Element: " + a[0]);
        System.out.println("Last Element: " + a[n-1]);
        
    }
}