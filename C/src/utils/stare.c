#include "errors.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

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



int main (int argc, char *argv[])
{
    if (argc>2) die("Shh...: Too many arguments");

    const char *path;
    path = (argc == 2) ? argv[1] : ".";
    

    DIR *dir = opendir(path);
    if (dir == NULL) die(path);

    
    struct dirent *entry;
    while (1)
    {
        entry = readdir(dir);
        
        if (entry == NULL) break;

        if (entry -> d_name[0] == '.')  continue;

        xwrite(entry -> d_name, strlen(entry -> d_name));
        xwrite("\n", 1);
    }
 
    closedir(dir);
    return 0;
}
