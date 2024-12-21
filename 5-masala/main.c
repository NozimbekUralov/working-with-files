#include <stdio.h>
#include <stdlib.h>

int* n = NULL;

int main(){
    int i=0;
    
    n = malloc(sizeof(int));

    FILE *input = fopen("input.txt", "r");
    FILE *odd = fopen("odd.txt", "w");
    FILE *even = fopen("even.txt", "w");

    while(fscanf(input, "%d", &n[i]) == 1){
        i++;
        n = realloc(n, (i+1) * sizeof(int));
    }
    fclose(input);

    for(int j = 0; j < i; j++){
        if(n[j] % 2 == 0) fprintf(even, "%d ", n[j]);
        else fprintf(odd, "%d ", n[j]);
    }

    fclose(odd);
    fclose(even);
    return 0;
}