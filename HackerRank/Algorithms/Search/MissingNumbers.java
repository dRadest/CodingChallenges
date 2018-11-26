import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    public static int[] convertIntegers(List<Integer> integers){
        int[] ret = new int[integers.size()];
        Iterator<Integer> iterator = integers.iterator();
        for (int i = 0; i < ret.length; i++)
        {
            ret[i] = iterator.next().intValue();
        }
        return ret;
    }

    // Complete the missingNumbers function below.
    static int[] missingNumbers(int[] arr, int[] brr) {
        HashMap<Integer, Integer> arr_map = new HashMap<Integer, Integer>();
        HashMap<Integer, Integer> brr_map = new HashMap<Integer, Integer>();
        for(int i=0; i<brr.length; i++){
            int key = brr[i];
            if(brr_map.containsKey(key)){
                int value = brr_map.get(key);
                value++;
                brr_map.replace(key, value);

            } else{
                brr_map.put(key, 1);
            }
        }
        for(int i=0; i<arr.length; i++){
            int key = arr[i];
            if(arr_map.containsKey(key)){
                int value = arr_map.get(key);
                value++;
                arr_map.replace(key, value);

            } else{
                arr_map.put(key, 1);
            }
        }
        ArrayList<Integer> missing = new ArrayList<Integer>();
        brr_map.forEach((k,v)->{
            if(!arr_map.containsKey(k)){
                missing.add(k);
            }else{
                int value = arr_map.get(k);
                if((value-v) != 0){
                    missing.add(k);
                }
            }
        });
        int[] ans = convertIntegers(missing);
        Arrays.sort(ans);
        return ans;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        int m = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] brr = new int[m];

        String[] brrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < m; i++) {
            int brrItem = Integer.parseInt(brrItems[i]);
            brr[i] = brrItem;
        }

        int[] result = missingNumbers(arr, brr);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(String.valueOf(result[i]));

            if (i != result.length - 1) {
                bufferedWriter.write(" ");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
