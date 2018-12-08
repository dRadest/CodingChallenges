# Solutions
- Easy
	* [A Chessboard Game](#a-chessboard-game)
	- [Game of Stones](#game-of-stones)
	- [Tower Breaker](#tower-breaker)
	- [Introduction to Nim Game](#introduction-to-nim-game)
	- [Misere Nim](#misere-nim)
* Medium

The Economics Detective

* [Intro to Game Theory and Dominant Strategy Equilibrium](https://www.youtube.com/watch?v=3Y1WpytiHKE)
* [Nash Equilibrium](https://www.youtube.com/watch?annotation_id=annotation_471559&feature=iv&src_vid=3Y1WpytiHKE&v=5o6MFTJGwuc)

Khan Academy

* [Prisoner's Dillema and Nash Equilibrium](https://www.youtube.com/watch?v=UkXI-zPcDIM)
* [More on Nash Equilibrium](https://www.youtube.com/watch?v=ewu_7Dmj_18)

[Introduction to Game Theory](http://home.ku.edu.tr/~lkockesen/teaching/econ333/lectnotes/uggame.pdf) KU, NYU

[gametheory101.com](http://gametheory101.com/)

Game Theory [cmu notes](http://www.cs.cmu.edu/afs/cs/academic/class/15859-f01/www/notes/comb.pdf)


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

### Tower Breaker
[Description](https://www.hackerrank.com/challenges/tower-breakers-1/problem)

file: Java [TowerBreaker.java](TowerBreaker.java)

#####[GfG Game Theory Intro](https://www.geeksforgeeks.org/introduction-to-combinatorial-game-theory/)


### Introduction to Nim Game
[Description](https://www.hackerrank.com/challenges/nim-game-1/problem)

[GfG Nim Game](https://www.geeksforgeeks.org/combinatorial-game-theory-set-2-game-nim/)

>Nim-Sum : The cumulative XOR value of the number of coins/stones in each piles/heaps at any point of the game is called Nim-Sum at that point.

>“If both A and B play optimally (i.e- they don’t make any mistakes), then the player starting first is guaranteed to win if the Nim-Sum at the beginning of the game is non-zero. Otherwise, if the Nim-Sum evaluates to zero, then player A will lose definitely.”

[proof](https://en.wikipedia.org/wiki/Nim#Proof_of_the_winning_formula)

file: Java [IntroToNimGame.java](IntroToNimGame.java)

### Misere Nim
[Description](https://www.hackerrank.com/challenges/misere-nim-1/problem)

>Misère Nim is exactly like the standard Nim game, except for one critical difference. If the size of every pile is , then we need to treat it as a special case where we count the number of piles. If the count is even, then the first player will win; if the count is odd, then the first player will lose.

file: Java [MisereNim.java](MisereNim.java)
