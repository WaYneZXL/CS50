// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"


#define hashsize 65536


// define struct node
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// create a hashtable with hashsize number of nodes
node *hashtable[hashsize];

// size of dictionary starts as zero
int dictsize = 0;


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char checkword[LENGTH + 1];
    int n = strlen(word);

    // When I didn't have this line of code, it return more than 10000 misspelled words and most of them includes some capital letters
    // Then I realized that my hash function returns different hashvalues for upper or lower case letters

    for (int i = 0 ; i < n; i++)
    {
        checkword[i] = tolower(word[i]);
    }

    // Signifies the end of a word
    checkword[n] = '\0';


    // get the hash value of the input word
    int hashvalue = hash(checkword);

    // iterate through the hashtable and search for the input word
    for (node *ptr = hashtable[hashvalue]; ptr != NULL; ptr = ptr->next)
    {
        //return true if the word is found
        if (strcasecmp(ptr -> word, checkword) == 0)
        {
            return true;
        }
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    int hashvalue;
    char newword[LENGTH + 1];

    // open the dictionary file
    FILE* dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    // scan dictionary word by word
    while (fscanf(dict, "%s", newword) == 1)
    {
        // get the hash value of that word
        hashvalue = hash(newword);

        // assign memory for new node
        node *new = malloc(sizeof(node));
        if (!new)
        {
            return false;
        }

        //copy new word to the node we just created
        strcpy(new -> word, newword);
        new -> next = NULL;

        // if the node in hashtable is empty, put new node in it
        if (hashtable[hashvalue] == NULL)
        {
            hashtable[hashvalue] = new;
        }
        else
        {
            // if not empty, append the new node to the end of hashtable
            for (node *ptr = hashtable[hashvalue]; ptr != NULL; ptr = ptr->next)
            {
                if (!ptr -> next)
                {
                    ptr->next = new;
                    break;
                }

            }
        }
        // size of the dictionary increases by 1
        dictsize++;
    }
    fclose(dict);
    return true;
}


// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (dictsize != 0)
    {
        return dictsize;
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Iterate through hash table, with hashsize is the maximum number
    for (int i = 0; i < hashsize; i++)
    {
        // create another pointer to point at the first node of the linked list
        node* cursor = hashtable[i];
        while(cursor != NULL)
        {
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}

// Source: http://www.partow.net/programming/hashfunctions/#AvailableHashFunctions

int hash(const char* str)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(str); i < n; i++)
        hash = (hash << 2) ^ str[i];
    return hash % hashsize;
}