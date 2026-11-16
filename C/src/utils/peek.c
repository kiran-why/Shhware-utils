#include <fcntl.h>
#include <unistd.h>
#include <errors.h>

int main(int argc, char* argv[])
{   
    if (argc<2)
    {
        die("Shh...");
    }

    int file_descriptor = open(argv[1], O_RDONLY);
    
    if (file_descriptor<0)
        {
            die("Shh...");
        }
    
    char buffer[1024];
    ssize_t bytes_read;


    while (1)
    {
        bytes_read = read(file_descriptor, buffer, sizeof(buffer));

        if (bytes_read == -1)
        {
            die("Shh...");
        }
    

        if (bytes_read == 0)
        {
            break;
        }
        
        write(STDOUT_FILENO, buffer, bytes_read);
    }
  
    close(file_descriptor);

    return 0;
}

