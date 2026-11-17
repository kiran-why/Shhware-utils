#include "errors.h"
#include <fcntl.h>
#include <unistd.h>

// xwrite: write bytes to stdout, or exit on failure
// data: bytes to write
// bytes_count: number of bytes in data
//
// Exit via die() if write fails
static void xwrite(const char *data, size_t bytes_count)
{
    if (bytes_count == 0) return;

    if (write(STDOUT_FILENO, data, bytes_count) < 0) 
        die ("write");
}



int main(int argc, char* argv[])
{   
    if (argc != 2)
        die(argc < 2 ? "missing file argument" : "too many arguments");


    int file_descriptor = open(argv[1], O_RDONLY);
    
    if (file_descriptor<0)  die("open");
   

    char buffer[1024];
    ssize_t bytes_read;


    while (1)
    {
        bytes_read = read(file_descriptor, buffer, sizeof(buffer));

        if (bytes_read == -1) die("read");

        if (bytes_read == 0) break;
        
        xwrite(buffer, bytes_read);
    }
  
    close(file_descriptor);

    return 0;
}

