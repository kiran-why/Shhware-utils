#include "errors.h"
#include <string.h>
#include <unistd.h>

// xwrite: write bytes to stdout, or exit on failure
// data: bytes to write
// bytes_cout: number of bytes in data
//
// Exit via die() if write fails
static void xwrite(const char *data, size_t bytes_count)
{
    if (bytes_count == 0) return;

    if (write(STDOUT_FILENO, data, bytes_count) < 0)
        die("write");
}



int main(void)
{
    char buffer[1024];

    if (getcwd(buffer, sizeof(buffer)) == NULL) 
        die("getcwd");
    
    xwrite(buffer, strlen(buffer));
    xwrite("\n", 1);

    return 0;
}
