import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    private static List<List<Integer>> adj;
    private static int vertices;

    static long journeyToMoon(int n, int[][] astronaut) {
        adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        
        for(int i=0; i<astronaut.length; i++) {
            int u = astronaut[i][0];
            int v = astronaut[i][1];
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        
        // array of booleans to keep track of visited nodes
        boolean[] visited = new boolean[n];
        for (int i=0; i<n; i++) {
            visited[i] = false;
        }
        
        vertices = 0;
        List<Integer> subgr = new ArrayList<Integer>();
        int subgraph = 0;
        for(int v=0; v<n; v++) {
            if(visited[v] == false) {
                dfs(v, visited, subgraph);
                if(vertices != 0) {
                    subgr.add(vertices);
                }
                vertices = 0;
            }
        }
        
        long pos = 0;
        int sum = 0;
        // calculate all possible combinations
        for(Integer size : subgr) {
            pos += sum * size;
            sum += size;
        }
        
        return pos;
    }
    
    static void dfs(int v, boolean[] visited, int subgraph) {
        visited[v] = true;
        vertices++;
        for(int i=0; i < adj.get(v).size(); i++) {
            if(!visited[adj.get(v).get(i)]) {
                dfs(adj.get(v).get(i), visited, subgraph);
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int p = in.nextInt();
        int[][] astronaut = new int[p][2];
        for(int astronaut_i = 0; astronaut_i < p; astronaut_i++){
            for(int astronaut_j = 0; astronaut_j < 2; astronaut_j++){
                astronaut[astronaut_i][astronaut_j] = in.nextInt();
            }
        }
        long result = journeyToMoon(n, astronaut);
        System.out.println(result);
        in.close();
    }
}
