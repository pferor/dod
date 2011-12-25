#include <stdio.h>
#include <stdlib.h>

#include "usage.h"


/* Display version on 'stream' and exits with 'exit_code' code */
void
show_version(FILE * stream, int exit_code, char *arg0)
{
    fprintf(stream, "(%s) %s version %s\n", arg0, LONGNAME, VERSION);

    exit(exit_code);
}


/* Shows usage on 'stream' and exits with 'exit_code' code */
void
show_usage(FILE * stream, int exit_code, char *arg0)
{
    fprintf(stream, " %s v%s\n", LONGNAME, VERSION);
    fprintf(stream, " Usage: %s [options] -d <dict> DES_string\n", arg0);
    fprintf(stream,
        "  -d <dict>  --dictionary <dic>  Uses <dict> dictionary\n");
    fprintf(stream,
        "  -h         --help              Shows this help and exits\n");
    fprintf(stream,
        "  -V         --version           Display version and exits\n");
    fprintf(stream,
        "  -v         --verbose           Verbose mode on\n");
    fprintf(stream,
        "\n  If the string is not decrypted you should add more dictionaries\n");

    exit(exit_code);
}

