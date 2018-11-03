import java.util.ArrayList;
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

import java.util.ArrayList;
import java.util.Scanner;

enum Color {
    RED, GREEN
}

abstract class Tree {

    private int value;
    private Color color;
    private int depth;

    public Tree(int value, Color color, int depth) {
        this.value = value;
        this.color = color;
        this.depth = depth;
    }

    public int getValue() {
        return value;
    }

    public Color getColor() {
        return color;
    }

    public int getDepth() {
        return depth;
    }

    public abstract void accept(TreeVis visitor);
}

class TreeNode extends Tree {

    private ArrayList<Tree> children = new ArrayList<>();

    public TreeNode(int value, Color color, int depth) {
        super(value, color, depth);
    }

    public void accept(TreeVis visitor) {
        visitor.visitNode(this);

        for (Tree child : children) {
            child.accept(visitor);
        }
    }

    public void addChild(Tree child) {
        children.add(child);
    }
}

class TreeLeaf extends Tree {

    public TreeLeaf(int value, Color color, int depth) {
        super(value, color, depth);
    }

    public void accept(TreeVis visitor) {
        visitor.visitLeaf(this);
    }
}

abstract class TreeVis
{
    public abstract int getResult();
    public abstract void visitNode(TreeNode node);
    public abstract void visitLeaf(TreeLeaf leaf);

}

/******************************* SOLUTION *******************************/
class SumInLeavesVisitor extends TreeVis {
    private int result = 0;
    public int getResult() {
        //implement this
        return result;
    }

    public void visitNode(TreeNode node) {
        //implement this
    }

    public void visitLeaf(TreeLeaf leaf) {
        //implement this
        result += leaf.getValue();
    }
}

class ProductOfRedNodesVisitor extends TreeVis {
    private long result = 1;
    private final int M = 1000000007;
    public int getResult() {
        //implement this
        return (int) result;
    }

    public void visitNode(TreeNode node) {
        //implement this
        if(node.getColor().equals(Color.RED)){
            result = (result * node.getValue()) % M;
        }
    }

    public void visitLeaf(TreeLeaf leaf) {
        //implement this
        if(leaf.getColor().equals(Color.RED)){
            result = (result * leaf.getValue()) % M;
        }
    }
}

class FancyVisitor extends TreeVis {
    private int resultA = 0;
    private int resultB = 0;
    public int getResult() {
        //implement this
        return Math.abs(resultA - resultB);
    }

    public void visitNode(TreeNode node) {
        //implement this
        int depth = node.getDepth();
        if(depth % 2 == 0){
            resultA += node.getValue();
        }
    }

    public void visitLeaf(TreeLeaf leaf) {
        //implement this
        if(leaf.getColor().equals(Color.GREEN)){
            resultB += leaf.getValue();
        }
    }
}

public class Solution {
    private static int nodeValues[]; // holds values of nodes
    private static Color nodeColors[]; // holds colors of nodes
    // map to indicate the node (key) and its set of children (value)
    private static Map<Integer, Set<Integer>> nodesMap = new HashMap<>();

  
    public static Tree solve() {

        Scanner in = new Scanner(System.in);
        int numberOfNodes = in.nextInt();
        // scan the values of nodes
        nodeValues = new int[numberOfNodes];
        for(int index = 0; index < numberOfNodes; index++) {
            nodeValues[index] = in.nextInt();
        }

        // scan the colors of nodes (0 = red, 1 = green)
        nodeColors = new Color[numberOfNodes];
        for(int index = 0; index < numberOfNodes; index++) {
            nodeColors[index] = (in.nextInt() == 0) ? Color.RED : Color.GREEN;
        }

        Tree rootNode;
        // if only one node, tree node is a leaf node
        if(numberOfNodes == 1) {
            rootNode = new TreeLeaf(nodeValues[0], nodeColors[0], 0);
        }
        else {
            // scan the edges (u and v are connected nodes)
            for(int index = 0; index < (numberOfNodes - 1); index++) {
                int u = in.nextInt();
                int v = in.nextInt();
                // get the set of nodes node u is connected to
                Set<Integer> uEdges = nodesMap.get(u);
                // if it doesn't exist
                if(uEdges == null) {
                    // create a new set
                    uEdges = new HashSet<>();
                }
                // add v to the set
                uEdges.add(v);
                // assign extended set of edges to u in the map
                nodesMap.put(u, uEdges);
                // get the set of nodes node v is connected to
                Set<Integer> vEdges = nodesMap.get(v);
                // if it doesn't exist
                if(vEdges == null) {
                    // create a new set
                    vEdges = new HashSet<>();
                }
                // add u to the set
                vEdges.add(u);
                // assign extended set of edges to v in the map
                nodesMap.put(v, vEdges);
            }

            // root node is a TreeNode
            rootNode = new TreeNode(nodeValues[0], nodeColors[0], 0);
            // get the set of nodes root is connected to (root index is 1)
            Set<Integer> rootEdges = nodesMap.get(1);
            // iterate through the nodes root is connected to
            Iterator<Integer> rootIterator = rootEdges.iterator();
            while(rootIterator.hasNext()) {
                // grab the next node in the set
                Integer nodeIdentifier = rootIterator.next();
                // remove root node from the set of edges of the node
                nodesMap.get(nodeIdentifier).remove(1);
                // create edge between root node and the node
                createEdge(rootNode, nodeIdentifier);
            }
    }

    return rootNode;
}
private static void createEdge(Tree parentNode, Integer nodeIdentifier) {
    // get the set of nodes given node is connected to        
    Set<Integer> nodeEdges = nodesMap.get(nodeIdentifier);
    // variable to indicate that the node has children
    boolean hasChild = false;
    // set of children nodes is not null and empty
    if(nodeEdges != null && !nodeEdges.isEmpty())
        hasChild = true;

    if(hasChild) { // tree node
        // construct the node
        TreeNode node = new TreeNode(nodeValues[nodeIdentifier - 1], nodeColors[nodeIdentifier - 1], parentNode.getDepth() + 1);
        // add it as a child to parent node
        ((TreeNode) parentNode).addChild(node);
        // iterate through the nodes this node is connected to
        Iterator<Integer> nodeIterator = nodeEdges.iterator();
        while(nodeIterator.hasNext()) {
            // grab the child node in the set
            Integer neighborNodeIdentifier = nodeIterator.next();
            // remove this node from its child set of edges
            nodesMap.get(neighborNodeIdentifier).remove(nodeIdentifier);
            // recursevily create edge between this node and its child
            createEdge(node, neighborNodeIdentifier);
        }
    }
    else { // leaf node
        // construct the node
        TreeLeaf leaf = new TreeLeaf(nodeValues[nodeIdentifier - 1], nodeColors[nodeIdentifier - 1], parentNode.getDepth() + 1);
        // add it as a child to parent node
        ((TreeNode) parentNode).addChild(leaf);
    }
} 


/******************************* SOLUTION *******************************/


    public static void main(String[] args) {
        Tree root = solve();
        SumInLeavesVisitor vis1 = new SumInLeavesVisitor();
        ProductOfRedNodesVisitor vis2 = new ProductOfRedNodesVisitor();
        FancyVisitor vis3 = new FancyVisitor();

        root.accept(vis1);
        root.accept(vis2);
        root.accept(vis3);

        int res1 = vis1.getResult();
        int res2 = vis2.getResult();
        int res3 = vis3.getResult();

        System.out.println(res1);
        System.out.println(res2);
        System.out.println(res3);
    }
}

