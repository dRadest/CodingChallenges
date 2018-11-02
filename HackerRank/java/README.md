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

# Solutions

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

### Java String Tokens

file: [StringTokens.java](/StringTokens.java)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/java-string-tokens/problem "StringTokens@HR")

Java [String](https://docs.oracle.com/javase/8/docs/api/java/lang/String.html) class SE8

### Valid Username Regular Expression

Problem description on [HackerRank](https://www.hackerrank.com/challenges/valid-username-checker/problem "StringRegEx@HR")

_requirements:_ string 8 - 30 characters long (inclusive), has to start with alphabetic, rest alphanumeric 

_solution:_ `"^[a-zA-Z]\\w{7,29}$"`

[String.matches()](https://docs.oracle.com/javase/8/docs/api/java/lang/String.html#matches-java.lang.String-) used to check if string matches regular expression

### Pattern Syntax Checker

file: [PatternSyntaxChecker.java](/PatternSyntaxChecker.java)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/pattern-syntax-checker/problem "PatternSyntaxChecker@HR")

[Pattern.compile()](https://docs.oracle.com/javase/7/docs/api/java/util/regex/Pattern.html#compile(java.lang.String)) SE7

### Java Primality Test

Problem description on [HackerRank](https://www.hackerrank.com/challenges/java-primality-test/problem "PrimalityTest@HR")

_Solution:_
```java
String n = scanner.nextLine();
// convert the String to BigInteger using constructor (TODO: handle exceptions)
BigInteger bign = new BigInteger(n);
// certainty = 1
System.out.println((bign.isProbablePrime(1) ? "prime" : "not prime"));
scanner.close();
```

`BigInteger.isProbablePrime()`:
[Oracle docs](https://docs.oracle.com/javase/7/docs/api/java/math/BigInteger.html#isProbablePrime%28int%29) and
[TutorialsPoint article](https://www.tutorialspoint.com/java/math/biginteger_isprobableprime.htm) 

### Java Generics

file: [Generics.java](/Generics.java)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/java-generics/problem "Generics@HR")

Generic methods Oracle [tutorial](https://docs.oracle.com/javase/tutorial/extra/generics/methods.html)

Java Generics TutorialsPoint [article](https://www.tutorialspoint.com/java/java_generics.htm)

### Java Abstract Class

file: [AbstractClass.java](/AbstractClass.java)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/java-abstract-class/problem "AbstractClass@HR")

Abstract Classes and Methods ORacle [tutorial](https://docs.oracle.com/javase/tutorial/java/IandI/abstract.html)

Java Abstraction TutorialsPoint [article](https://www.tutorialspoint.com/java/java_abstraction.htm)

### Java Interface

file: [Interface.java](/Interface.java)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/java-interface/problem "Interface@HR")

_Explanation:_ class without a modifier (keyword) is _package private_ (Controling Access to Members of a Class Oracle [tutorial](https://docs.oracle.com/javase/tutorial/java/javaOO/accesscontrol.html)) and all methods of an interface are _public_ (Abstract Classes Compared to Interfaces [tutorial](https://docs.oracle.com/javase/tutorial/java/IandI/abstract.html) and Interfaces [tutorial](https://docs.oracle.com/javase/tutorial/java/IandI/createinterface.html) on docs.oracle.com) that's why method divisor_sum() in MyCalculator class has to be declared public to avoid assigning weaker access priviliges

### Java Varargs - Simple Addition

file: [Varargs.java](/Varargs.java)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/simple-addition-varargs/problem "Varargs@HR")

### Java Reflection Attributes

Problem description on [HackerRank](https://www.hackerrank.com/challenges/java-reflection-attributes/problem "Reflection@HR")

Discovering Class Members Oracle [tutorial](https://docs.oracle.com/javase/tutorial/reflect/class/classMembers.html)

_Solution:_
```java
try{
	// get the class associated with "Student"
    Class student = Class.forName("Student");
    // get all the declared methods in Student class
    Method[] methods = student.getDeclaredMethods();

    // traverse through each method 
    ArrayList<String> methodList = new ArrayList<>();
    for(Method method : methods){
    	// add its name to the method list
        methodList.add(method.getName());
    }
    // sort the method list in ascending order (default)
    Collections.sort(methodList);
    // print each method name on a new line
    for(String name: methodList){
        System.out.println(name);
    }
}catch(Exception e){}
```

Documentation for [Class](https://docs.oracle.com/javase/8/docs/api/java/lang/Class.html) and [Method](https://docs.oracle.com/javase/8/docs/api/java/lang/reflect/Method.html) SE8

### Java Factory Pattern

file: [FactoryPattern.java](/FactoryPattern.java)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/java-factory/problem "FactoryPattern@HR")

TutorialsPoint [article](https://www.tutorialspoint.com/design_pattern/factory_pattern.htm) on Factory Pattern

### Java Singleton Pattern

_Solution:_
```java
class Singleton{
    public String str;
    private Singleton(){}
    private static final Singleton instance = new Singleton();
    public static Singleton getSingleInstance(){
        return instance;
    }
}
```
Problem description on [HackerRank](https://www.hackerrank.com/challenges/java-singleton/problem "SingletonPattern@HR")

JournalDev [article](https://www.journaldev.com/1377/java-singleton-design-pattern-best-practices-examples) on Singleton Pattern

### Java Covariant Return Types

file: [CovariantReturnTypes.java](/CovariantReturnTypes.java)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/java-covariance/problem "CovariantReturnTypes@HR")

_Oracle docs:_

* [Returning a Value From a Method](https://docs.oracle.com/javase/tutorial/java/javaOO/returnvalue.html)

* [Overriding and Hiding Methods](https://docs.oracle.com/javase/tutorial/java/IandI/override.html)

* [Covariant Return Types](https://blogs.oracle.com/sundararajan/covariant-return-types-in-java) (blogpost)

### Java Regex

Problem description on [HackerRank](https://www.hackerrank.com/challenges/java-regex/problem "Regex@HR")

Write regular expression to validate IP address:

>IP address is a string in the form "A.B.C.D", where the value of A, B, C, and D may range from 0 to 255. Leading zeros are allowed. The length of A, B, C, or D can't be greater than 3.

_Solution:_
`"((\\d{1,2}|(0|1)\\d{2}|2[0-4]\\d|25[0-5])\\.){3}(\\d{1,2}|(0|1)\\d{2}|2[0-4]\\d|25[0-5])"`

_Explanation:_

`\\d{1,2}` catches any one or two digit numbers

`(0|1)\\d{2}` catches any three digit number starting with 0 or 1

`2[0-4]\\d` catches numbers between 200 and 249

`25[0-5]` catches numbers between 250 and 255


