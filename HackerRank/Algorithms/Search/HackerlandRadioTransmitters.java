import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        int x, low, center, cnt = 0, lft;
        
        HashMap<Integer, Boolean> mp = new HashMap<Integer, Boolean>();
        ArrayList<Integer> a = new ArrayList<Integer>();
        
        for(int i=0; i<n; i++) {
        	x = in.nextInt();
        	if(mp.get(x)==null)
        		a.add(x);
        	mp.put(x, true);
        }
        in.close();
        
        
        Integer[] ar = a.toArray(new Integer[a.size()]);
        quickSort(ar, 0, ar.length - 1);
        
        
        n = ar.length;
    	lft = 0;
    	while (lft < n)
    	{
    		x = ar[lft] + k;
    		low = lowerBound(ar, x);
    		if(low == -1)
    			low = n;
    		if (low >= n || ar[low] > x)
    			low--;
    		center = ar[low];

    		x = center + k;
    		low = lowerBound(ar, x);
    		if(low == -1)
    			low = n;
    		if (low >= n || ar[low] > x)
    			low--;
    		lft = low + 1;

    		cnt++;
    	}

    	System.out.println(cnt);
        
        
  
	}
	
	public static int partition(Integer[] a, int start, int end) {
		int pivot = a[end];
		int pIndex = start;
		int temp;
		for(int i=start; i<end; i++) {
			if(a[i] <= pivot) {
				temp = a[i];
				a[i] = a[pIndex];
				a[pIndex] = temp;
				pIndex++;
			}
		}
		temp = a[pIndex];
		a[pIndex] = a[end];
		a[end] = temp;
		return pIndex;
	}
	
	public static void quickSort(Integer[] a, int start, int end) {
		if(start<end) {
			int pIndex = partition(a, start, end);
			quickSort(a, start, pIndex-1);
			quickSort(a, pIndex+1, end);
		}
	}
	
	public static void printArray(Integer[] a) {
		for (int i : a) {
			System.out.print(i + " ");
		}
		System.out.println();
	}
	
	public static int lowerBound(Integer[] a, int x) {
		for(int i=0; i<a.length; i++) {
			if(a[i] >= x)
				return i;
		}
		return -1;
	}

}

