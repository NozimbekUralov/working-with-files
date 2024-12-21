#include <stdio.h>
#include <stdlib.h>

int* n = NULL;

int main(){
    int i = 0;
    int sum = 0;

    n = malloc(sizeof(int));
    FILE *output = fopen("output.txt", "w");
    FILE *file = fopen("input.txt", "r");

    while(fscanf(file, "%d", &n[i]) == 1){ 
        sum += n[i];       
        i++;
        n = realloc(n, (i +1) * sizeof(int));
    }
    fclose(file);

    for(int j = 0; j < i; j++) {
        fprintf(output, "%d", n[j]);

        if(j != i-1) fprintf(output, "+");
        else fprintf(output, "=");
    }
    fprintf(output, "%d\n", sum);
    fclose(output);

    return 0;
}