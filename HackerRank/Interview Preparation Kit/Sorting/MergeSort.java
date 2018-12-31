import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static long countInversions(int[] arr){
        
        return mergeSort(arr, 0, arr.length - 1);
    }
    
    public static long mergeSort(int[] arr, int start, int end){
        if(start == end)
            return 0;
        int mid = (start + end) / 2;
        long count = 0;
        count += mergeSort(arr, start, mid); //left inversions
        count += mergeSort(arr, mid + 1, end);//right inversions
        count += merge(arr, start, end); // split inversions.
        return count;
    }
    
    public static long merge(int[] arr, int start, int end){
    	int mid = (start + end) / 2;
        int[] newArr = new int[end - start + 1];
        int curr = 0;
        int i = start;
        int j = mid + 1;
        long count = 0;
        while(i <= mid && j <=end) {
            if(arr[i] > arr[j]) {
                newArr[curr++] = arr[j++];
                count += mid - i + 1; // Tricky part.
            }
            else
                newArr[curr++] = arr[i++];          
        }
         // Leftover elements here.
        while(i <= mid) {
            newArr[curr++] = arr[i++];    
        }
        
        while(j <= end) {
            newArr[curr++] = arr[j++];
        }
     
        System.arraycopy(newArr, 0, arr, start, end - start + 1); // Usual stuff from merge sort algorithm with arrays.
        return count;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            int[] arr = new int[n];
            for(int arr_i = 0; arr_i < n; arr_i++){
                arr[arr_i] = in.nextInt();
            }
            long result = countInversions(arr);
            System.out.println(result);
        }
        in.close();
    }
}
