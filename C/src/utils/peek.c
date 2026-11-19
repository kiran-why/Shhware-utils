#include "errors.h"

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


// possible flags
typedef struct struct_opts {
    int numbered_lines; // -n
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

    while ((opt = getopt(argc,argv, "n")) > 0)
    {     
        switch (opt)
        {
            case 'n':
                opts -> numbered_lines = 1;
                break;

            case '?':

            default: die("Usage: peek [-n] [file]");
        } 
    }                                           
}



// xwrite: writes bytes to a file descriptor, exits on failure
// data: pointer to the bytes to write
// bytes_count: number of bytes to write
//
// Exits via die() if the write fails
static void xwrite(const char *data, size_t bytes_count)
{
    if (bytes_count == 0) return;
    
    if (write(STDOUT_FILENO, data, bytes_count) < 0)
        die("write");
}


// just_peek: outputs file contents directly without any formatting
// fd: file descriptor of the file to read
//
// Used when no formatting flags are provided. Exits via die() on read/write error
static void just_peek(int fd)
{
    char buffer[4096];
    ssize_t bytes_read;

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
    {
        xwrite(buffer, bytes_read);
    }

    if (bytes_read < 0) die("read");
}



// flagged_peek: reads a file and outputs it with formatting based on flags
// fd: file descriptor of the file to read
// opts: pointer to the options structure containing active flags
//
// Exits via die() on read/write error
static void flagged_peek(int fd, const type_opts *opts)
{
    char buffer[1024];
    ssize_t bytes_read;
    int line_num = 1;
    int at_line_start = 1;

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
    {
        if (opts->numbered_lines)   // -n flag logic
         {
            for (ssize_t i = 0; i < bytes_read; i++)
            {
                char cur_char = buffer[i];                           
                char line_buffer[32];

                if (at_line_start)
                {
                    int len = sprintf(line_buffer, "%6d\t", line_num);
                    xwrite(line_buffer, len);
                    line_num++;
                }
                
                xwrite(&cur_char, 1);
                at_line_start = (cur_char == '\n');                        
            }
        }
    }

    if (bytes_read < 0) die("read");
}



int main(int argc, char *argv[])
{
    type_opts opts = {0};
    parse_flags(argc, argv, &opts);
    
    if (optind >= argc) die("Missing file argument");

    int file_descriptor = open(argv[optind], O_RDONLY);

    if (file_descriptor < 0) die("open");

    if (opts.numbered_lines == 1)
        flagged_peek(file_descriptor, &opts);

    else
        just_peek(file_descriptor);

    close(file_descriptor);
    return 0;
}
