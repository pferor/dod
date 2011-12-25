#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>  /* crypt */

#include "crypt.h"


/* Compares encrypted key 'key' with dictionaries in 'dictionary_path'
 * words */
bool
compare(const char *key,
        const char *salt,
        const char dictionary_path[],
        bool verbose)
{
    FILE *fp;
    char *word;            /* dictionary entry */
    char *encrypted_word;  /* encrypted dictionary entry */
    char *variant;

    word = (char *) malloc(sizeof(char) * 40);
    encrypted_word = (char *) malloc(sizeof(char) * 25);
    variant = (char *) malloc(sizeof(char) * 40);

    fp = fopen(dictionary_path, "r+t");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open \"%s\"\n", dictionary_path);
        return true;
    }

    if (verbose) {
        fprintf(stdout, "Searching in %s...\n", dictionary_path);
    }

    while (!feof(fp)) {
        fscanf(fp, "%s\n", word);
        if (verbose) {
            fprintf(stdout, "%s\n", word);
        }
        encrypted_word = (char *) crypt(word, salt);

        if (strcmp(encrypted_word, key) == 0) {
            fprintf(stdout, "%s\n", word);
            fclose(fp);
            return false;
        }
    }

    return true;
}

