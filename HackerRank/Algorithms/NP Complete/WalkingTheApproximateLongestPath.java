import java.io.*;
import java.util.*;

public class Solution {

    public static class Graph{
        int v;
        int e;
        int minV;
        ArrayList<HashSet<Integer>> adjList;
        boolean[] visited;
        // constructor
        Graph(int v, int e){
            this.v = v; this.e = e;
            adjList = new ArrayList<>(v);
            visited = new boolean[v];
            for(int i=0; i<v; i++){
                adjList.add(new HashSet<Integer>());
            }
        }
        
        // add an edge between two vertices
        public void addEdge(int v1, int v2){
            this.adjList.get(v1-1).add(v2-1);
            this.adjList.get(v2-1).add(v1-1);
        }
        
        // return the vertex with minimum edges
        public int getMinVertex(){
            int minVertex = 0;
            int minValue = Integer.MAX_VALUE;
            for(int i=0; i<v;i++){
                if(adjList.get(i).size() < minValue){
                    minValue = adjList.get(i).size();
                    minVertex = i;
                }
            }
            return minVertex;
        }
        
        // find the vertex among neighboring vertices with minimum edges
        // and return it
        // return -1 if no such vertex exists (all have been visited)
        public int getNextVertex(int v){
            this.visited[v] = true;
            int minVertex = -1;
            int minValue = Integer.MAX_VALUE;
            
            for(int i:this.adjList.get(v)){
                if(!visited[i]){
                    if(this.adjList.get(i).size() < minValue){
                        minValue = this.adjList.get(i).size();
                        minVertex = i;
                    }
                }
            }
            
            return minVertex;
        }
        
        public String toString(){
            StringBuffer s = new StringBuffer("");
            for(int i=0; i<v; i++){
                s.append(i+": "+this.adjList.get(i)+"\n");
            }
            return s.toString();
        }
    }

    public static void main(String[] args) {
    	/* scan the input */
        Scanner input = new Scanner(System.in);
        int v = input.nextInt();
        int e = input.nextInt();
        // construct a graph with v vertices and e edges
        Graph g = new Graph(v,e);
        for(int i=0; i<e; i++){
            g.addEdge(input.nextInt(),input.nextInt());
        }

        // construct a path
        ArrayList<Integer> path = new ArrayList<>();
        // find vertex with minimum edges and start building the path there
        int currentVertex = g.getMinVertex();
        while(true){
            path.add(currentVertex);
            // find next vertex with minimum edges
            currentVertex = g.getNextVertex(currentVertex);
            if(currentVertex == -1)break;
        }
        // print the path size and path itself
        System.out.println(path.size());
        for(int i=0; i<path.size(); i++){
            System.out.print((path.get(i)+1)+" ");
        }
    }
}

