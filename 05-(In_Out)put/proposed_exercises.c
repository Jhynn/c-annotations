#include <stdio.h>
#include <stdlib.h>


// Exercise: Count the number of words, characters and lines in a file.

int
main() {
    FILE* file;
    char path[128];

    char ch;
    // Is a auxiliar that will assume all the characters of the text file.
    int characters, words, lines; // Counters...

    printf("Enter text file path: ");
    scanf("%s", path);

    // Open file in read mode.
    file = fopen(path, "r");

    // Check if file was opened successfully.
    if (file == NULL) {
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read privilege.\n");

        exit(EXIT_FAILURE);
    }

    characters = words = lines = 0;

    while ((ch = fgetc(file)) != EOF) {
        characters++;

        // Count lines.
        if (ch == '\n' || ch == '\0')
            lines++;

        // Probable word breakers.
        if ((ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0'))
            words++;
        // The next character is missing to check.
    }

    printf("Informations...\n");
    printf("Characters: %d\n", characters);
    printf("Words.....: %d\n", words);
    printf("Lines.....: %d\n", lines);

    // Always close the file.
    fclose(file);

    return 0;
}
