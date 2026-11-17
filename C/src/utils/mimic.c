#include "errors.h"
#include <unistd.h>
#include <fcntl.h>

// xwrite: write bytes to dest file, or exit on failure
// data: bytes to write
// bytes_count: number of bytes in data
//
// Exit via die() if the write fails
static void xwrite(int dest, const char *data, size_t bytes_count)
{
    if (bytes_count == 0) return;

    if (write(dest, data, bytes_count) < 0)
        die("write");
}

int main(int argc, const char *argv[])
{
    if (argc != 3)
        die(argc<3 ? "Not enough arguments" : "Too many arguments");

    int file_src = open(argv[1], O_RDONLY);
    if (file_src < 0) die("open");

    int file_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file_dest < 0) die("open");
    
    char buffer[1024];
    while (1)
    {
        ssize_t bytes_read = read(file_src, buffer, sizeof(buffer));
        if (bytes_read < 0) die("read");
        if (bytes_read == 0) break;

        xwrite(file_dest, buffer, bytes_read);
    }
    
    close(file_src);
    close(file_dest);
        
    return 0;
}
