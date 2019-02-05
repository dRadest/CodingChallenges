/*
* https://www.interviewbit.com/problems/set-matrix-zeros/
* Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.
* idea: use first row and column to mark which columns and rows contain zeros
*/

void Solution::setZeroes(vector<vector<int> > &A) {
    int m=A.size(); // rows
    int n=A[0].size(); // columns
    // markers for first row and column
    int r1=0,c1=0;
    // check if first row has zeros
    for(int i=0;i<n;i++){
        if(A[0][i]==0){
            r1=1;
            break;
        }
    }
    // check if first column has zeros
    for(int i=0;i<m;i++){
        if(A[i][0]==0){
            c1=1;
            break;
        }
    }

    // traverse rest of the matrix
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(A[i][j]==0){ // zero found
                A[i][0]=0; // first element in the row
                A[0][j]=0; // element int he first column
            }
        }
    }
    // if zeros at column or row index zero
    // set element with both those indecies to zero
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(A[i][0]==0||A[0][j]==0){
                A[i][j]=0;   
            }
        }
    }
    // fill first row with zeroes
    if(r1==1){
        for(int i=0;i<n;i++)
         A[0][i]=0;
    }    
    // fill first column with zeroes
    if(c1==1){
        for(int i=0;i<m;i++){
            A[i][0]=0;   
        }
    }
}
