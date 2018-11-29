import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Node implements Comparable<Node>{
    private int vertex; // vertex number 
    private int distance; // distance to head vertex
    public Node(int v, int w){
        this.vertex = v;
        this.distance = w;
    }
    public int getVertex(){
        return this.vertex;
    }
    public int getDistance(){
        return this.distance;
    }
    @Override
    public int compareTo(Node node) {
        if(this.getDistance() == node.getDistance()){
            return this.getVertex() - node.getVertex();
        }
        return this.getDistance() - node.getDistance();
    }
}

public class Solution {

    // Complete the shortestReach function below.
    static int[] shortestReach(int n, int[][] edges, int s) {
        // construct the graph (list of adjacent nodes)
        LinkedList<Node> adj[] = new LinkedList[n]; 
        for (int i=0; i<n; ++i){ 
            adj[i] = new LinkedList();
        }
        for(int i=0; i<edges.length; i++){
            int u = edges[i][0]-1;
            int v = edges[i][1]-1;
            int w = edges[i][2];
            adj[u].add(new Node(v, w));
            adj[v].add(new Node(u, w));
        }

        // initialize distance array to INF
        int[] distance = new int[n];
        for(int i=0; i<n; i++){
            distance[i] = Integer.MAX_VALUE;
        }

        // min heap contains nodes
        PriorityQueue<Node> pq = new PriorityQueue<Node>(n);
        
        // distance at starting point is zero
        distance[s-1] = 0;
        pq.add(new Node(s-1, 0)); 

        while(pq.size() != 0){
            int u = pq.poll().getVertex();
            Iterator<Node> i = adj[u].listIterator();

            while (i.hasNext()) { 
                Node node = i.next();
                int v = node.getVertex();
                int weight = node.getDistance(); 
                if (distance[v] > distance[u] + weight) {
                    distance[v] = distance[u] + weight;
                    pq.offer(new Node(v, distance[v])); 
                } 
            }
        }

        int[] result = new int[n-1];
        int k = 0;
        for(int i=0; i<n; i++){
            if(i != s-1){
                if(distance[i] == Integer.MAX_VALUE){
                    result[k] = -1;
                } else {
                    result[k] = distance[i];
                }
                k++;
            }
        }
        return result;


    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            String[] nm = scanner.nextLine().split(" ");

            int n = Integer.parseInt(nm[0]);

            int m = Integer.parseInt(nm[1]);

            int[][] edges = new int[m][3];

            for (int i = 0; i < m; i++) {
                String[] edgesRowItems = scanner.nextLine().split(" ");
                scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

                for (int j = 0; j < 3; j++) {
                    int edgesItem = Integer.parseInt(edgesRowItems[j]);
                    edges[i][j] = edgesItem;
                }
            }

            int s = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int[] result = shortestReach(n, edges, s);

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
