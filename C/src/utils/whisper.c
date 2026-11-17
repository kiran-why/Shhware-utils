#include "errors.h"
#include <unistd.h>
#include <string.h>


// xwrite: write bytes to stdout, or exit on failure
// data: bytes to write
// bytes_count: number of bytes in data
//
// Exits via die() if the write fails
static void xwrite(const char *data, size_t bytes_count)
{
    if (bytes_count == 0) return;

    if (write(STDOUT_FILENO, data, bytes_count) < 0) die ("write");
}



int main(int argc, char* argv[])
{   
    for (int i=1; i<argc; i++)
    {
        xwrite(argv[i], strlen(argv[i]));
        xwrite(" ",1);
    }
    
    xwrite("\n", 1);

    return 0;

}
