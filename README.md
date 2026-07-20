# Longest Balanced Parentheses

Problem: given a string made up of only `(` and `)`, find the length of the
longest substring that is properly balanced.

## How it works

I went with a counter based solution instead of a stack. It makes two passes over
the string and only uses a couple of integer counters, so it runs in linear time
and constant space.

First pass goes left to right. I keep a count of open and close brackets. Every
time the two counts match, whatever we have seen so far is balanced, so I update
the answer with `2 * count`. If the close count ever goes above the open count,
that substring is dead, so I reset both counters back to zero.

The catch is that a string like `(()` never lets the counts meet again from the
left, so the first pass alone would miss it. To handle that I run the same logic a
second time from right to left, this time resetting when the open count gets
ahead. Between the two passes we cover every case, and the answer is just the
largest length either pass found.

A stack based approach also solves this, but I preferred the counters here since
it keeps the extra space at O(1).

## Complexity

- Time: O(n), since the string is scanned twice and each pass is linear.
- Space: O(1), since only a few integer counters are used, no stack or arrays.

## A few examples

```
"(()"     -> 2      the "()" in the middle
")()())"  -> 4      the "()()" run
""        -> 0
```

## Running it

```bash
g++ -std=c++17 -O2 -o solution longest_valid_parentheses.cpp
./solution
```
