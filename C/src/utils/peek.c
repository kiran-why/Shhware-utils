#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errors.h>

int main(int argc, char* argv[])
{   
    // error if not enough args
    if (argc<2)
    {
        die("Not enough arguements");
    }
  
    // open files
    int file_descriptor = open(argv[1], O_RDONLY);
    
    // peek cannot open file
    if (file_descriptor<0)
        {
            die(argv[1]);
        }
    
    // amount of bytes to read
    char buffer[1024];
    ssize_t bytes_read;

    // reads file till end
    while (1)
    {
        bytes_read = read(file_descriptor, buffer, 1024);

        // error while reading
        if (bytes_read == -1)
        {
            die("read");
        }
        
        // signs end of file and stops the cycle
        if (bytes_read == 0)
        {
            break;
        }
        
        // prints what is inside a file
        write(STDOUT_FILENO, buffer, bytes_read);
    }
    
    // close file
    close(file_descriptor);

    return 0;
}

