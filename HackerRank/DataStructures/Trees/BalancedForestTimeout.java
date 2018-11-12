import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;


/* times out on test cases 3, 4 and 5 */
public class Solution {

    /*
    * helper method to perform a depth-first traversal of a graph
    * starting at the given node / vertex
    * saves visited nodes in a TreeSet
    */
    static void dfs(int node, TreeSet<Integer> treeSet, HashMap<Integer, LinkedList<Integer>> map){
        treeSet.add(node);
        LinkedList<Integer> workingSet = map.get(node);
        for (int i=0; i<workingSet.size(); i++) {
            int nextNode = workingSet.get(i);
            if(!treeSet.contains(nextNode)){
                dfs(nextNode, treeSet, map);
            }
        }

    }

    /*
    * helper method that constructs a map representing a tree
    * given the edges
    */
    static HashMap<Integer, LinkedList<Integer>> constructTree(int[][] edges, int[] c){
        HashMap<Integer, LinkedList<Integer>> map = new HashMap<Integer, LinkedList<Integer>>();
        int nnodes = c.length;
        for (int i=0; i<nnodes; i++) {
            map.put(i+1, new LinkedList<>());
        }
        int nedges = edges.length;
        for (int i=0; i<nedges; i++) {
            int nodeA = edges[i][0];
            int nodeB = edges[i][1];
            map.get(nodeA).add(nodeB);
            map.get(nodeB).add(nodeA);
        }
        return map;
    }

    /* 
    * constructs subtrees cutting two edges 
    * and returns the number to add to one to obtain balanced trees
    * -1 if no such number exists
    */
    static int cut_edges(int a, int b, int[][] edges, int[] c){
        // prepare sets to contain edges in a subtree
        TreeSet<Integer> firstSubtree = new TreeSet<>();
        TreeSet<Integer> secondSubtree = new TreeSet<>();
        TreeSet<Integer> thirdSubtree = new TreeSet<>();
        double firstSum = 0, secondSum = 0, thirdSum = 0;

        // construct a map
        HashMap<Integer, LinkedList<Integer>> map = constructTree(edges, c);
        // first cut
        Integer fA = edges[a][0];
        Integer fB = edges[a][1];
        // apply first and cut to the map
        map.get(fA).remove(fB);
        map.get(fB).remove(fA);

        // traverse the map, construct subtrees and calculate their values
        Set set = map.entrySet();
        Iterator iterator = set.iterator();
        // construct the first sub-tree
        Map.Entry mentry = (Map.Entry) iterator.next();
        dfs((Integer)mentry.getKey(), firstSubtree, map);
        while(iterator.hasNext()){
            mentry = (Map.Entry) iterator.next();
            int currentNode = (Integer)mentry.getKey();
            if (firstSubtree.contains(currentNode)) {
                continue;
            } else if (secondSubtree.isEmpty()) {
                dfs(currentNode, secondSubtree, map);
            } else {
                continue;
            }
        }

        // calculate the sums of both subtrees
        while(!firstSubtree.isEmpty()){
            firstSum += c[firstSubtree.pollFirst() - 1];
        }
        while(!secondSubtree.isEmpty()){
            secondSum += c[secondSubtree.pollFirst() - 1];
        }

        if (firstSum == secondSum) {
            return (int)firstSum;
        }

        // re-initialize variables
        firstSum = 0;
        secondSum = 0;
        firstSubtree.clear();
        secondSubtree.clear();

        // apply second cut to the map
        Integer sA = edges[b][0];
        Integer sB = edges[b][1];
        map.get(sA).remove(sB);
        map.get(sB).remove(sA);

        // traverse the map, construct subtrees and calculate their values
        set = map.entrySet();
        iterator = set.iterator();
        // construct the first sub-tree
        mentry = (Map.Entry) iterator.next();
        dfs((Integer)mentry.getKey(), firstSubtree, map);
        while(iterator.hasNext()){
            mentry = (Map.Entry) iterator.next();
            int currentNode = (Integer) mentry.getKey();
            if (firstSubtree.contains(currentNode)) {
                continue;
            } else if (secondSubtree.isEmpty()) {
                dfs(currentNode, secondSubtree, map);
            } else if (secondSubtree.contains(currentNode)) {
                continue;
            } else {
                dfs(currentNode, thirdSubtree, map);
            }
        }

        // calculate the sum of all subtrees
        while(!firstSubtree.isEmpty()){
            int index = firstSubtree.pollFirst()-1;
            firstSum += c[index];
        }
        while(!secondSubtree.isEmpty()){
            int index = secondSubtree.pollFirst()-1;
            secondSum += c[index];
        }
        while(!thirdSubtree.isEmpty()){
            int index = thirdSubtree.pollFirst()-1;
            thirdSum += c[index];
        }

        if (firstSum == secondSum && firstSum >= thirdSum) {
            return (int)(firstSum - thirdSum);
        } else if (firstSum == thirdSum && firstSum >= secondSum){
            return (int)(firstSum - secondSum);
        } else if (secondSum == thirdSum && secondSum >= firstSum) {
            return (int)(secondSum - firstSum);
        } else {
            return -1;
        }
    }

    // Complete the balancedForest function below.
    static int balancedForest(int[] c, int[][] edges) {
        int nedges = edges.length;
        int nnodes = c.length;
        if (nnodes == 1) {
            return c[0];
        } else if (nnodes == 2) {
            return Math.abs(c[0]-c[1]);
        } else if (nnodes == 3){
            if (c[0] == c[1] && c[0] >= c[2]) {
                return (c[0] - c[2]);
            } else if (c[0] == c[2] && c[0] >= c[1]) {
                return (c[0] - c[1]);
            } else if (c[1] == c[2] && c[1] >= c[0]) {
                return (c[1] - c[0]);
            } else {
                return -1;
            }
        }

        int resultA = -1;
        // traverse edges
        for (int i=0; i<nedges - 1; i++) {
            for (int j=i+1; j < nedges; j++) {
                int result = cut_edges(i, j, edges, c);
                if(result != -1 && (resultA == -1 || resultA > result)){
                    resultA = result;
                }
            }
        }
        
        return resultA;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int[] c = new int[n];

            String[] cItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int i = 0; i < n; i++) {
                int cItem = Integer.parseInt(cItems[i]);
                c[i] = cItem;
            }

            int[][] edges = new int[n - 1][2];

            for (int i = 0; i < n - 1; i++) {
                String[] edgesRowItems = scanner.nextLine().split(" ");
                scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

                for (int j = 0; j < 2; j++) {
                    int edgesItem = Integer.parseInt(edgesRowItems[j]);
                    edges[i][j] = edgesItem;
                }
            }

            int result = balancedForest(c, edges);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
