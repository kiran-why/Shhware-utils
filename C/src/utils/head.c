#include "errors.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

// xwrite: write bytes to stdout, or exit on failure
// data: bytes to write
// bytes_count: number of bytes in data
//
// Exit via die() if write fails
static void xwrite(const char *data, size_t bytes_count)
{
    if (bytes_count == 0) return;

    if (write(STDOUT_FILENO, data, bytes_count) < 0)
        die("write");
}



int main(int argc, const char *argv[])
{
    if (argc != 3)
        die (argc<3 ? "Not enough arguments" : "Too many arguments");


    int file_descriptor = open(argv[1], O_RDONLY);
    if (file_descriptor < 0) die("open");

    int max_lines = atoi(argv[2]);

    if (max_lines < 1) 
    { 
        close(file_descriptor);
        return 0;
    }

    char buffer[1024];
    ssize_t bytes_read;
    int lines_count = 0;

    while ((bytes_read = read(file_descriptor, buffer, sizeof(buffer))) > 0)
    {
        for (ssize_t i=0; i<bytes_read; i++)
        {
            xwrite(&buffer[i], 1);

            if (buffer[i] == '\n')
            {
                lines_count++;

                if (lines_count == max_lines) 
                {    
                    close(file_descriptor); 
                    return 0;
   }     }   }  }
    
    
    if (bytes_read<0) die("read");
    close(file_descriptor);
    return 0;
}
