#include <stdio.h>
#include <ctype.h>

int main(){
    char words[20][30];
    int i=0;

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if(input != NULL && output != NULL){
        
        while (fscanf(input, "%s", &words[i]) == 1){
            words[i][0] = toupper(words[i][0]);
            i++;
        }

        for(int j = 0; j < i; j++){
            fprintf(output, "%s ", words[j]);
        }
    }

    fclose(input);
    fclose(output);    

    return 0;
}