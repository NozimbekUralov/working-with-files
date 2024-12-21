#include <stdio.h>

int main(){
    int nums[20];
    int i = 0;

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    while (fscanf(input, "%d", &nums[i]) == 1){
        i++;
    }

    fprintf(output, "%d %d", nums[0], nums[i-1]);

    return 0;
}