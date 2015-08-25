# game RACE-UP...

##Compiling and Running

Supposed that you have the gcc-c++ compiler installed

* Compile the game as follows :

```c++
g++ game.cpp -o game
```

* Make sure to set your ITEM files which defaults to :

```text
1 Brick -20
2 Lottery 80
3 Bed 10
4 Hammer -100
5 Donations 70
6 Water 0
```

Here the first parameter is dice count, second The name of item. Make sure item name is not space separated. Third is Impact value of that Item i.e. Whats the value change to the user score.

* Run thee game

```sh
./game
```

###various of the terms concerned to the game...

**Dice** :- It's imagined of as the actual dice available.
	Rolling the dice will give any random number between 1 to 6 and the player will have to accept the respected choice that would come-up

**Turn** :- At one turn each of the player will be given one chance to ROLL the DICE
	Further the player will be given another chance to ROLL the Dice if the number on the DICE would be 6
	Three 6 on dice in the row would nullify all the previous dice rolls and the turn will be rotated
	The turn will be rotated from player to player untill one of the player will emerge victorious

**Player Cookie** :- It's just the representative piece of each of the player on the game

**Objective of the Game** :- The primary objective of the game is to reach the score of 1000 by obtaining the points related to the objects that are obtained on the dice ROLLs

**Winning and Losing conditions** :- The player who first will be able to reach the score of 1000 points will be considered as the WINNER and so consequently other players will lose
	A player will be declared as OUT or LOST if his score will get to be less than 0
	If only one player will be left in the game and rest all other players get OUT then the last remaining player will be declared as a WINNER
