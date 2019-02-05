/*
* https://www.interviewbit.com/problems/spiral-order-matrix-i/
* Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.
*/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int> result;
    // variables to keep track of rows/columns processed
    // and direction in which we are traversing the matrix
    int rows = A.size();
    int cols = A[0].size();
    int top = 0;
    int bottom = rows-1;
    int left = 0;
    int right = cols-1;
    int dir = 0; // 0 for L->R, 1 for T->B, 2 for R->L, 3 for B->T
    
    while(top <= bottom && left <= right){
        if(dir == 0){ // left to right
            for(int j = left; j <= right; j++){
                result.push_back(A[top][j]);
            }
            top++;
        }
        else if(dir == 1){ // top to bottom
            for(int i = top; i <= bottom; i++){
                result.push_back(A[i][right]);
            }
            right--;
            
        }
        else if(dir == 2){ // right to left
            for(int j = right; j >= left; j--){
                result.push_back(A[bottom][j]);
            }
            bottom--;
            
        }
        else if(dir == 3){ // bottom to top
            for(int i = bottom; i >= top; i--){
                result.push_back(A[i][left]);
            }
            left++;
            
        }
        dir = (dir+1)%4;
    }
    
return result;
}
