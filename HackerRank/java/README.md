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

### Java Output Formatting

file: [OutputFormat.java](/OutputFormat.java)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/java-output-formatting/problem "OutputFormat@HR")

Formatting Numeric Print Output Java [tutorial](https://docs.oracle.com/javase/tutorial/java/data/numberformat.html)

used in the solution: 

`printf("%-15s", "Hello")`  -----> "Hello__________" _left justified, minimum 15 characters_

`printf("%03d", 12)` -----> "012" _three characters in width, with leading zeroes as necessary_

`printf` [cheatsheet](https://alvinalexander.com/programming/printf-format-cheat-sheet)

### Java End-of-file

file: [EndOfFile.java](/EndOfFile.java)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/java-end-of-file/problem "EndOfFile@HR")

### Java Currency Formatter

file: [CurrencyFormatter.java](/CurrencyFormatter.java)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/java-currency-formatter/problem "CurrencyFormatter@HR")

### Java Date And Time

file: [DateAndTime.java](/DateAndTime.java)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/java-date-and-time/problem "DateAndTime@HR")

Java [Calendar](https://docs.oracle.com/javase/7/docs/api/java/util/Calendar.html) class SE7

### Java Date And Time

file: [StringTokens.java](/StringTokens.java)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/java-string-tokens/problem "StringTokens@HR")

Java [String](https://docs.oracle.com/javase/8/docs/api/java/lang/String.html) class SE8

### Valid Username Regular Expression

Problem description on [HackerRank](https://www.hackerrank.com/challenges/valid-username-checker/problem "StringRegEx@HR")

_requirements:_ string 8 - 30 characters long (inclusive), has to start with alphabetic, rest alphanumeric 

_solution:_ `"^[a-zA-Z]\\w{7,29}$"`

[String.matches()](https://docs.oracle.com/javase/8/docs/api/java/lang/String.html#matches-java.lang.String-) used to check if string matches regular expression

