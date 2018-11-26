import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static int minimumLoss(long[] price) {
        // traverse price array and save (price, index) to a map
        Map<Long, Integer> map = new HashMap<Long, Integer>();
        for(int i=0; i<price.length; i++) {
        	map.put(price[i], i);
        }
        // sort the price array
        Arrays.sort(price);
        // check adjacent pairs and compare their indicies with the original
        int minLoss = Integer.MAX_VALUE;
        for(int i=1; i<price.length; i++) {
        	long p1 = price[i];
        	long p2 = price[i-1];
        	int index1 = map.get(p1);
        	int index2 = map.get(p2);
        	if(p1 - p2 < minLoss && index1 < index2) {
        		minLoss = (int)(p1 - p2);
        	}
        }
        return minLoss;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        long[] price = new long[n];
        for(int price_i = 0; price_i < n; price_i++){
            price[price_i] = in.nextLong();
        }
        int result = minimumLoss(price);
        System.out.println(result);
        in.close();
    }
}
