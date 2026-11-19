#include "errors.h"
#include <stdio.h>

int main(int argc, const char *argv[])
{
    if (argc != 3)
        die(argc<3 ? "Not enough arguments" : "Too many arguments");

    if (rename(argv[1],argv[2]) < 0)
        die("rename");

    return 0;
}
