#include <stdio.h>
#include <stdlib.h>

int* nums;

int main(){
    nums = malloc(sizeof(int));
    int i = 0;

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    while (fscanf(input, "%d", &nums[i]) == 1){
        fprintf(output, "%c", nums[i]);
        i++;
        nums = realloc(nums, (i+1) * sizeof(int));
    }
    printf("\n");

    fclose(input);
    fclose(output);
    free(nums);

    return 0;
}