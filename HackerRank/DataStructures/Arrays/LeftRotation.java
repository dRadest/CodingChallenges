import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {



    private static final Scanner scanner = new Scanner(System.in);

    // prints space-seperated elements of the array in one line
    private static void printArray(int[] a){
        for(int elem : a){
            System.out.print(elem + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        String[] nd = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nd[0]);

        int d = Integer.parseInt(nd[1]);

        int[] a = new int[n];

        String[] aItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int aItem = Integer.parseInt(aItems[i]);
            a[i] = aItem;
        }
        
        scanner.close();
        
        // number of rotations
        int rotations = d % n;
        if(rotations == 0){ // print a[] as is
            printArray(a);
        } else {
        	// array to hold rotated a
            int[] newa = new int[n]; 
            for(int i=0; i<n; i++){
            	// calculate the new index of an int at i
                int index = (n+i-rotations)%n;
                newa[index] = a[i];
            }
            printArray(newa);
        }
    }
}