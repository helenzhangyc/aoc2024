# aoc2024
Advent of Code 2024

#### Day 1
**Topics:** Hashmap

**Difficulty:** 1/10

For part 2, store the frequencies in a frequency map for efficiency

#### Day 2
**Topics:** Array

**Difficulty:** 2/10

I did brute force removal for part 2, maybe there's a better way to check for tolerance

#### Day 3
**Topics:** Regex

**Difficulty:** 7/10

I did not have a lot of experience with regex so I spent a long time figuring out the regex expression and how to find match. \
For part 2, don't enable at the start of each line. Debugged this for a while...

**Takeaways**:
- `std::sregex_iterator` iterates through all matches in the input regex
- `std::smatch` stores the results of a regex match
- The matched parts can be accessed using array-like indexing. A capturing group is defined using `()` in a regex pattern. Each set of parentheses creates a group that captures the part of the string matched by that section of the pattern. For instance, in `R"(mul\((\d+),(\d+)\))"` with the input string `mul(123,456)`, `match[0]` would be the entire string `mul(123,456)`, `match[1]` would be `123` and `match[2]` would be `456`. Note that `\(` and `\)` are literal parentheses, not capturing group.

#### Day 4
**Topics:** 2D Array

**Difficulty:** 3/10

Just search for every possibility. For some reason I think part 2 is easier than part 1

#### Day 5
**Topics:** Topological Sort, Kahn's Algorithm

**Difficulty:** Part 1: 2/10, Part 2: 6/10

Store the updates in a hashmap where the key is a number and value is a list of numbers that should appear after it. \
For part 1, iterate through each list of page numbers, for each number `num`, check if there's any number prior to it that is in `hashmap[num]`. If so, the page number list is invalid. Otherwise, the page number list is valid and we can add the middle number to the sum. \
Runtime is $O(\frac{n^2}{2} \times m)$, where $n$ is the length of the page number list and $m$ is the length of `hashmap[num]`, for each `num` in the page number list. Assume each `hashmap[num]` have the same length here for simplicity. \
Not sure if there's a more efficient solution but the brute force solution is pretty easy so I rated it as a 2/10. \
For part 2, we need to re-order the page numbers if the order is incorrect. Given only the relative orders between pages, we need to do a topological sort for each incorrect page number list. \
Runtime is $O(n + E)$ using Kahn's Algorithm, where $n$ is the length of the page number list (vertices) and $E$ is the number of edges. \
This part requires more knowledge in algorithm so I gave it a 6/10.

#### Day 6
**Topics:** Graph

**Difficulty:** Part 1: 3/10, Part 2: 5/10

Part 1 is easy, just simulate the guard and mark all the visited positions as X until the guard exits the map. Count number of X in the graph at the end.

For part 2, we need to notice that the guard is entering a loop if and only if it visits the same location with the same direction. By figuring out this, we just need to store the guard's state as a combination of position and orientation in a hashmap and check if this state has already been encountered by the guard before everytime the guard makes a move.

#### Day 7
**Topics:** Backtracking

**Difficulty:** 6/10

Just perform backtracking on all possible combinations. At first I thought it's evaluating using the human way (* first, and then +), so I just used javascript `eval()`, that wasted some time until I realized you are supposed to evaluating from left to right

#### Day 8
**Topics:** 2D Array

**Difficulty:** 4/10

Easy day, got confused by the antinode coordinate calculation for a sec

#### Day 9
**Topics:** Simulation

**Difficulty:** Part 1: 4/10, Part 2: 7/10

For Part 1, simulate the process by making . as -1 and move the file blocks. At first, did the same thing for part 2 but then it becomes very annoying to simulate and debug. Got inspired by https://github.com/mquig42/AdventOfCode2024/blob/main/src/day09.cpp and finished the question, so I will give it a 7/10.

#### Day 10
**Topics:** BFS

**Difficulty:** 3/10

Standard and simple BFS

#### Day 11
**Topics:** Simulation

**Difficulty:** Part 1: 2/10, Part 2: 5/10

Part 1 is easy, just follow the question instruction and do the simulation. \
For part 2, following the same way as part 1 would take forever to run. We need to realize that the position of stone does not matter. Therefore, we can store stones in a hashmap where keys are the stone, and values are the frequencies of the stone.

#### Day 12
**Topics:** BFS

**Difficulty:** Part 1: 5/10

Need to realize that for each cell, it contributes to `4 - (# of adjacent cells that has the same type as the current cell)` in the perimeter.