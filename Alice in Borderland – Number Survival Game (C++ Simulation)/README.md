# Alice in Borderland – Number Strategy Game (C++)

A C++ simulation inspired by the “King of Diamonds” game from Alice in Borderland. The program models a multi-player elimination game where survival depends on choosing numbers closest to a calculated target.

---

## Game Rules

* Each player selects a number between **1 and 100**

* The system calculates:

  **Target = 0.8 × (average of all chosen numbers)**

* The player(s) closest to the target:

  * Do not lose points

* All other players:

  * Lose 1 point

* Any player reaching **-10 points is eliminated**

* The game continues until **one player remains**

---

## How the Program Works

1. The user enters the number of players
2. Each round:

   * Players are assigned random numbers (1–100)
   * Total and average are calculated
   * Target value is computed
   * Difference between each player's number and target is measured
   * Scores are updated based on closeness
3. Players with score **-10 are removed**
4. The loop continues until one winner remains

---

## Code Structure

### Class: `Game`

Handles player data and shared game state.

**Attributes:**

* `num` → chosen number
* `score` → current score
* `player_number` → player ID

**Static Members:**

* `totalpoints` → sum of all player numbers
* `playercount` → active players
* `finalscore` → computed target value
* `relative_score[]` → stores distance from target

**Key Methods:**

* `num_input(int)` → assigns and displays number
* `calulation()` → computes target
* `changescore(int)` → updates score

---

## Compilation & Execution

### Compile

```bash
g++ game.cpp -o game
```

### Run

```bash
./game
```

---

## Example Output

```
Round 1 Begins

Player 1 choice is: 45
Player 2 choice is: 60
Player 3 choice is: 30

Final Score is: 36

Player 1 difference: 9
Player 2 difference: 24
Player 3 difference: 6

Round Results:
Player 1 Score: -1
Player 2 Score: -1
Player 3 Score: 0
```

---

## Limitations

* Uses random inputs instead of real user decisions
* Not a fully strategic simulation of the original game
* Uses non-standard variable-length arrays
* Player removal logic can be optimized

---

## Future Improvements

* Add real player input (interactive gameplay)
* Implement smarter AI strategies
* Replace arrays with `vector` for safety
* Improve elimination logic
* Add graphical interface

---

## Purpose

This project demonstrates:

* Object-Oriented Programming in C++
* Use of static variables
* Game loop and elimination logic
* Basic simulation design

## Author

Rachit
