#include "errors.h"

#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


// possible flags
typedef struct struct_opts {
    int parent_dir; // -p
} type_opts;


// parse_flags: parses command-line arguments into the options structure
// argc: number of arguments
// argv: array of argument strings
// opts: pointer to the options structure to be filled
//
// Exits via die() if an unknown flag is provided
static void parse_flags(int argc, char **argv, type_opts *opts)
{
    int opt;

    while ((opt = getopt(argc, argv, "p")) != -1)
    {
        switch (opt)
        {
            case 'p':
                opts -> parent_dir = 1;
                break;

            default: die("Usage: cell [-p] [dest]");
        }
    }
}


// just_cell: creates a single directory
// path: the directory path to create
//
// Exits via die() on other failures (e.g., permission denied)
static void just_cell(const char *path)
{
      if (mkdir(path, 0755) < 0) die(path);
}


// flagged_cell: creates a directory and its parents (-p flag logic)
// path: the directory path to create (modifiable copy)
// opts: pointer to the options structure
//
// Exits via die() on failure
static void flagged_cell(char *path, const type_opts *opts)
{
    if (opts -> parent_dir)     // -p flag logic
    {
        char *cur_pos = path;   // pointer to iterate through the path string
        
        while (*cur_pos != '\0')
        {
            if (*cur_pos == '/' && cur_pos != path)     // if found not root /, then we found parent
            {   
                *cur_pos ='\0';                         // temporarily replace / with \0 to isolate parent path
                just_cell(path);
                *cur_pos = '/';                         // restore slash to continue scanning rest of the path
            }
            
            cur_pos++;
        }

        just_cell(path);    // create last dir in the path
    }
} 




int main(int argc, char *argv[])
{
    type_opts opts = {0};
    parse_flags(argc, argv, &opts);

    if (optind >= argc) die("Missing file argument");

    for (int i = optind; i < argc; i++)
    {
        if (opts.parent_dir == 1)
        {   // strdup creates a copy of the string cuz flagged_cell modifies it
            char *path_copy = strdup(argv[i]);      
            flagged_cell(path_copy, &opts);
            free(path_copy);    // free allocated memory to prevent memory leaks
        }
        else
            just_cell(argv[i]);
    }                 

    return 0;
}
