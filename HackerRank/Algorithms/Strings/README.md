* [CamelCase](#camelcase)
* [Two Characters](#two-characters)
* [The Love Letter Mystery](#the-love-letter-mystery)

### CamelCase

[Description](https://www.hackerrank.com/challenges/camelcase/problem)

[ASCII table](http://www.asciitable.com/)

Java solution
```java
static int camelcase(String s) {
    int num = 1;
    for(int i=0; i<s.length(); i++){
        int cur = (int)s.charAt(i);
        if(cur >= 65 && cur <= 95){
            num++;
        }
    }
    return num;
}
```

### Two Characters

[Description](https://www.hackerrank.com/challenges/two-characters/problem)

file: Java [TwoCharacters.java](TwoCharacters.java)

_note:_ there are probably easier (less complex solutions)

### The Love Letter Mystery

[Description](https://www.hackerrank.com/challenges/the-love-letter-mystery/problem)

file: Java [LoveLetterMystery.java](LoveLetterMystery.java)