import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    static int ROW;
    static int COL;

    // A function to check if a given cell (row, col) can
    // be included in DFS
    static boolean isSafe(int M[][], int row, int col, boolean visited[][]) {
        // row number is in range, column number is in range
        // and value is 1 and not yet visited
        return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col] == 1 && !visited[row][col]);
    }

    // A utility function to do DFS for a 2D boolean matrix.
    // It only considers the 8 neighbors as adjacent vertices
    static int dfs(int M[][], int row, int col, boolean visited[][]) {
        // These arrays are used to get row and column numbers
        // of 8 neighbors of a given cell
        int rowNbr[] = new int[] { -1, -1, -1, 0, 0, 1, 1, 1 };
        int colNbr[] = new int[] { -1, 0, 1, -1, 1, -1, 0, 1 };

        // Mark this cell as visited
        visited[row][col] = true;

        int count = 1;

        // Recur for all connected neighbours
        for (int k = 0; k < 8; ++k){
            if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited)){
                count += dfs(M, row + rowNbr[k], col + colNbr[k], visited);
            }
        }
        return count;
    }

    // Complete the maxRegion function below.
    static int maxRegion(int[][] grid) {
        ROW = grid.length;
        COL = grid[0].length;
        // keep track of visited nodes
        boolean[][] visited = new boolean[ROW][COL];
        // maximum connected nodes
        int maxcount = 0;
        // traverse the matrix  
        for(int i=0; i<ROW; i++){
            for(int j=0; j<COL; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    int count = dfs(grid, i, j, visited);
                    if(count > maxcount){
                        maxcount = count;
                    }
                }
            }
        }
        return maxcount;


    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int m = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[][] grid = new int[n][m];

        for (int i = 0; i < n; i++) {
            String[] gridRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < m; j++) {
                int gridItem = Integer.parseInt(gridRowItems[j]);
                grid[i][j] = gridItem;
            }
        }

        int res = maxRegion(grid);

        bufferedWriter.write(String.valueOf(res));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
