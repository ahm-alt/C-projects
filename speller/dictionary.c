// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 456976;

// Hash table
node *table[N];

//size
int siz = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int s = strlen(word) + 1;
    char tm[s];// = malloc(sizeof(char) * s);
    for (int i = 0; i < s; i++)
    {
        tm[i] = tolower(word[i]);
    }
    //unsigned int key = hash(tm);
    //free(tm);
    node *tmp = table[hash(tm)];
    while (tmp != NULL)
    {
        if (strcasecmp(word, tmp->word) == 0)
        {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // from internet
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ word[i];
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dic = fopen(dictionary, "r");
    if (dic == NULL)
    {
        return 0;
    }
    //set to null
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    //hash table
    while (true)
    {
        node *n = malloc(sizeof(node));
        if (fscanf(dic, "%s", n->word) == EOF)
        {
            fclose(dic);
            free(n);
            break;
        }
        unsigned int k = hash(n->word);
        n->next = table[k];
        table[k] = n;
        siz++;
    }
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return siz;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        for (node *tmp = table[i]; tmp != NULL; tmp = table[i])
        {
            table[i] = table[i]->next;
            free(tmp);
        }
    }
    return true;
}

