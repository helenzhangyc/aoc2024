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

Takeaways:
- `std::sregex_iterator` iterates through all matches in the input regex
- `std::smatch` stores the results of a regex match
- The matched parts can be accessed using array-like indexing. A capturing group is defined using `()` in a regex pattern. Each set of parentheses creates a group that captures the part of the string matched by that section of the pattern. For instance, in `R"(mul\((\d+),(\d+)\))"` with the input string `mul(123,456)`, `match[0]` would be the entire string `mul(123,456)`, `match[1]` would be `123` and `match[2]` would be `456`. Note that `\(` and `\)` are literal parentheses, not capturing group.