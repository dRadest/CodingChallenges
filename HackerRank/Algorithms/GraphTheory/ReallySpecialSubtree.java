import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Graph {

    /*
     * Complete the 'kruskals' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
     */

    /*
     * For the weighted graph, <name>:
     *
     * 1. The number of nodes is <name>Nodes.
     * 2. The number of edges is <name>Edges.
     * 3. An edge exists between <name>From[i] and <name>To[i]. The weight of the edge is <name>Weight[i].
     *
     */

    // A class to represent a graph edge 
    static class Edge implements Comparable<Edge> { 
        int src, dest, weight; 
  
        // Comparator function used for sorting edges 
        public int compareTo(Edge compareEdge) {
            if(this.weight == compareEdge.weight){
                int sumone = this.src + this.dest + this.weight;
                int sumtwo = compareEdge.src + compareEdge.dest + compareEdge.weight;
                return sumone - sumtwo;
            } 
            return this.weight-compareEdge.weight; 
        } 
    }; 

    // A class to represent a subset for union-find 
    static class Subset { 
        int parent, rank; 
    }; 

    public int V, E; // number of vertices and edges
    public static Edge[] edges; // array of edges in the graph

    // Creates a graph with V vertices and E edges 
    Graph(int v, int e) { 
        V = v; 
        E = e; 
        edges = new Edge[E]; 
        for (int i=0; i<e; ++i) 
            edges[i] = new Edge(); 
    } 

    // A utility function to find set of an element i 
    // (uses path compression technique) 
    static int find(Subset[] subsets, int i) { 
        // find root and make root as parent of i (path compression) 
        if (subsets[i].parent != i) 
            subsets[i].parent = find(subsets, subsets[i].parent); 
  
        return subsets[i].parent; 
    } 
  
    // A function that does union of two sets of x and y 
    // (uses union by rank) 
    static void union(Subset[] subsets, int x, int y) { 
        int xroot = find(subsets, x); 
        int yroot = find(subsets, y); 
  
        // Attach smaller rank tree under root of high rank tree 
        // (Union by Rank) 
        if (subsets[xroot].rank < subsets[yroot].rank) 
            subsets[xroot].parent = yroot; 
        else if (subsets[xroot].rank > subsets[yroot].rank) 
            subsets[yroot].parent = xroot; 
  
        // If ranks are same, then make one as root and increment 
        // its rank by one 
        else
        { 
            subsets[yroot].parent = xroot; 
            subsets[xroot].rank++; 
        } 
    } 

    public static int kruskals(int gNodes, List<Integer> gFrom, List<Integer> gTo, List<Integer> gWeight) {
        // construct the graph 
        Graph graph = new Graph(gNodes, gWeight.size());
        for(int i=0; i<gWeight.size(); i++){
            graph.edges[i].src = gFrom.get(i);
            graph.edges[i].dest = gTo.get(i);
            graph.edges[i].weight = gWeight.get(i);
        }

        // array of size (V-1) to store edges
        Edge[] result = new Edge[gNodes-1];
        for(int i=0; i<gNodes-1; i++){
            result[i] = new Edge();
        }

        // sort edges
        Arrays.sort(edges);

        // Allocate memory for creating V ssubsets 
        Subset[] subsets = new Subset[gNodes]; 
        for(int i=0; i<gNodes; i++){ 
            subsets[i] = new Subset();
        } 

        // Create V subsets with single elements 
        for (int v = 0; v < gNodes; v++) { 
            subsets[v].parent = v; 
            subsets[v].rank = 0; 
        } 

        int e = 0; // index variable for result[]
        int i = 0; // index variable for edges[]
        // number of edges to be taken is (gNodes - 1)
        while (e < gNodes - 1) { 
            // Pick the smallest edge. And increment  
            // the index for next iteration 
            Edge next_edge = new Edge(); 
            next_edge = edges[i++]; 
  
            int x = find(subsets, next_edge.src-1); 
            int y = find(subsets, next_edge.dest-1); 
  
            // If including this edge doesn't cause cycle, 
            // include it in result and increment the index  
            // of result for next edge 
            if (x != y) { 
                result[e++] = next_edge; 
                union(subsets, x, y); 
            } 
            // Else discard the next_edge 
        }  

        // calculate total weight of all the edges 
        int sum = 0;
        for(Edge edg : result){
            sum += edg.weight;
        }
        return sum;

    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] gNodesEdges = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int gNodes = Integer.parseInt(gNodesEdges[0]);
        int gEdges = Integer.parseInt(gNodesEdges[1]);

        List<Integer> gFrom = new ArrayList<>();
        List<Integer> gTo = new ArrayList<>();
        List<Integer> gWeight = new ArrayList<>();

        IntStream.range(0, gEdges).forEach(i -> {
            try {
                String[] gFromToWeight = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

                gFrom.add(Integer.parseInt(gFromToWeight[0]));
                gTo.add(Integer.parseInt(gFromToWeight[1]));
                gWeight.add(Integer.parseInt(gFromToWeight[2]));
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        int res = Graph.kruskals(gNodes, gFrom, gTo, gWeight);
        // Write your code here.
        String resString = String.valueOf(res);
        bufferedWriter.write(resString, 0, resString.length());

        bufferedReader.close();
        bufferedWriter.close();
    }
}
