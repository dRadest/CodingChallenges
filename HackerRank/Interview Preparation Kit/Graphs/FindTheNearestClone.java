import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    // finds closest node to i of the color val
    // or -1 if no path exists
    // using BFS
    static int nextClosest(int i, ArrayList<ArrayList<Integer>> graph, long val, long[] ids) { 
        // Mark all the vertices as not visited(By default 
        // set as false) 
        boolean visited[] = new boolean[graph.size()]; 
  
        // Create a queue for BFS 
        LinkedList<Integer> queue = new LinkedList<Integer>(); 
  
        // Mark the current node as visited and enqueue it 
        visited[i]=true; 
        queue.add(i); 

        int path = 0;
  
        while (queue.size() != 0) { 
            // Dequeue a vertex from queue and print it 
            i = queue.poll(); 

  
            // Get all adjacent vertices of the dequeued vertex s 
            // If a adjacent has not been visited, then mark it 
            // visited and enqueue it 
            // also, check if it's the same color as our start node
            Iterator<Integer> it = graph.get(i).listIterator(); 
            while (it.hasNext()) { 
                int n = it.next(); 
                if (!visited[n]) { 
                    visited[n] = true; 
                    path++;
                    if (ids[n] == val) {
                        return path;
                    }
                    queue.add(n); 
                } 
            } 
        }
        return -1; // path not found
    }

    // Complete the findShortest function below.

    /*
     * For the unweighted graph, <name>:
     *
     * 1. The number of nodes is <name>Nodes.
     * 2. The number of edges is <name>Edges.
     * 3. An edge exists between <name>From[i] to <name>To[i].
     *
     */
    static int findShortest(int graphNodes,int[] graphFrom,int[] graphTo,long[] ids,int val) {
        // construct the graph
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for(int i=0; i<graphNodes; i++){
            graph.add(new ArrayList<Integer>());
        }
        // add nodes 
        for(int i=0; i<graphFrom.length; i++){
            int u = graphFrom[i]-1;
            int v = graphTo[i]-1;
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        int minpath = Integer.MAX_VALUE;
        // traverse ids
        for(int i=0; i<graphNodes; i++){
            long color = ids[i]; // of node i
            if(val == (int)color){
                int path = nextClosest(i, graph, color, ids);
                if(path == 1){ // shortest possible path
                    return 1;
                }
                if(path < minpath){ // shortest path so far
                    minpath = path;
                }
            }
        }
        return (minpath == Integer.MAX_VALUE || minpath == -1) ? -1 : minpath;
        
        
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] graphNodesEdges = scanner.nextLine().split(" ");
        int graphNodes = Integer.parseInt(graphNodesEdges[0].trim());
        int graphEdges = Integer.parseInt(graphNodesEdges[1].trim());

        int[] graphFrom = new int[graphEdges];
        int[] graphTo = new int[graphEdges];

        for (int i = 0; i < graphEdges; i++) {
            String[] graphFromTo = scanner.nextLine().split(" ");
            graphFrom[i] = Integer.parseInt(graphFromTo[0].trim());
            graphTo[i] = Integer.parseInt(graphFromTo[1].trim());
        }

        long[] ids = new long[graphNodes];

        String[] idsItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < graphNodes; i++) {
            long idsItem = Long.parseLong(idsItems[i]);
            ids[i] = idsItem;
        }

        int val = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int ans = findShortest(graphNodes, graphFrom, graphTo, ids, val);

        bufferedWriter.write(String.valueOf(ans));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
