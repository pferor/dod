#ifndef CRYPT_H
#define CRYPT_H

#include <stdbool.h>


/**
 * @brief compares encrypted key 'key' with dictionaries in
 *        'dictionary_path' words
 *
 * @param *key            Key to compare with
 * @param *salt           S
 * @param dictionary_path Path to dictionary
 * @param verbose         Display information
 *
 * @return true if the key was found, or false otherwise
 */
bool compare(const char *key,
             const char *salt,
             const char dictionary_path[],
             bool verbose);


#endif /* ! CRYPT_H */

