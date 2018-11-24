## Tutorials

GeeksforGeeks [sorting algorithms](https://www.geeksforgeeks.org/sorting-algorithms/)

Tutorialspoint Data Structures and Algorithms: [Sorting Algorithms](https://www.tutorialspoint.com/data_structures_algorithms/sorting_algorithms.htm)

brilliant.org [Sorting Algorithms](https://brilliant.org/wiki/sorting-algorithms/)

toptal.com [Sorting Algorithms](https://www.toptal.com/developers/sorting-algorithms)

## Solutions

#### Insertion Sort Challenges
###### Insertion Sort Part 1
[Description](https://www.hackerrank.com/challenges/insertionsort1/problem)

Java solution
```java
static void insertionSort1(int n, int[] arr) {
    int el = arr[n-1];
    int i = 0;
    while(arr[i] <= el){
        i++;
    }
    for(int j=n-1; j>i; j--){
        arr[j] = arr[j-1];
        for(int k:arr){
            System.out.print(k + " ");
        }
        System.out.println();
    }
    arr[i] = el;
        for(int k:arr){
            System.out.print(k + " ");
        }
        System.out.println();
}
```

###### Insertion Sort Part 2
[Description](https://www.hackerrank.com/challenges/insertionsort2/problem)

Java solution
```java
static void insertionSort2(int n, int[] arr) {
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        for(int k:arr){
            System.out.print(k + " ");
        }
        System.out.println();
    }
}
```

###### Correctness and the Loop Invariant
[Description](https://www.hackerrank.com/challenges/correctness-invariant/problem)

more on [Loop Invariant](https://www.cs.scranton.edu/~mccloske/courses/cmps144/invariants_lec.html)

Java solution
```java
public static void insertionSort(int[] A){
    for(int i = 1; i < A.length; i++){
        int value = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > value){
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = value;
    }

    printArray(A);
}
```

###### Running Time of Algorithms
[Description](https://www.hackerrank.com/challenges/runningtime/problem)

Java solution
```java
static int runningTime(int[] arr) {
    int nShifts = 0;
    for(int i = 1; i < arr.length; i++){
        int value = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > value){
            arr[j + 1] = arr[j];
            nShifts++;
            j = j - 1;
        }
        arr[j + 1] = value;
    }
    return nShifts;
}
```

###### Insertion Sort Advanced Analysis
[Description](https://www.hackerrank.com/challenges/insertion-sort/problem)

file: C++ [insertion_sort_advanced_analysis.cpp](insertion_sort_advanced_analysis.cpp)

#### Quick Sort Challenges
###### QuickSort 1 - Partition
[Description](https://www.hackerrank.com/challenges/quicksort1/problem)

```java
static int[] quickSort(int[] arr) {
        int temp=0;
        int pivot=arr[0];
        int pIndex=arr.length-1;
        for(int i=pIndex;i>0;i--){
            if(arr[i]>=pivot){
                temp=arr[i];
                arr[i]=arr[pIndex];
                arr[pIndex]=temp;
                pIndex--;
            }
        }
        temp=arr[pIndex];
        arr[pIndex]=arr[0];
        arr[0]=temp;
        return arr;
}
```

###### QuickSort 2 - Sorting
[Description](https://www.hackerrank.com/challenges/quicksort2/problem)

file: Java [QuickSort.java](QuickSort.java)

###### QuickSort In-Place
[Description](https://www.hackerrank.com/challenges/quicksort3/problem)

file: Java [QuickSortInPlace.java](QuickSortInPlace.java)

###### Running Time of QuickSort
[Description](https://www.hackerrank.com/challenges/quicksort4/problem)

file: C++ [running_time_of_quicksort.cpp](running_time_of_quicksort.cpp)

#### Counting Sort Challenges
###### Counting Sort 1
[Description](https://www.hackerrank.com/challenges/countingsort1/problem)

Java solution
```java
static int[] countingSort(int[] arr) {
    int[] a = new int[100];
    for(int i = 0; i<arr.length; i++){
        a[arr[i]]++;
    }
    return a;
}
```

###### Counting Sort 2
[Description](https://www.hackerrank.com/challenges/countingsort2/problem)

Java Solution
```java
public class Solution {
    static int num;
    public static void main(String[] args) {
        Scanner se=new Scanner(System.in);
        int n=se.nextInt();
        int ar[]=new int[n];
        int num[]=new int[n];
        int max=0;
        for(int i=0;i<n;i++){
            ar[i]=se.nextInt();
            if(ar[i]>max) max=ar[i];
            num[ar[i]]++;   
            }
         for(int i=0;i<=max;i++){
            for(int j=0;j<num[i];j++){
              System.out.print(i+" ");  
            }        
            }
        }
        
    }
```