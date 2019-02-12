/*
*
* https://www.interviewbit.com/problems/knight-on-chess-board/
*
* Knight movement on a chess board
*
* Given any source point and destination point on a chess board, we need to find whether Knight can move to the destination or not.
*
* The above figure details the movements for a knight ( 8 possibilities ). Note that a knight cannot go out of the board.
*
* If yes, then what would be the minimum number of steps for the knight to move to the said point.
* If knight can not move from the source point to the destination point, then return -1
*
* Input:
*
* N, M, x1, y1, x2, y2
* where N and M are size of chess board
* x1, y1  coordinates of source point
* x2, y2  coordinates of destination point
*
* Output:
*
* return Minimum moves or -1
*
* Example
*
*	Input : 8 8 1 1 8 8
*	Output :  6
*/

/**
 * code adopted from (O(n^2)):
 * https://www.geeksforgeeks.org/minimum-steps-reach-target-knight/
 * with dynamic programming approach:
 * https://www.geeksforgeeks.org/minimum-steps-reach-target-knight-set-2/
**/

// structure for storing cell's data 
struct cell 
{ 
    int x, y; 
    int dis; 
    cell() {} 
    cell(int x, int y, int dis) : x(x), y(y), dis(dis) {} 
}; 
  
// Utility method returns true if (x, y) lies inside the Board 
bool isInside(int x, int y, int N, int M) 
{ 
    if (x >= 1 && x <= N && y >= 1 && y <= M) {
        return true; 
    }
    return false; 
} 
  
// Method returns minimum step to reach target position 
int minStepToReachTarget(int knightPos[], int targetPos[], int N, int M) 
{ 
    // x and y direction, where a knight can move 
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2}; 
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1}; 
  
    // queue for storing states of knight in board 
    queue<cell> q; 
  
    // push starting position of knight with 0 distance 
    q.push(cell(knightPos[0], knightPos[1], 0)); 
  
    cell t; 
    int x, y; 
    bool visit[N + 1][M + 1]; 
  
    // make all cell unvisited 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            visit[i][j] = false; 
        }
    }
  
    // visit starting state 
    visit[knightPos[0]][knightPos[1]] = true; 
  
    // loop until queue has elements
    while (!q.empty()) 
    { 
        t = q.front(); 
        q.pop(); 
  
        // if current cell is equal to target cell, 
        // return its distance 
        if (t.x == targetPos[0] && t.y == targetPos[1]) {
            return t.dis; 
        }
  
        // loop for all reachable states 
        for (int i = 0; i < 8; i++) 
        { 
            x = t.x + dx[i]; 
            y = t.y + dy[i]; 
  
            // If reachable state is not yet visited and 
            // inside board, push that state into queue 
            if (isInside(x, y, N, M) && !visit[x][y]) { 
                visit[x][y] = true; 
                q.push(cell(x, y, t.dis + 1)); 
            } 
        } 
    } 
    return -1;
} 
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    int knightPos[] = {C, D}; 
    int targetPos[] = {E, F}; 
    return minStepToReachTarget(knightPos, targetPos, A, B);
}
