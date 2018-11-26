GeeksforGeeks [Searching algorithms](https://www.geeksforgeeks.org/searching-algorithms/)

### Ice Cream Parlor
[Description](https://www.hackerrank.com/challenges/icecream-parlor/problem)

Java solution
```java
static int[] icecreamParlor(int m, int[] arr) {
    int[] ans = new int[2];
    int n = arr.length;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == m) {
                ans[0] = i + 1;
                ans[1] = j + 1;
                break;
            }
        }
    }
    return ans;
}
```