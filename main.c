/* Decrypts argument through crypt function (DES-based) using
 * a dictionary.
 *
 * Usage:
 * $ dod [options] -d <dictionary> DES_encrypted_string
 *
 * Example:
 * $ dod -v --dictionary="mydictionary.dic" ZX9XTlIfPvdGE
 *
 *
 * This software is under GPL license v3
 * PFeror, 2008  < pferor [AT] gmail [DOT] com >
 */

#include <stdio.h>   /* fprintf */
#include <stdlib.h>  /* malloc */
#include <string.h>  /* strncat */
#include <getopt.h>  /* getopt */
#include <stdbool.h> /* bool */

#include "usage.h"
#include "crypt.h"



/* Main entry */
int
main(int argc, char *argv[])
{
    char *dictionary = NULL;
    char *salt = NULL;
    bool verbose = false;
    int next_option;
    const char *const short_options = "hVn:Dd:v";
    const struct option long_options[] = {
        {"help",       0, NULL, 'h'},
        {"version",    0, NULL, 'V'},
        {"dictionary", 1, NULL, 'd'},
        {"verbose",    0, NULL, 'v'},
        { NULL,        0, NULL,  0 }    /* required at end of array */
    };

    /* Get options */
    do {
        next_option =
            getopt_long(argc, argv, short_options, long_options, NULL);

        switch (next_option) {
            case 'h':   /* -h or --help */
                show_usage(stdout, 0, argv[0]);
                break;

            case 'V':   /* -V or --version */
                show_version(stdout, 0, argv[0]);
                break;

            case 'd':   /* -d or --dictionary */
                dictionary = (char *) malloc(sizeof(char) *
                                       strlen(optarg));
                dictionary = optarg;
                break;

            case 'v':   /* -v or --verbose */
                verbose = true;
                break;

            case -1:    /* done with options */
                break;

            default:
                show_usage(stdout, 1, argv[0]);
        }
    }
    while (next_option != -1);

    /* Validate */
    if (dictionary == NULL) {
        show_usage(stdout, 1, argv[0]);
    }

    /* Search in dictionaries or exit */
    if (optind != argc) {
        salt = (char *) malloc(sizeof(char) * 2);
        strncat(salt, argv[optind], 2);

        if (compare(argv[optind], salt, dictionary, verbose) ==
           false) {
            return false;
        }

        if (verbose) {
            fprintf(stdout, "Word not found :-(\n");
        }

        return true;
    } else {
        show_usage(stdout, 1, argv[0]);
    }
}

