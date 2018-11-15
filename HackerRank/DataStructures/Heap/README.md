# Theory

Wikipedia [article](https://en.wikipedia.org/wiki/Heap_(data_structure)) on heap data structure

GeeksforGeeks list of [articles](https://www.geeksforgeeks.org/heap-data-structure/) on Heap Data Structure

TutorialsPoint heap [tutorial](https://www.tutorialspoint.com/data_structures_algorithms/heap_data_structure.htm)

# Solutions

#### QHEAP1

Problem on [HackerRank](https://www.hackerrank.com/challenges/qheap1/problem)

file: Java [Qheap1.java](Qheap1.java)

Comment on Discussion forum:
> just a swim() function and boom no more time outs! :D

Solution using PriorityQueue of java.util library

```java
        Scanner sc = new Scanner(System.in);
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        int Q = sc.nextInt(); // the number of queries
        int queryType = 0;
        int element = 0;
        while(Q-->0) {
            queryType = sc.nextInt();
            switch(queryType){
                case 1:
                    element = sc.nextInt();
                    minHeap.add(element);
                    break;
                case 2:
                    element = sc.nextInt();
                    minHeap.remove(element);
                    break;
                case 3:
                    System.out.println(minHeap.peek());
            }
}
```

#### Jesse And Cookies

Problem on [HackerRank](https://www.hackerrank.com/challenges/jesse-and-cookies/problem)

file: Java [JesseAndCookies.java](JesseAndCookies.java)