#include "errors.h"
#include <unistd.h>



int main(int argc, char *argv[])
{
    if (argc<2) die("Shh...: Not enough arguments");

    for (int i=1; i<argc; i++)
        if (unlink(argv[i]) < 0) die("unlink");

    return 0;
}
