### Breaking the Records

[Description](https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem)

```c++
vector<int> breakingRecords(vector<int> scores) {
	// to keep track of how many times max and min scores are broken
    vector<int> ans(2, 0); 
    int min_score = scores[0];
    int max_score = scores[0];
    if(scores.size() == 1){
        return ans;
    }
    for(int i=1; i<scores.size(); i++){
        if(scores[i] < min_score){
            ans[1]++;
            min_score = scores[i];
        }else if(scores[i] > max_score){
            ans[0]++;
            max_score = scores[i];
        }
    }
    return ans;
}
```