import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Structure of Trie DS
    static class TrieNode{
        int value;
        TrieNode[] child = new TrieNode[2];
        public TrieNode(){
            this.value = 0;
            this.child[0] = null;
            this.child[1] = null;
        }
    };
    
    // Inserting key in Trie
    static void insert(TrieNode root, int key) {
        TrieNode temp = root;

        // Storing 31 bits as integer representation
        for (int i = 31; i >= 0; i--) {
            // Current bit in the number
            int current_bit = (key & (1 << i)) >= 1 ? 1 : 0;

            // New node required
            if (temp.child[current_bit] == null){
                temp.child[current_bit] = new TrieNode();
            }

            // Traversing in Trie
            temp = temp.child[current_bit];
        }
        // Assigning value to the leaf Node
        temp.value = key;
    }
    
    // Computing max xor
    static int max_xor(TrieNode root, int key) {
        TrieNode temp = root;

        // Checking for all bits in integer range
        for (int i = 31; i >= 0; i--) {
            // Current bit in the number
            int current_bit = (key & (1 << i)) >= 1 ? 1 : 0;

            // Traversing Trie for different bit, if found
            if (temp.child[1 - current_bit] != null){
                temp = temp.child[1 - current_bit];
            }
            

            // Traversing Trie for same bit
            else{
                temp = temp.child[current_bit];
            }
        }

        // Returning xor value of maximum bit difference
        // value. Thus, we get maximum xor value
        return (key ^ temp.value);
    }

    // Complete the maxXor function below.
    static int[] maxXor(int[] arr, int[] queries) {
        // solve here
        // Forming Trie for arr
        TrieNode root = new TrieNode();
        for (int i = 0; i < arr.length; i++){
            insert(root, arr[i]);
        }
        // array to store the max xor values
        int[] ans = new int[queries.length];
        for(int i = 0; i<queries.length; i++){
            int number = queries[i];
            ans[i] = max_xor(root, number);
        }
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

        int[] queries = new int[m];

        for (int i = 0; i < m; i++) {
            int queriesItem = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
            queries[i] = queriesItem;
        }

        int[] result = maxXor(arr, queries);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(String.valueOf(result[i]));

            if (i != result.length - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
