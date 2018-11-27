import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    private static class Node<T> {
		private final List<Node<T>> childNodes = new ArrayList<>();
		
		private void addChildNode(Node<T> node) {
			this.childNodes.add(node);
		}
	}

	private static int[] decomposeTree(Node<Integer> node) {
		
		int count = 0, edgesToRemove = 0;
		for(Node<Integer> childNode : node.childNodes) {
			final int[] tmpMetadata = decomposeTree(childNode);
			edgesToRemove += tmpMetadata[1];
			if(tmpMetadata[0] % 2 == 0) {
				edgesToRemove++;
			} else {
				count += tmpMetadata[0];
			}
		}
		count++;
		return new int[]{count, edgesToRemove};
	}
	
	public static void main(String[] args) {
		final Scanner in = new Scanner(System.in);
		final int N = in.nextInt();
		final int M = in.nextInt();
		
		final Node<Integer>[] treeNodes = (Node<Integer>[]) new Node[N];
		for(int i = 0; i < M; i++) {
			final int node1 = in.nextInt() - 1;
			final int node2 = in.nextInt() - 1;
			
			treeNodes[node1] = (treeNodes[node1] == null ? new Node<Integer>() : treeNodes[node1]);
			treeNodes[node2] = (treeNodes[node2] == null ? new Node<Integer>() : treeNodes[node2]);
			
			if(node1 < node2) {
				treeNodes[node1].addChildNode(treeNodes[node2]);
			} else {
				treeNodes[node2].addChildNode(treeNodes[node1]);
			}
		}
		
		final int[] metadata = decomposeTree(treeNodes[0]);
		
		System.out.println(metadata[1]);
		
		in.close();
	}
}