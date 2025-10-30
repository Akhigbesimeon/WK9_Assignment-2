#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_STUDENTS 10
#define SHRINKED_STUDENTS 6
#define MAX_EMAIL_LENGTH 100

int main() {
    char **emails;
    int i;

    // Allocate memory for 10 students
    emails = (char **)malloc(INITIAL_STUDENTS * sizeof(char *));
    if (emails == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter emails of %d students:\n", INITIAL_STUDENTS);
    for (i = 0; i < INITIAL_STUDENTS; i++) {
        emails[i] = (char *)malloc(MAX_EMAIL_LENGTH * sizeof(char));
        if (emails[i] == NULL) {
            printf("Memory allocation failed for email %d.\n", i + 1);
            return 1;
        }

        printf("Email %d: ", i + 1);
        scanf("%s", emails[i]);
    }

    printf("\nStored Email Addresses:\n");
    for (i = 0; i < INITIAL_STUDENTS; i++) {
        printf("%s\n", emails[i]);
    }

    // Shrink memory to store only 6 students
    emails = (char **)realloc(emails, SHRINKED_STUDENTS * sizeof(char *));
    if (emails == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    printf("\nShrinked to %d students:\n", SHRINKED_STUDENTS);
    for (i = 0; i < SHRINKED_STUDENTS; i++) {
        printf("%s\n", emails[i]);
    }

    // Free allocated memory
    for (i = 0; i < SHRINKED_STUDENTS; i++) {
        free(emails[i]);
    }
    free(emails);

    return 0;
}
