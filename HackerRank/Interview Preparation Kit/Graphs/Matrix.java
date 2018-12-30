import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

/****************************************************************************/
class Graph {
    class Edge implements Comparable<Edge> {
        int city1, city2, time;

        // comparator method to sort edges by time ascending
        @Override
        public int compareTo(Edge compareEdge) {
            return compareEdge.time - this.time;
        }
    }

    // class to represent subset for union-find
    class Subset {
        int parent, rank;
        boolean hasMachine;
    }

    int C, R; // number of cities and roads
    Edge[] edges; // collection of roads
    int[] machines; // holds indicies of cities with machines
    // constructs a graph with c cities and r roads

    public Graph(int c, int r, int[] m) {
        this.C = c;
        this.R = r;
        this.machines = m;
        this.edges = new Edge[this.R];
        for (int i = 0; i < this.R; i++) {
            edges[i] = new Edge();
        }
    }

    // A utility method to find set of an element i
    // (uses path compression technique)
    int find(Subset[] subsets, int i) {
        // find root and make root as parent of i (path compression)
        if (subsets[i].parent != i)
            subsets[i].parent = find(subsets, subsets[i].parent);

        return subsets[i].parent;
    }

    // A method that does union of two sets of x and y
    // (uses union by rank)
    void union(Subset[] subsets, int x, int y) {
        int xroot = find(subsets, x);
        int yroot = find(subsets, y);

        // if either of subsets has machines, new formed subset will have it also
        boolean hasIt = false;
        if (subsets[xroot].hasMachine || subsets[yroot].hasMachine) {
            hasIt = true;
        }

        // Attach smaller rank tree under root of high rank tree
        // (Union by Rank)
        if (subsets[xroot].rank < subsets[yroot].rank) {
            subsets[xroot].parent = yroot;
            subsets[yroot].hasMachine = hasIt;
        } else if (subsets[xroot].rank > subsets[yroot].rank) {
            subsets[yroot].parent = xroot;
            subsets[xroot].hasMachine = hasIt;
        }

        // If ranks are same, then make one as root and increment
        // its rank by one
        else {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
            subsets[xroot].hasMachine = hasIt;
        }
    }

    // The main function to construct MST using Kruskal's algorithm
    int modifiedKruskal() {
        // store resultant edges
        ArrayList<Edge> result = new ArrayList<Edge>();
        // indicates if resultant subset has machines
        boolean resultHasMachines = false;
        int totalTime = 0; // count total time

        // sort edges in descending order by time
        Arrays.sort(edges);

        // sort indicies of cities with machines in ascending order
        // for binary search
        Arrays.sort(machines);

        // Allocate memory for creating V ssubsets
        Subset[] subsets = new Subset[C];
        for (int i = 0; i < C; i++) {
            subsets[i] = new Subset();
            // create C subsets with single elements
            subsets[i].parent = i;
            subsets[i].rank = 0;
            subsets[i].hasMachine = Arrays.binarySearch(machines, i) >= 0 ? true : false;
        }

        // traverse the edges
        for (int i = 0; i < R; i++) {
            Edge currentEdge = new Edge();
            currentEdge = edges[i];
            int x = find(subsets, currentEdge.city1);
            int y = find(subsets, currentEdge.city2);
            // both subsets have machines
            if (subsets[x].hasMachine && subsets[y].hasMachine) {
                totalTime += currentEdge.time;
                // none of the subsets has machines
            } else if (!subsets[x].hasMachine && !subsets[y].hasMachine) {
                result.add(currentEdge);
                union(subsets, x, y);
            } else { // one of the subsets has machines
                if (resultHasMachines) { // resulting subset with machines
                    totalTime += currentEdge.time;
                } else {
                    result.add(currentEdge);
                    union(subsets, x, y);
                }
            }
        }
        return totalTime;
    }

}

// endof Graph
/****************************************************************************/

public class Solution {

    // Complete the minTime function below.
    static int minTime(int[][] roads, int[] machines) {
        // construct a graph
        Graph graph = new Graph(roads.length + 1/* cities */, roads.length/* roads */, machines);
        for (int i = 0; i < roads.length; i++) {
            int c1 = roads[i][0];
            int c2 = roads[i][1];
            int t = roads[i][2];
            graph.edges[i].city1 = c1;
            graph.edges[i].city2 = c2;
            graph.edges[i].time = t;
        }
        return graph.modifiedKruskal();


    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nk = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nk[0]);

        int k = Integer.parseInt(nk[1]);

        int[][] roads = new int[n - 1][3];

        for (int i = 0; i < n - 1; i++) {
            String[] roadsRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 3; j++) {
                int roadsItem = Integer.parseInt(roadsRowItems[j]);
                roads[i][j] = roadsItem;
            }
        }

        int[] machines = new int[k];

        for (int i = 0; i < k; i++) {
            int machinesItem = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
            machines[i] = machinesItem;
        }

        int result = minTime(roads, machines);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
