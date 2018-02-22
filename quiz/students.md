# Comparing Students

## Questions

1.1. It is the comparison function that qsort uses to compare. It returns a negative integer value if the first argument is less than the second,
a positive integer value if the first argument is greater than the second and zero if the arguments are equal.

1.2. In theory, void* can be any data type. But in the example, function compare_ints declares arg1 and arg2 to be integers and therefore allocates
them the corresponding space in memory. If a and b are not integers here (say long), it may result in segmentation fault due to insufficient memory.

1.3. See `students.c`. DONE

1.4. See `students.py`.DONE

1.5. See `students.js`. DONE

## Debrief

a. Class notes (week4 and week9)
   https://stackoverflow.com/questions/6105513/need-help-using-qsort-with-an-array-of-structs

b. 40 Minutes
