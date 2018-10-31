# Run Java in cmd / bash

_check if java installed_

`$java -version`

`$javac -version`

_cd into filename.java directory_

_compile_ 

`$javac filename.java`

_run_

`$java filename`

_example:_ HelloWorld.java

```java
	public class HelloWorld {

    	public static void main(String[] args) {
        	System.out.println("Hello World!");
    	}
	}
```

_compile:_ `javac HelloWorld.java`

_run:_ `java HelloWorld`

# Read input from _stdin_ / Write ouput to _stdout_

### Using [Scanner](https://docs.oracle.com/javase/8/docs/api/java/util/Scanner.html)

```java
Scanner scanner = new Scanner(System.in);
String myString = scanner.next();
int myInt = scanner.nextInt();
scanner.close();

System.out.println("myString is: " + myString);
System.out.println("myInt is: " + myInt);
```

### Using [BufferedReader](https://docs.oracle.com/javase/8/docs/api/java/io/BufferedReader.html)

```java
BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
String input = reader.readLine();
int a = Integer.parseInt(input);
reader.close();

System.out.println("input is: " + input);
System.out.println("a is: " + a);
```

### Java Stdin and Stdout I

file: [StdinOutOne.java](/StdinOutOne.java)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/java-stdin-and-stdout-1/problem "stdinoutone@HR")

### Java Stdin and Stdout I

file: [StdinOutTwo.java](/StdinOutTwo.java)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/java-stdin-stdout/problem "stdinouttwo@HR")