#include <stdio.h>
#include <stdlib.h>
#include <errors.h>

void die(const char *message)
{
    perror(message);
    exit(1);
}

