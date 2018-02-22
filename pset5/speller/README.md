# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

An invented long word said to mean a lung disease caused by inhaling very fine ash and sand dust.
source: https://en.oxforddictionaries.com/definition/pneumonoultramicroscopicsilicovolcanoconiosis

## According to its man page, what does `getrusage` do?

It returns the resource usage of the calling process (in our case, load, check, etc.)
http://man7.org/linux/man-pages/man2/getrusage.2.html

## Per that same man page, how many members are in a variable of type `struct rusage`?

There are 16 variables in the struct rusage:

 struct rusage {
               struct timeval ru_utime; /* user CPU time used */
               struct timeval ru_stime; /* system CPU time used */
               long   ru_maxrss;        /* maximum resident set size */
               long   ru_ixrss;         /* integral shared memory size */
               long   ru_idrss;         /* integral unshared data size */
               long   ru_isrss;         /* integral unshared stack size */
               long   ru_minflt;        /* page reclaims (soft page faults) */
               long   ru_majflt;        /* page faults (hard page faults) */
               long   ru_nswap;         /* swaps */
               long   ru_inblock;       /* block input operations */
               long   ru_oublock;       /* block output operations */
               long   ru_msgsnd;        /* IPC messages sent */
               long   ru_msgrcv;        /* IPC messages received */
               long   ru_nsignals;      /* signals received */
               long   ru_nvcsw;         /* voluntary context switches */
               long   ru_nivcsw;        /* involuntary context switches */
           };
http://man7.org/linux/man-pages/man2/getrusage.2.html


## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

As we can see in the definition of calculate, the function needs to check whether a and b is NULL first before performing calculations.
Using references enables the program to do that.
I suspect that it also saves memory as both a and b are referred multiple times in calculate.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

'Main' starts by checking the number of commandline arguments and whether the file opens, until line 71, then it starts to read the file.
Line 71 reads the file character by character until the end of the file and checks whether the character it reads is alphabetical characters or apostrophes.
If yes, it will get the whole word by using index++ in the loop, write an end to the word, add word count by 1, check if the word is misspelled, and add 1 to misspelled if yes.
If the character is digit or the lengh of the "word" it reads is more than 45, it will proceed to the next word.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

fgetc returns a single character. By checking what character it reads, we can tell whether we're dealing with a word, a number, or something else.
fscanf only returns one certain format of string by specifying string type, i.e. "%s". We can use fscanf while loading dictionary because we're confident that
all words in the dictionary file are char, whereas we're not that certain with the txt input.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

The reason why we want to declare them as const is because that we want to "reserve" a place for them in the memory so that they can be changed but not moved later.
Since we'll need to refer to the returned value in other programs (i.e. speller.c), it avoids unnecessary errors.
Source: http://duramecho.com/ComputerInformation/WhyHowCppConst.html

