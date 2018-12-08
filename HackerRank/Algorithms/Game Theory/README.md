# Solutions
- Easy
	* [A Chessboard Game](#a-chessboard-game)
	- [Game of Stones](#game-of-stones)
	- [Tower Breaker](#tower-breaker)
	- [Introduction to Nim Game](#introduction-to-nim-game)
	- [Misere Nim](#misere-nim)
	- [Nimble Game](#nimble-game)
	- [Poker Nim](#poker-nim)
* Medium
	- [Zero Move Nim](#zero-move-nim)
	- [Alice And Bob's Silly Game](#alice-and-bobs-silly-game)

The Economics Detective

* [Intro to Game Theory and Dominant Strategy Equilibrium](https://www.youtube.com/watch?v=3Y1WpytiHKE)
* [Nash Equilibrium](https://www.youtube.com/watch?annotation_id=annotation_471559&feature=iv&src_vid=3Y1WpytiHKE&v=5o6MFTJGwuc)

Khan Academy

* [Prisoner's Dillema and Nash Equilibrium](https://www.youtube.com/watch?v=UkXI-zPcDIM)
* [More on Nash Equilibrium](https://www.youtube.com/watch?v=ewu_7Dmj_18)

[Introduction to Game Theory](http://home.ku.edu.tr/~lkockesen/teaching/econ333/lectnotes/uggame.pdf) KU, NYU

[gametheory101.com](http://gametheory101.com/)

Game Theory [cmu notes](http://www.cs.cmu.edu/afs/cs/academic/class/15859-f01/www/notes/comb.pdf)

GeeksforGeeks [Grundy numbers](https://www.geeksforgeeks.org/combinatorial-game-theory-set-3-grundy-numbersnimbers-and-mex/) and [Sprague-Grundy Theorem](https://www.geeksforgeeks.org/combinatorial-game-theory-set-4-sprague-grundy-theorem/)

Wikipedia [Sprague-Grundy Theorem](https://en.wikipedia.org/wiki/Sprague%E2%80%93Grundy_theorem)


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

>Misère Nim is exactly like the standard Nim game, except for one critical difference. If the size of every pile is _1_, then we need to treat it as a special case where we count the number of piles. If the count is even, then the first player will win; if the count is odd, then the first player will lose.

file: Java [MisereNim.java](MisereNim.java)

### Nimble Game
[Description](https://www.hackerrank.com/challenges/nimble-game-1/problem)

>This is a variation on the standard Nim game. If a coin is located at the _i-th_ square, it can go to squares at index _0_ to _i-1_. So there are possibilities _i_ for every coin in each square. So, you can think of it just as you would think of a pile of _i_ stones. Moving a coin to the left is just like taking a stone from a stone pile.

>After you reduce the game to standard Nim, you can find the XOR sum to solve the game. Notice that square _i_ has _ci_ stones of size _i_. So we can just take one instance of size pile _i_ if _ci_ is odd, as XOR sum of even number of identical elements is zero. So, no matter how large the value of _ci_ is, you can easily find the XOR sum by checking if _ci_ is even or odd.

file: Java [NimbleGame.java](NimbleGame.java)

### Poker Nim
[Description](https://www.hackerrank.com/challenges/poker-nim-1/problem)

>This problem is identical to standard nim game. If the current player is in winning position and the opponent adds some chips, the current player can remove those chips in his move and remain in winning position. As the current player can mirror his opponent's "add" move all the time, that move has no value. 

file: Java [Pokernim.java](PokerNim.java)

### Zero Move Nim
[Description](https://www.hackerrank.com/challenges/zero-move-nim/problem)

GeeksforGeeks [Variaton in Nim](https://www.geeksforgeeks.org/variation-nim-game/)

file: Java [ZeroMoveNim.java](ZeroMoveNim.java)

### Alice And Bob's Silly Game
[Description](https://www.hackerrank.com/challenges/alice-and-bobs-silly-game/problem)

file: Java [AliceAndBobSillyGame.java](AliceAndBobSillyGame.java)
