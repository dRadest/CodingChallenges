import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

// class to represent graph
class Graph{
	int vertices;
	// adjacency list presented with array list
	ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();

	//constructor
	public Graph(int v){
		this.vertices = v;
		for (int i=0; i<this.vertices; i++) {
			this.adj.add(new ArrayList<Integer>());
		}
	}
}


public class HamCycleAdj {

	// method to check if the vertex v can be added at index 'pos'in the Hamiltonian Cycle 
    // constructed so far (stored in 'path[]')
    private static boolean isSafe(int v, Graph graph, int path[], int pos) { 
        // Check if this vertex is an adjacent vertex of the previously added vertex
        if (graph.adj.get(path[pos - 1]).contains(v) == false) 
            return false; 
  
        /* Check if the vertex has already been included. 
           This step can be optimized by creating an array 
           of size V */
        for (int i = 0; i < pos; i++) 
            if (path[i] == v) 
                return false; 
  
        return true; 
    } 

	// method that recursively builds Hamiltonian cycle if possible
    private static boolean canBuildHamCycle(Graph graph, int[] path, int pos) 
    { 
        // base case: all vertices included 
        if (pos == graph.vertices) { 
            // And if there is an edge from the last included 
            // vertex to the first vertex 
            if (graph.adj.get(path[pos-1]).contains(path[0])) 
                return true; 
            else
                return false; 
        } 
  
        // Try different vertices as a next candidate in 
        // Hamiltonian Cycle. We don't try for 0 as we 
        // included 0 as starting point in in hamCycle() 
        for (int v = 1; v < graph.vertices; v++) { 
            // Check if this vertex can be added to Hamiltonian Cycle
            if (isSafe(v, graph, path, pos)) { 
                path[pos] = v; 
  
                /* recur to construct rest of the path */
                if (canBuildHamCycle(graph, path, pos + 1)) 
                    return true; 
  
                // If adding vertex v doesn't lead to a solution, then remove it 
                path[pos] = -1; 
            } 
        } 
  
        // If no vertex can be added to Hamiltonian Cycle constructed so far, then return false
        return false; 
    } 

    // method to print solution 
    private static void printSolution(int[] path) { 
        System.out.println("Solution Exists: Following is one Hamiltonian Cycle"); 
        for (int i = 0; i < path.length; i++) 
            System.out.print(" " + path[i] + " "); 
  
        // Let us print the first vertex again to show the complete cycle 
        System.out.println(" " + path[0] + " "); 
    } 

	// method that prints hamiltonian cycle or states that solution doesn't exist
	private static void hamCycle(Graph graph){
		int[] path = new int[graph.vertices];
		for (int i=0; i<graph.vertices; i++) {
			path[i] = -1; // not in the solution
		}

		path[0] = 0; // start at vertex 0
		if(!canBuildHamCycle(graph, path, 1)){
			System.out.println("Solution does not exist");
		}else{
			printSolution(path);
		}

	}

	public static void main(String[] args){
		System.out.println("Hamiltonian cycle in the making");
		
		// construct a graph
		Graph g = new Graph(5);
		g.adj.get(0).add(1);
		g.adj.get(0).add(3);
		g.adj.get(1).add(0);
		g.adj.get(1).add(2);
		g.adj.get(1).add(3);
		g.adj.get(1).add(4);
		g.adj.get(2).add(1);
		g.adj.get(2).add(4);
		g.adj.get(3).add(0);
		g.adj.get(3).add(1);
		g.adj.get(3).add(4);
		g.adj.get(4).add(1);
		g.adj.get(4).add(2);
		g.adj.get(4).add(3);

		hamCycle(g);
		

	}
}