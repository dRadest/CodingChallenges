import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the bfs function below.
    static int[] bfs(int n, int m, int[][] edges, int s) {
        // construct graph
        LinkedList<Integer> adj[] = new LinkedList[n]; 
        for (int i=0; i<n; ++i){ 
            adj[i] = new LinkedList();
        }
        for(int i=0; i<m; i++){
            int u = edges[i][0]-1;
            int v = edges[i][1]-1;
            adj[u].add(v);
            adj[v].add(u);
        } 
        
        // Mark all the vertices as not visited(By default 
        // set as false) 
        boolean[] visited = new boolean[n]; 
  
        // Create a queue for BFS 
        LinkedList<Integer> queue = new LinkedList<Integer>(); 
  
        // Mark the current node as visited and enqueue it 
        visited[s-1]=true; 
        queue.add(s-1); 

        // array holding calculated distances
        int[] distances = new int[n];
        for(int i=0; i<n; i++){ // initialize to 0
            distances[i] = 0;
        }

        while (queue.size() != 0){ 
            // Dequeue a vertex from queue and print it 
            int a = queue.poll(); 
  
            // Get all adjacent vertices of the dequeued vertex s 
            // If a adjacent has not been visited, then mark it 
            // visited and enqueue it 
            Iterator<Integer> i = adj[a].listIterator(); 

            while (i.hasNext()) { 
                int node = i.next(); 
                if (!visited[node]) { 
                    visited[node] = true; 
                    queue.add(node); 
                    distances[node] = distances[a] + 6;
                } 
            }
        }
        int[] result = new int[n-1];
        int k = 0;
        for(int i=0; i<n; i++){
            if(i != s-1){
                if(distances[i] == 0){
                    result[k] = -1;
                } else {
                    result[k] = distances[i];
                }
                k++;
            }
        }
        return result;


    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String[] nm = scanner.nextLine().split(" ");

            int n = Integer.parseInt(nm[0]);

            int m = Integer.parseInt(nm[1]);

            int[][] edges = new int[m][2];

            for (int i = 0; i < m; i++) {
                String[] edgesRowItems = scanner.nextLine().split(" ");
                scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

                for (int j = 0; j < 2; j++) {
                    int edgesItem = Integer.parseInt(edgesRowItems[j]);
                    edges[i][j] = edgesItem;
                }
            }

            int s = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int[] result = bfs(n, m, edges, s);

            for (int i = 0; i < result.length; i++) {
                bufferedWriter.write(String.valueOf(result[i]));

                if (i != result.length - 1) {
                    bufferedWriter.write(" ");
                }
            }

            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
