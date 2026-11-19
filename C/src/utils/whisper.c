#include "errors.h"

#include <unistd.h>
#include <string.h>
#include <stdio.h>

// possible flags
typedef struct struct_opts {
    int no_newline; //-n
} type_opts;


// parse_flags: parses comman-line arguments into options structure
// argc: number of arguments
// argv: array of argument strings
// opts: pointer to the option structure to be filled
//
// Exits via die() if an unknown flag is provided
static void parse_flags(int argc, char **argv, type_opts *opts)
{
    int opt;
    
    while ((opt = getopt(argc, argv, "n")) > 0)
    {
        switch (opt)
        {
            case 'n':
                opts -> no_newline = 1;
                break;

            case '?':

            default: die("Usage: whisper [-n] [string...]");
        }
    }
}



// xwrite: write bytes to stdout, or exit on failure
// data: bytes to write
// bytes_count: number of bytes in data
//
// Exits via die() if the write fails
static void xwrite(const char *data, size_t bytes_count)
{
    if (bytes_count == 0) return;

    if (write(STDOUT_FILENO, data, bytes_count) < 0) 
        die ("write");
}



// just_whisper: outputs strings separated by spaces with new line
// args: array of strings to print
// num_args: number of stings in the array
//
// Used when no forrmating flags are provided. Exits via die() on write error
static void just_whisper(char **args, int num_args)
{
    for (int i = 0; i < num_args; i++)
    {
        xwrite(args[i], strlen(args[i]));

        if (i < num_args - 1)
            xwrite(" ", 1);
    }
    
    xwrite("\n", 1);
}



// flagged_whisper: outputs strings, respecting flags
// args: array of strings to print
// num_args: number of strings in the array
// opts: pointer to the options structure containig active flags
//
// Exits via die() on write error
static void flagged_whisper(char **args, int num_args, const type_opts * opts)
{
    for (int i = 0; i < num_args; i++)
    {
        xwrite(args[i], strlen(args[i]));
        if (i < num_args - 1) 
            xwrite(" ", 1);
    }

    if (opts -> no_newline)     // -n flag logic
        return;

    xwrite("\n", 1);
}



int main(int argc, char* argv[])
{   
    type_opts opts = {0};
    parse_flags(argc, argv, &opts);    
    char **args = argv + optind;        // points to first non-flag argument
    int num_args = argc - optind;       // count_of remaining strings after flag parsing

    if (opts.no_newline == 1)
        flagged_whisper(args, num_args, &opts);
    
    else
        just_whisper(args, num_args);

    return 0;

}
