# Collatz Conjecture

Welcome to Collatz Conjecture on Exercism's Python Track.
If you need help running the tests or submitting your code, check out `HELP.md`.

## Introduction

One evening, you stumbled upon an old notebook filled with cryptic scribbles, as though someone had been obsessively chasing an idea.
On one page, a single question stood out: **Can every number find its way to 1?**
It was tied to something called the **Collatz Conjecture**, a puzzle that has baffled thinkers for decades.

The rules were deceptively simple.
Pick any positive integer.

- If it's even, divide it by 2.
- If it's odd, multiply it by 3 and add 1.

Then, repeat these steps with the result, continuing indefinitely.

Curious, you picked number 12 to test and began the journey:

12 ➜ 6 ➜ 3 ➜ 10 ➜ 5 ➜ 16 ➜ 8 ➜ 4 ➜ 2 ➜ 1

Counting from the second number (6), it took 9 steps to reach 1, and each time the rules repeated, the number kept changing.
At first, the sequence seemed unpredictable — jumping up, down, and all over.
Yet, the conjecture claims that no matter the starting number, we'll always end at 1.

It was fascinating, but also puzzling.
Why does this always seem to work?
Could there be a number where the process breaks down, looping forever or escaping into infinity?
The notebook suggested solving this could reveal something profound — and with it, fame, [fortune][collatz-prize], and a place in history awaits whoever could unlock its secrets.

[collatz-prize]: https://mathprize.net/posts/collatz-conjecture/

## Instructions

Given a positive integer, return the number of steps it takes to reach 1 according to the rules of the Collatz Conjecture.

## Exception messages

Sometimes it is necessary to [raise an exception](https://docs.python.org/3/tutorial/errors.html#raising-exceptions). When you do this, you should always include a **meaningful error message** to indicate what the source of the error is. This makes your code more readable and helps significantly with debugging. For situations where you know that the error source will be a certain type, you can choose to raise one of the [built in error types](https://docs.python.org/3/library/exceptions.html#base-classes), but should still include a meaningful message.

The Collatz Conjecture is only concerned with **strictly positive integers**, so this exercise expects you to use the [raise statement](https://docs.python.org/3/reference/simple_stmts.html#the-raise-statement) and "throw" a `ValueError` in your solution if the given value is zero or a negative integer. The tests will only pass if you both `raise` the `exception` and include a message with it.

To raise a `ValueError` with a message, write the message as an argument to the `exception` type:

```python
# example when argument is zero or a negative integer
raise ValueError("Only positive integers are allowed")
```

## Source

### Created by

- @zwaltman

### Contributed to by

- @BethanyG
- @cmccandless
- @Dog
- @ikhadykin
- @K4cePhoenix
- @N-Parsons
- @smt923
- @Stigjb
- @thomasjpfan
- @tqa236

### Based on

Wikipedia - https://en.wikipedia.org/wiki/Collatz_conjecture