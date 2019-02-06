/*
* https://www.interviewbit.com/problems/square-root-of-integer/
* Implement int sqrt(int x).
* Compute and return the square root of x.
* If x is not a perfect square, return floor(sqrt(x))
*
* geeksforgeeks:
* https://www.geeksforgeeks.org/square-root-of-an-integer/
*/

int binarySearch(int A, int start, int end){
    int mid = floor(start + (end-start)/2);
    if(start <= end){
    	// mid*mid == A
        if(mid <= (A/mid) && (mid+1) > (A/(mid+1))){
            return mid;         
        }
        else if( mid < (A/mid) ){ // mid*mid < A
            // discard first half
            return binarySearch(A, mid+1, end);
        }
        else if( mid > (A/mid) ){ // mid*mid > A
            // discard second half
            return binarySearch(A, start, end);
        }
    }
    
    return mid;
}

int Solution::sqrt(int A) {
    if(A==0 || A==1){
        return A;
    }else{
        return binarySearch(A, 0, A);
    }
}
