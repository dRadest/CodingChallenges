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

### Time Conversion

Problem on [HackerRank](https://www.hackerrank.com/challenges/time-conversion/problem)

C++ solution
```c++
#include <bits/stdc++.h>

using namespace std;

string timeConversion(string s) {
    bool pm = true;
    if(s[8] == 'A'){
        pm = false;
    }
    string hour;
    string base = s.substr(2, 6);
    if(pm){
        if(s.compare(0, 2, "01") == 0){
            hour = "13";
        }else if(s.compare(0, 2, "02") == 0){
            hour = "14";
        }else if(s.compare(0, 2, "03") == 0){
            hour = "15";
        }else if(s.compare(0, 2, "04") == 0){
            hour = "16";
        }else if(s.compare(0, 2, "05") == 0){
            hour = "17";
        }else if(s.compare(0, 2, "06") == 0){
            hour = "18";
        }else if(s.compare(0, 2, "07") == 0){
            hour = "19";
        }else if(s.compare(0, 2, "08") == 0){
            hour = "20";
        }else if(s.compare(0, 2, "09") == 0){
            hour = "21";
        }else if(s.compare(0, 2, "10") == 0){
            hour = "22";
        }else if(s.compare(0, 2, "11") == 0){
            hour = "23";
        }else if(s.compare(0, 2, "12") == 0){
            hour = "12";
        }
    } else {
        if(s.compare(0, 2, "12") == 0){
            hour = "00";
        }else {
            hour = s.substr(0, 2);
        }
    }
    return hour.append(base);

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
```
