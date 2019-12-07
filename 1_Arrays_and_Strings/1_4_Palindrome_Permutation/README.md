# Examples

## Provided

* "Tact coa" -> True ("taco cat", "atco cta", etc.)

## Mine

* "AaBb" -> True ("abba", "baab")
* "a" -> True ("a")
* "" -> True ("")
* "A a3b_B" -> True ("abba", "baab"). I just went ahead and ignored non-alphabets.

# Clarifications

* Case-insensitive? Assume yes.
* Just alphabets? Assume yes.

# Attempts

## Really bad first pass

Generate all permutations of the input string. `O(N!)`.

Check if any of the permutations is a palindrome. `O(N)`.

Total run time: `O(N*N!)`.

Nice.

## Better: Counts array

A palindrome has reflective symmetry, which means all except for at most one character must occur an even number of times.

So we can step through all the characters, keeping a count of each character, in an array whose length equals the size of the alphabet.

Then we can step through the alphabet array and see that all except for possibly one have an even number of counts.

Run time: `O(N)` for stepping through chars, `O(1)` for stepping through alphas. So `O(N)`. Or `O(N + c)` if alphabet size is variable `c`.

Space complexity: `O(1)` for char counts array. Or `O(c)` if alphabet size is variable `c`.

## Better: Bool array

We don't actually need to keep the count above, just whether all but possibly one of the counts are even.

So we can just use a bool array, and toggle the bools each time we encounter a char.

Then just make sure we have all falses(/trues) or just one true(/false).

Run time: same as above.

Space complexity: same as above.

## Better: Bit vector (or bitset in cpp)

We don't actually need a bool array, we can just use a primitive integer with sufficient space to represent each letter in our alphabet uniquely.

Then we just toggle bits as we encounter chars using XOR.

Then we just check that all bits are 0 or just one bit is 1.

Again I think that

Run time: same as above.

Space complexity: same as above, but we don't even need another data structure.

