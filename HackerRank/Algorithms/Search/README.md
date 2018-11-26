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

### Missing Numbers
[Description](https://www.hackerrank.com/challenges/missing-numbers/problem)

Java solution
```java
public static void main(String[] args) {
    //read in the data
	int[] a = new int[10001]; //initialized with 0's
	Scanner in = new Scanner(System.in);
	int n = in.nextInt();
	//readin in list A
	for(int i=0; i<n; i++) {
		a[in.nextInt()]--;
	}
	int m = in.nextInt();
	for(int i=0; i<m; i++) {
		a[in.nextInt()]++;
	}
	in.close();
	
	//print out all the indexes where value is greater than 0
	for (int i = 0; i < 10001; i++) {
		if(a[i] > 0)
			System.out.print(i + " ");
	}
}
```
Java solution using HashMap

file: Java [MissingNumbers.java](MissingNumbers.java) 

### Sherlock And Array
[Description](https://www.hackerrank.com/challenges/sherlock-and-array/problem)

file: Java [SherlockAndArray.java](SherlockAndArray.java)

### Hackerland Radio Transmitters
[Description](https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem)

file: Java [HackerlandRadioTransmitters.java](HackerlandRadioTransmitters.java)