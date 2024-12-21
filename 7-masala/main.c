#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char word[20];
}Words;

Words* words;

int main(){
    words = malloc(sizeof(Words));
    
    int i = 0;

    FILE *first = fopen("1.txt", "r");
    FILE *second = fopen("2.txt", "r");
    FILE *output = fopen("output.txt", "w");

    while(fscanf(first, "%s", &words[i].word) == 1){
        i++;
        words = realloc(words, (i+1) * sizeof(Words));
    }

    while (fscanf(second, "%s", &words[i].word) == 1){
        i++;
        words = realloc(words, (i+1) * sizeof(Words));
    }

    for(int j = 0; j < i; j++){
        fprintf(output, "%s\n", words[j].word);
    }

    fclose(first);
    fclose(second);
    fclose(output);

    free(words);

    return 0;
}