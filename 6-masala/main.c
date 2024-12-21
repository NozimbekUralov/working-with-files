#include <stdio.h>
#include <stdlib.h>


int main(){
    char words[20][20];
    int i = 0;

    FILE *uz = fopen("uz.txt", "r");
    FILE *en = fopen("en.txt", "r");
    FILE *output = fopen("output.txt", "w");


    if(uz != NULL && en != NULL){
        while(fscanf(uz, "%s", words[i]) == 1 && fscanf(en, "%s", words[i+1]) == 1){
            fprintf(output, "%s - %s\n", words[i], words[i+1]);
            i++;
        }
    }
    fclose(output);
    fclose(en);
    fclose(uz);

    return 0;
}