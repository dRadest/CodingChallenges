import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the minimumMoves function below.
    static int minimumMoves(String[] grid, int startX, int startY, int goalX, int goalY) {
        // construct edges (adjacency list representation)
        ArrayList<ArrayList<Integer>> edges = new ArrayList<ArrayList<Integer>>();
        int n = grid.length;
        int nodes = n*n;
        // populate edges adjacency list with empty array lists
        for (int i = 0; i <= nodes; i++) {
            edges.add(new ArrayList<Integer>());
        }
        // traverse the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < grid[i].length(); j++) {
                char ch = grid[i].charAt(j); // current character
                if (ch == '.') { // valid spot
                    int vertex1 = i * n + j + 1;
                    int vertex2 = -1;
                    int k = i;
                    int l = j;
                    // move UP
                    while (k > 0 && grid[k - 1].charAt(l) == '.') { 
                        vertex2 = (k - 1) * n + l + 1;

                        if (!edges.get(vertex1).contains(vertex2) && !edges.get(vertex2).contains(vertex1)) {
                            edges.get(vertex1).add(vertex2);
                            edges.get(vertex2).add(vertex1);
                        }
                        k--;

                    }
                    k = i;
                    // move DOWN
                    while (k < n - 1 && grid[k + 1].charAt(l) == '.') { 
                        vertex2 = (k + 1) * n + l + 1;

                        if (!edges.get(vertex1).contains(vertex2) && !edges.get(vertex2).contains(vertex1)) {
                            edges.get(vertex1).add(vertex2);
                            edges.get(vertex2).add(vertex1);
                        }
                        k++;
                    }
                    k = i;
                    // move LEFT
                    while (l > 0 && grid[k].charAt(l - 1) == '.') { 
                        vertex2 = k * n + (l - 1) + 1;

                        if (!edges.get(vertex1).contains(vertex2) && !edges.get(vertex2).contains(vertex1)) {
                            edges.get(vertex1).add(vertex2);
                            edges.get(vertex2).add(vertex1);
                        }
                        l--;

                    }
                    l = j;
                    // move RIGHT
                    while (l < grid[k].length() - 1 && grid[k].charAt(l + 1) == '.') {
                        vertex2 = k * n + (l + 1) + 1;

                        if (!edges.get(vertex1).contains(vertex2) && !edges.get(vertex2).contains(vertex1)) {
                            edges.get(vertex1).add(vertex2);
                            edges.get(vertex2).add(vertex1);
                        }
                        l++;
                    }

                }
            }
        }

        /*
        * for detailed explanation of code below, refer to:
        * https://www.geeksforgeeks.org/minimum-number-of-edges-between-two-vertices-of-a-graph/
        */
        
        // keep track of visited nodes, initialized to false
        boolean[] visited = new boolean[nodes + 1];
        // distance from starting node to each, initialized to 0 
        int[] distance = new int[nodes + 1]; 

        Queue<Integer> Q = new LinkedList<>();

        // start and end node
        int u = startX * n + startY + 1;
        int v = goalX * n + goalY + 1;

        Q.add(u);
        visited[u] = true;
        while (!Q.isEmpty()) {
            int x = Q.peek();
            Q.poll();

            for (int i = 0; i < edges.get(x).size(); i++) {
                if (visited[edges.get(x).get(i)])
                    continue;

                // update distance for i
                distance[edges.get(x).get(i)] = distance[x] + 1;
                Q.add(edges.get(x).get(i));
                visited[edges.get(x).get(i)] = true;
            }
        }

        return distance[v];


    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String[] grid = new String[n];

        for (int i = 0; i < n; i++) {
            String gridItem = scanner.nextLine();
            grid[i] = gridItem;
        }

        String[] startXStartY = scanner.nextLine().split(" ");

        int startX = Integer.parseInt(startXStartY[0]);

        int startY = Integer.parseInt(startXStartY[1]);

        int goalX = Integer.parseInt(startXStartY[2]);

        int goalY = Integer.parseInt(startXStartY[3]);

        int result = minimumMoves(grid, startX, startY, goalX, goalY);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
