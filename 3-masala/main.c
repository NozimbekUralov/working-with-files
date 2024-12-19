#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char word[30];
}Word;

Word* words = NULL;
int word_count = 0;

int main() {
    int l;
    words = malloc(sizeof(Word));

    printf("son kiriting: "); scanf("%d", &l);

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    while(fscanf(input, "%s", words[word_count].word) == 1) {
        
        if(word_count +1 != l) fprintf(output, "%s\n", words[word_count].word);
       
        word_count++;
        words = realloc(words, (word_count + 1) * sizeof(Word));
    }

    fclose(output);
    fclose(input);
    free(words);
    return 0;
}