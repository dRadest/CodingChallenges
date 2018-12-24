import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public static class Graph {

        private int V; // vertices
        private ArrayList<ArrayList<Integer>> edges = new ArrayList<>(); // adjacency list of edges
        
        
        public Graph(int size) {
            this.V = size;
            for(int i=0; i<this.V; i++){
                edges.add(new ArrayList<Integer>());
            }
        }

        public void addEdge(int first, int second) {
            edges.get(first).add(second);
            edges.get(second).add(first);
            
        }
        
        public int[] shortestReach(int startId) { // 0 indexed
            // Mark all the vertices as not visited(By default
            // set as false)
            boolean visited[] = new boolean[this.V];

            int[] distances = new int[this.V];
            Arrays.fill(distances, -1); // initialize to -1

            // Create a queue for BFS
            LinkedList<Integer> queue = new LinkedList<Integer>();

            // Mark the current node as visited and enqueue it
            visited[startId] = true;
            distances[startId] = 0;
            queue.add(startId);

            while (queue.size() != 0) {
                // Dequeue a vertex from queue and print it
                int currId = queue.poll();

                // Get all adjacent vertices of the dequeued vertex s
                // If a adjacent has not been visited, then mark it
                // visited and enqueue it
                Iterator<Integer> i = edges.get(currId).listIterator();
                while (i.hasNext()) {
                    int n = i.next();
                    if (!visited[n]) {
                        distances[n] = distances[currId] + 6;
                        visited[n] = true;
                        queue.add(n);
                    }
                }
            }  
            return distances; 
        }
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
      
        int queries = scanner.nextInt();
        
        for (int t = 0; t < queries; t++) {
            
            // Create a graph of size n where each edge weight is 6:
            Graph graph = new Graph(scanner.nextInt());
            int m = scanner.nextInt();
            
            // read and set edges
            for (int i = 0; i < m; i++) {
                int u = scanner.nextInt() - 1;
                int v = scanner.nextInt() - 1;
                
                // add each edge to the graph
                graph.addEdge(u, v);
            }
            
            // Find shortest reach from node s
            int startId = scanner.nextInt() - 1;
            int[] distances = graph.shortestReach(startId);
 
            for (int i = 0; i < distances.length; i++) {
                if (i != startId) {
                    System.out.print(distances[i]);
                    System.out.print(" ");
                }
            }
            System.out.println();            
        }
        
        scanner.close();
    }
}

