#include <stdio.h>
#include <stdlib.h>
#include <errors.h>
#include <errno.h>
#include <string.h>


void die(const char *message)
{
    if (errno != 0)
        fprintf(stderr, "Shh...: %s\n", strerror(errno));
    
    else
        fprintf(stderr, "Shh...: %s\n", message);

    exit(EXIT_FAILURE);
}
