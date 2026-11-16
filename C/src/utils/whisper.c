#include <unistd.h>
#include <string.h>
#include <errors.h>

int main(int argc, char* argv[])
{   
    for (int i=1; i<argc; i++)
    {
        write(STDOUT_FILENO, argv[i], strlen(argv[i]));
        write(STDOUT_FILENO," " , 1); // space after every arguement   
    }
    
    // empty srting after cycle
    write(STDOUT_FILENO, "\n", strlen("\n"));

    return 0;

}
