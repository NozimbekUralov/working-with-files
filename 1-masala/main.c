#include <stdio.h>

int main() {
    FILE *file = fopen("input.txt", "r");

    FILE *output = fopen("output.txt", "w");

    int number;
    int sum = 0, i = 0;

    while (fscanf(file, "%d", &number) == 1) {
        i++;
        sum += number;
    }

    fprintf(output, "%.2f", (float)sum/i);

    fclose(output);
    fclose(file);
    return 0;
}