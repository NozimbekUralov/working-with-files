#include <stdio.h>

int main(){
    int n = 5;
    int sum = 0;

    FILE *output = fopen("output.txt", "w");

    for(int i = 1; i <= n; i++){
        sum+=i;

        fprintf(output, "%d", i);

        if(n != i) fprintf(output, "+");
        else fprintf(output, "=%d", sum);
    }

    fclose(output);

    return 0;
}