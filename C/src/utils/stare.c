#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errors.h>
#include <stdio.h>
#include <dirent.h>

int main (int argc, char *argv[])
{
    if (argc>2) die("Shh...: Too many arguments");

    const char *path;
    path = (argc == 2) ? argv[1] : ".";
    
    DIR *cur_dir = opendir(path);

    if (cur_dir == NULL) die(path);

    struct dirent *entry;

    
    while ((entry = readdir(cur_dir)) != NULL)
    {
        if (entry -> d_name[0] == '.')  continue;

        write(STDOUT_FILENO, entry -> d_name, strlen(entry -> d_name));
        write(STDOUT_FILENO, "\n", 1);
    }
    
    closedir(cur_dir);
    return 0;
}
