```

         █▄        █▄                                                           ▄█▀ ▄▀▀▄  ▄█▀
         █▓▌       █▓▌                                                         ▐▓█▄▄▌■▀▐▌▐▓█
   ▄▄██▄▐▓▓█░▄▓▄  ▐▓▓█░▄▓▄  ▀░▄▄            ▄██▄   ▀░▄▄     ▄▄█▄▄       ▄▓     ▀▓▓▌ ▀■▓▀ ▐▓▓▌       ▄▄██▄
  ▓▓  ▀▀▐▒▒ ▀ ▀██ ▐▒▒ ▀ ▀██  ▐▒▌        ▓▓▌▀  ▀█▌   ▓▓▌▄▄  ▓█▀ ▀▓▓     ▓▓▀   ▓ ▐▒▒   ▄▄▓▀▐▒▒       ▓▓  ▀▀
   ▀▀▀▄  ░░▌   ▐▓▌ ░░▌   ▐▓▌ ▐░░ ░▀█▄▄ ▐▒▒  ▄▄█▓█  ▐▒▒▀▄▓█▐▒▌  ▄▒▀    ▐▒▌   ▐▓▌ ░░▌  ▐▓▓  ░░▌       ▀▀▀▄
▐█▌  ░█░ ██▓  ▄██  ██▓  ▄██   ██▄  ▓▒▌ ░░▌ ██▀ ▀▓▌ ░░▌ ▀░▀ ▀░░▀       ▐░░▄ ▄▒▒  ▐██   ▒▒▌ ▐██   ▄▐█▌  ░█░
 █░▄██▀  ▐█▌  █▀   ▐█▌  █▀     ░██▄░█░▄██  ▓█▄▄▒▒ ▀██       ▀█▄  ▄     ▀█░█░▀    █░▀ ▐░░   █░█▄█▀ █░▄██▀
  ▀▀░     ▀    ▀    ▀    ▀       ▀▀ ░▀▀     ▀▀▀▀     ▀         ▀▀         ▀     ▀    ██▀    ▀▀▀    ▀▀░
                                                                                     ▀▄

```
<div align="center"><h2> Overview </h2></div>

Shhware-utils is a learning project and an attempt to create an alternative to GNU coreutils. After exploring the complex GNU source code, i wanted to build something simplier for my own. The goal is to implement common Unix utilities,
keeping code simple, readable and simple as possible.

**Note** The project is still in its early stages. These utilities are currently quite basic and missing many of flags.

## Utilities

Here is the current list of tools available in Shhware-utils (with their GNU coreutils equivalents):

*   **`peek`** (*cat*) - Reads a file and prints its contents to standard output.
*   **`whisper`** (*echo*) - Prints the provided arguments to standard output.
*   **`cell`** (*mkdir*) - Creates directories.
*   **`erase`** (*rm*) - Removes (unlinks) files.
*   **`dose`** (*head*) - Outputs the first N lines of a file.
*   **`stare`** (*ls*) - Lists the contents of a directory.
*   **`tap`** (*touch*) - Creates empty files or updates their timestamps.
*   **`where`** (*pwd*) - Prints the current working directory.
*   **`mimic`** (*cp*) - Copies a file from source to destination.
*   **`shift`** (*mv*) - Moves or renames files and directories.
