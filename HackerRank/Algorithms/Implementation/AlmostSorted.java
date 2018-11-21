import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // swap elements in the array at indecies i and j
    static void swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // check if the array is sorted
    static boolean isSorted(int[] arr){
        for(int i=0; i<arr.length-1; i++){
            if(arr[i] > arr[i+1]){
                return false;
            }
        }
        return true;
    }

    // reverse the elements of the array from index i to j
    static void reverse(int[] arr, int i, int j){
        while(i < j){
            swap(arr, i, j);
            i++;
            j--;
        }
    }

    // Complete the almostSorted function below.
    static void almostSorted(int[] arr) {
        int n = arr.length;
        if(isSorted(arr)){
            System.out.println("yes");
            return;
        }
        // produce the sorted array
        int[] sortedArr = Arrays.copyOf(arr, n);
        Arrays.sort(sortedArr);
        // find the left and right most indicies that differ
        int lindex = 0;
        int rindex = n - 1;
        for(; lindex < n; lindex++){
            if(sortedArr[lindex] != arr[lindex]){
                break;
            }
        }
        for(; rindex >= 0; rindex--){
            if(sortedArr[rindex] != arr[rindex]){
                break;
            }
        }
        // try swapping elements at left and right index
        swap(arr, lindex, rindex);
        if(isSorted(arr)){
            System.out.println("yes\nswap " + (lindex+1) + " " + (rindex+1));
            return;
        }
        // swap back
        swap(arr, lindex, rindex);
        // try reversing the segment
        reverse(arr, lindex, rindex);
        if(isSorted(arr)){
            System.out.println("yes\nreverse " + (lindex+1) + " " + (rindex+1));
            return;
        }
        System.out.println("no");


    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        almostSorted(arr);

        scanner.close();
    }
}
