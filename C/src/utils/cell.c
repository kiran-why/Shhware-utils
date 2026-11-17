#include "errors.h"
#include <sys/stat.h>


int main(int argc, char *argv[])
{
    if (argc<2) die("Shh...: Not enough arguments");

    for (int i = 1; i<argc; i++)
        if (mkdir(argv[i], 0755 ) < 0) die("mkdir");

    return 0;
}
