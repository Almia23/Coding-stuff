#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 50
#define MAX_CHARS 80
#define MAX_WORD_LEN 80

int main() {
    char filename[] = "testing.rtf";
    FILE *fp;
    char line[MAX_CHARS];
    char *words[MAX_LINES * MAX_CHARS];
    int num_lines = 0;
    int num_words = 0;
    int num_four_letter_words = 0;

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", filename);
        exit(1);
    }

    // Read each line and split into words
    while (fgets(line, MAX_CHARS, fp) != NULL && num_lines < MAX_LINES) {
        char *word = strtok(line, " ,.\n");
        while (word != NULL) {
            words[num_words++] = word;
            if (strlen(word) == 4) {
                num_four_letter_words++;
            }
            word = strtok(NULL, " ,.\n");
        }
        num_lines++;
    }

    // Close the file
    fclose(fp);

    // Display the number of words and four-letter words
    printf("Number of words: %d\n", num_words);
    printf("Number of four-letter words: %d\n", num_four_letter_words);

    return 0;
}