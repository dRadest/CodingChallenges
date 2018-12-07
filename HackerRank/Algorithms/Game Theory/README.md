# Solutions
- Easy
	* [A Chessboard Game](#a-chessboard-game)
	- [Game of Stones](#game-of-stones)
* Medium

The Economics Detective

* [Intro to Game Theory and Dominant Strategy Equilibrium](https://www.youtube.com/watch?v=3Y1WpytiHKE)
* [Nash Equilibrium](https://www.youtube.com/watch?annotation_id=annotation_471559&feature=iv&src_vid=3Y1WpytiHKE&v=5o6MFTJGwuc)

Khan Academy

* [Prisoner's Dillema and Nash Equilibrium](https://www.youtube.com/watch?v=UkXI-zPcDIM)
* [More on Nash Equilibrium](https://www.youtube.com/watch?v=ewu_7Dmj_18)

[Introduction to Game Theory](http://home.ku.edu.tr/~lkockesen/teaching/econ333/lectnotes/uggame.pdf) KU, NYU

[gametheory101.com](http://gametheory101.com/)

### A Chessboard Game
[Directions](https://www.hackerrank.com/challenges/a-chessboard-game-1/problem)

file: Java [Chessboard.java](Chessboard.java) w/ a trick

### Game of Stones
[Description](https://www.hackerrank.com/challenges/game-of-stones-1/problem)

_Solution_

because of reaccuring pattern this simple trick works
```java
static String gameOfStones(int n) {
    if(n%7 > 1){
        return "First";
    }
    return "Second";
}
```
file: Java [GameOfStones.java](GameOfStones.java)
