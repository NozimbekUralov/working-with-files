#include <stdio.h>
#include <string.h>


int main(){
    char str[50];
    char simbols[] ="+-*/()";
    int count = 0;

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if(input != NULL && output != NULL){
        
        fgets(str, sizeof(str), input);

        for(int i = 0; i < strlen(simbols); i++){
            for(int j = 0; j < strlen(str); j++){
                if(str[j] == simbols[i]) count++;
            }
            if(i < strlen(simbols) -2) fprintf(output, "%c %d ta\n",simbols[i], count);
            else if(i == strlen(simbols) -2) fprintf(output, "() %d ta", count);
            count = 0;      
        } 
    }

    fclose(input);
    fclose(output);   

    return 0;
}