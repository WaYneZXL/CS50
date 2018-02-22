# #functions

## Questions

1. Beause this hash function returns only 26 (0 to 25) hashvalues and there are potentially a lot of collisions.

2. It is perfect in the sense that each string will have its unique hash values and there are no collisions. It is imperfect for C because once the string gets longer,
the hash function will return a very large integer. Large integers makes calculation slower (in case we need to calculate hash values), and large integers might result in
buffer overflow if it is larger than the maximum value allowed by its data type.

3. It will be extremely time consuming if we want to compare one by one each picture with the original: it might involve comparisons of multiple parts of the picture file
 - like what we did with bmp files. Comparing the hash values, on the other hand, is more convenient and time efficient for the online checker.

4. For tries, looking up a word takes only O(1) because the program needs to go through a word once (from the first letter to the last letter) and it can tell whether the
word is correct or not. For hashtables, for each hash function value, we need to go through the whole hashtable to find that node and then compare whether two words are
the same. Therefore, it takes O(n) for hashtables to find a word.

## Debrief

1. NA

2. 20 min
