### Compare the Triplets

Problem on [HackerRank](https://www.hackerrank.com/challenges/compare-the-triplets/problem)

C++ solution
```c++
vector<int> compareTriplets(vector<int> a, vector<int> b) {
    vector<int> result(2);
    result[0] = 0;
    result[1] = 0;
    for(int i=0; i<3; i++){
        if(a[i] > b[i]){
            result[0]++;
        } else if(a[i] < b[i]){
            result[1]++;
        }
    }
    return result;
}
``` 

### Diagonal Difference

Problem on [HackerRank](https://www.hackerrank.com/challenges/diagonal-difference/problem)

C++ solution
```c++
int diagonalDifference(vector<vector<int>> arr) {
    int n = arr.size();
    int rightd = 0, leftd = 0; // diagonals
    for(int i=0; i<n; i++){
        rightd += arr[i][i];
        leftd += arr[i][n-1-i];
    }
    
    return abs(rightd - leftd);


}
```

### Staircase

Problem on [HackerRank](https://www.hackerrank.com/challenges/staircase/problem)

C/C++ solution
```c++
void staircase(int n) {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j >= n - 1 - i){
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
```
