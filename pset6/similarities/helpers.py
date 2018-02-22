from nltk.tokenize import sent_tokenize
from nltk.tokenize import word_tokenize

def lines(a, b):
    """Return lines in both a and b"""
    list1 = a.splitlines()
    list2 = b.splitlines()

    commonlist = []

    for lines in list1:
        if lines in list2:
            commonlist.append(lines)

    uniquelist = list(set(commonlist))

    return [uniquelist]


def sentences(a, b):
    """Return sentences in both a and b"""
    list1 = sent_tokenize(a)
    list2 = sent_tokenize(b)

    commonlist = []

    for lines in list1:
        if lines in list2:
            commonlist.append(lines)

    uniquelist = list(set(commonlist))

    return [uniquelist]


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    # use word_tokenize to break down the strings into words
    list1 = word_tokenize(a)
    list2 = word_tokenize(b)

    # create 2 lists that contains only alphabetic words
    wordlist1 = []
    wordlist2 = []

    # create 2 lists that contains all substrings
    substringlist1 = []
    substringlist2 = []

    # populate wordlist1 & 2 by going through list1 & 2 and check if the word is alphabetic
    for word in list1:
        if word.isalpha():
            wordlist1.append(word)

    # go thru the wordlist1 and create list for substrings
    for word in wordlist1:

        # if the word length is smaller than n, then put the whole word into our substring list
        if len(word) <= n:
            substringlist1.append(word)

        # if not, iterate thru the list and get x number of substrings
        else:
            x = len(word) - n + 1
            for i in range(x):
                substringlist1.append(word[i:i+n])

    for word in list2:
        if word.isalpha():
            wordlist2.append(word)

    for word in wordlist2:
        if len(word) <= n:
            substringlist2.append(word)
        else:
            x = len(word) - n + 1
            for i in range(x):
                substringlist2.append(word[i:i+n])

    # create a common list
    commonlist = []

    # iterate through the substringlist1 to find similarities
    for i in len(substringlist1):
        if substringlist1[i] in substringlist2:
            commonlist.append(substringlist1[i])

    # eliminate duplicates
    uniquelist = list(set(commonlist))

    return [uniquelist]
