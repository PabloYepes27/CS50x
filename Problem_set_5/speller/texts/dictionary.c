// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
// array of struct node's
node *table[N];
// total of words
int word_counter = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *tmp = table[hash(word)];;

    if (table[hash(word)])
    {
        while (tmp)
        {
            if (strcasecmp(tmp->word, word) == 0)
            {
                return true;
            }
            tmp = tmp->next;
        }
    }
    return false;
}

// Hashes word to a number it returns and index of the array
// one bucket for each first letter of the word
unsigned int hash(const char *word)
{
    if (word[0] >= 65 && word[0] <= 90)
    {
        return ((word[0] - 65));
    }
    return ((word[0] - 97));
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // open the dictionary
    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
        return false;
    }

    // create and initialize a temporary space to hold the words
    char *dict_word = malloc(LENGTH);
    if (!dict_word)
    {
        return false;
    }

    // read every word of the dicitionary(file)
    while (fscanf(file, "%s", dict_word) != EOF)
    {
        // create a new node
        node *n = malloc(sizeof(node));
        if (!n)
        {
            return false;
        }

        // copy each word into each node
        strcpy(n->word, dict_word);

        // put each node at the beginning of the list on his respective index of the array
        n->next =  table[hash(dict_word)];

        // set each index of the array points to the first element of the linked list
        table[hash(dict_word)] = n;

        // count the amount of words in the dictionary that hasn't fail
        word_counter++;
    }
    fclose(file);
    free(dict_word);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *tmp, *killer;

    for (int i = 0; i < N; i++)
    {
        tmp = table[i];
        while (tmp)
        {
            killer = tmp;
            tmp = tmp->next;
            free(killer);
        }
    }
    return true;
}
