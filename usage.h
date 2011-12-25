#ifndef USAGE_H
#define USAGE_H

/* Application info */
#define VERSION     "1.0"
#define LONGNAME    "DES O'Dict"


/**
 * @brief Display version on 'stream' and exits with 'exit_code' code
 *
 * @param stream    Where to display the version
 * @param exit_code Exit code
 * @param *arg0     Application name, usually argv[0]
 */
void show_version(FILE * stream, int exit_code, char *arg0);

/**
 * @brief Shows usage on 'stream' and exits with 'exit_code' code
 *
 * @param stream    Where to display this help
 * @param exit_code Exit code
 * @param *arg0     Application name, usually argv[0]
 */
void show_usage(FILE * stream, int exit_code, char *arg0);


#endif /* ! USAGE_H */

