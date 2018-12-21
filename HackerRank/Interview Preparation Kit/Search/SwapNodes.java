import java.io.*;
import java.util.*;

public class Solution {
    
    class node {
        node left, right;
        int data;
        node(int x) {
            this.data = x;
            this.left = this.right = null;
        }
    }
    
    void inorder(node t) {
        if(t == null)   return;
        inorder(t.left);
        System.out.print(t.data + " ");
        inorder(t.right);
    }
    
    void dfs(node t, int y) {
        if(t == null)   return;
        // add node label (at depth y) to the arraylist depth at index y 
        depth[y].add(t.data);
        dfs(t.left, y + 1);
        dfs(t.right, y + 1);
    }
    
    node tree[];
    ArrayList<Integer> depth[];

    void solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        tree = new node[n + 1];
        depth = new ArrayList[n + 1];
        for(int i = 1; i <= n; i++) {
            tree[i] = new node(i);
            depth[i] = new ArrayList<>();
        }
        
        for(int i = 1; i <= n; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            if(l != -1) {
                tree[i].left = tree[l];
            }
            if(r != -1) {
                tree[i].right = tree[r];
            }
        }
        
        dfs(tree[1], 1);
        
        int t = sc.nextInt();
        while(t-- > 0) {
            int k = sc.nextInt();
            int h = k;
            while(h <= n) {
                // swap children of each node at depth h
                for(int d : depth[h]) {
                    node temp = tree[d].left;
                    tree[d].left = tree[d].right;
                    tree[d].right = temp;
                }
            // h is all the possible multiples of k where we have to swap nodes
                h += k;
            }
            inorder(tree[1]);
            System.out.println();
        }
    }
    
    public static void main(String[] args) {
        new Solution().solve();
    }
}