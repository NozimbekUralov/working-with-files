#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[20];
    int score;
} Student;

Student* students = NULL;


int main(){
    char data[10][20];
    char *token;
    int i = 0;

    FILE *input = fopen("input.txt", "r");
    FILE *pass = fopen("pass.txt", "w");
    FILE *fail = fopen("fail.txt", "w");


    while (fgets(data[i], sizeof(data), input)) {
        i++;
    }

    students = malloc(sizeof(Student) * i);

    for(int j = 0; j < i; j++){

        token = strtok(data[j], ":");
        
        strcpy(students[j].name, token);

        token = strtok(NULL, ":");
        students[j].score = atoi(token);
    }


    for(int f = 0; f < i; f++){
        if(students[f].score >= 60) fprintf(pass, "%s : %d\n", students[f].name, students[f].score);
        else fprintf(fail, "%s : %d\n", students[f].name, students[f].score);
    }

        

    fclose(input);
    fclose(fail);
    fclose(pass);
    free(students);

    return 0;
}