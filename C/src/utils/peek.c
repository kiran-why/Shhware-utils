#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <core/errors.h>

int main(int argc, char* argv[])
{
    //used to open file
    int file_descriptor = open(argv[1], O_RDONLY);
    if (file_descriptor<0)
        {
            err(argv[1]);
        }
    
    //amount of bytes to read
    char buffer[1024];
    
    //used to read file
    ssize_t bytes_read = read(file_descriptor, buffer, 1024);
    if (bytes_read == -1)
        {
            err("read");
        }


    //used to print what is inside a file
    write(STDOUT_FILENO, buffer, bytes_read);
    
    //used to close file
    close(file_descriptor);

    return 0;
}

