#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char word[30];
}Word;

Word* words = NULL;
int word_count = 0;

int main() {
    char *min, *max;

    words = malloc(sizeof(Word));

    FILE *file = fopen("input.txt", "r");

    FILE *output = fopen("output.txt", "w");

    min = max = words[word_count].word;

    while (fscanf(file, "%s", words[word_count].word) == 1) {
        
        if (strlen(words[word_count].word) < strlen(min)) {
            min = words[word_count].word;
        }
        
        if (strlen(words[word_count].word) > strlen(max)) {
            max = words[word_count].word;
        }
        
        word_count++;

        words = realloc(words, (word_count + 1) * sizeof(Word));

    }

    fprintf(output, "Eng qisqa so'z: %s\nEng uzun so'z: %s\n", min, max);

    fclose(output);
    fclose(file);
    free(words);
    return 0;
}