/*
*
* https://www.interviewbit.com/problems/distribute-candy/
*
*There are N children standing in a line. Each child is assigned a rating value.
*
*    You are giving candies to these children subjected to the following requirements:
*
*        Each child must have at least one candy.
*        Children with a higher rating get more candies than their neighbors.
*
* What is the minimum candies you must give?
*
* Sample Input :
*
*	Ratings : [1 2]
*	
* Sample Output :
*
*	3
*
*	The candidate with 1 rating gets 1 candy and candidate with rating cannot get 1 candy as 1 is its neighbor. 
*	So rating 2 candidate gets 2 candies. In total, 2+1 = 3 candies need to be given out.
*/

int Solution::candy(vector<int> &A) {
    int n=A.size();
    // give each child a candy
    vector<int>candies(n);
    for(int i=0;i<n;i++){
        candies[i]=1;
    }
    for(int i=1;i<n;i++){
        // current child's rating equals previous'
        if(A[i]==A[i-1]) continue;
        // current child's rating higher than previous'
        // current child has less or equal candies than previous
        else if(A[i]>A[i-1]&&candies[i]<=candies[i-1]){
            // current child gets one more candy than previous has
            candies[i]=candies[i-1]+1;
        }
        else{ // go back from this position
            int j=i-1;
            // fix candy distribution
            // while rating is greater but received candies are less or equal
            while(j>=0&&A[j]>A[j+1]&candies[j]<=candies[j+1]){
                candies[j]=candies[j+1]+1;
                j--;
            }
        }
    }
    // sum all the candies
    int ans=candies[0];
    for(int i=1;i<n;i++){
        ans+=candies[i];
    }
    return ans;
}

