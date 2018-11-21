* [Breaking the Records](#breaking-the-records)
* [Cavity Map](#cavity-map)
* [Manasa and Stones](#manasa-and-stones)
* [Forming a Magic Square](#forming-a-magic-square)
* [Encryption](#encryption)
* [Absolute Permutation](#absolute-permutation)
* [Bomberman Game](#bomberman-game)
* [Larry's Array](#larrys-array)
* [Almost Sorted](#almost-sorted)


### Breaking the Records

[Description](https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem)

C++ Solution
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

### Cavity Map

[Description](https://www.hackerrank.com/challenges/cavity-map/problem)

C++ solution
```c++
vector<string> cavityMap(vector<string> grid) {
    int n = grid.size();
    vector<string> ans(grid);
    for(int i=1; i<n-1; i++){
        for(int j=1; j<ans[i].length()-1; j++){
            int cur = ans[i][j] - '0';
            int top = ans[i-1][j] - '0';
            int left = ans[i][j-1] - '0';
            int bottom = ans[i+1][j] - '0';
            int right = ans[i][j+1] - '0';
            if(cur > top && cur > left && cur > bottom && cur > right){
                ans[i][j] = 'X';
            }
        }
    }
    return ans;
}
```

### Manasa and Stones

[Description](https://www.hackerrank.com/challenges/manasa-and-stones/problem)

C++ solution
```c++
vector<int> stones(int n, int a, int b) {
    vector<int> ans;
    set<int> set;
    int mina = min(a, b);
    int maxb = max(a, b);
    n--;
    for(int i=0; i<=n; i++){
        int element = i*maxb+(n-i)*mina;
        set.insert(element);
    }
    std::set<int>::iterator it = set.begin();
    while(it != set.end()){
        ans.push_back(*it);
        it++;
    }
    return ans;
}
```

### Forming a Magic Square

[Description](https://www.hackerrank.com/challenges/magic-square-forming/problem)

file: C++ [forming_a_magic_Square.cpp](forming_a_magic_square.cpp)

GeeksforGeeks [example](https://www.geeksforgeeks.org/minimum-cost-convert-3-x-3-matrix-magic-square/)

### Encryption

[Description](https://www.hackerrank.com/challenges/encryption/problem)

file: C++ [encryption.cpp](encryption.cpp)

### Absolute Permutation

[Description](https://www.hackerrank.com/challenges/absolute-permutation/problem)

file: C++ [absolute_permutation.cpp](absolute_permutation.cpp)

### Bomberman Game

[Description](https://www.hackerrank.com/challenges/bomber-man/problem)

file: C++ [bomberman_game.cpp](bomberman_game.cpp)

### Larry's Array

[Description](https://www.hackerrank.com/challenges/larrys-array/problem)

file: 

Java [LarryArray.java](LarryArray.java)

C++ [larry_array_setter.cpp](larry_array_setter.cpp)

### Almost Sorted

[Description](https://www.hackerrank.com/challenges/almost-sorted/problem)

file: Java [AlmostSorted.java](AlmostSorted.java)

_from the editorial:_
> The idea of this algorithm is first to check whether the _input_ is already sorted. If it is, just return yes. Otherwise, to sort the input, find the leftmost and the rightmost index where _input[index] != sortedInput[index]_. After we get these two indices(we will get at least two indices, if input is not sorted), we can check swap or reverse. When we check swap or reverse, we can just check if the involved part _input[lindex:rindex+1]_ can be sorted or not. If it's sortable and _r - l = 1_ , use swap. If _r - l > 1_, use reverse.