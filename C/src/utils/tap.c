#include "errors.h"
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
    if (argc<2) die("Shh...: Not enough arguments");
    
    for (int i = 1; i<argc; i++)
    {
        int file_descriptor = open(argv[i], O_CREAT | O_WRONLY, 0644);

        if (file_descriptor<0) die("open");

        close(file_descriptor);
    }
    
    return 0;
}
