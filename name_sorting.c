#include <stdio.h>
#include <string.h>

#define SIZE 20
#define MAX_LEN 100

// Function prototypes
int ascending(const char *a, const char *b);
int descending(const char *a, const char *b);
void bubbleSort(char arr[SIZE][MAX_LEN], int (*compare)(const char *, const char *));

int main() {
    char names[SIZE][MAX_LEN] = {
        "Aman Kasa", "Denaton Brunelle", "Olayinka Ajao", "Nkurikiyimana Aimable", "Emma Briggs",
        "Peter Nnamchukwu", "Tavonga Matikiti", "Paul Masamvu", "Precious Mozia", "Chinemerem Judith",
        "Thadee Gatera", "Blair Kayigamba", "Kelia Tesi", "Maxwel Okoth", "James Ngugi Giathi",
        "Jok John Kur", "Hephzibah Ofomi", "Adebayo Seyi", "Sharif Kiviri", "Erica Costa"
    };

    char order[10];
    printf("Enter 'asc' for ascending or 'desc' for descending order: ");
    scanf("%s", order);

    int (*compare)(const char *, const char *);

    if (strcmp(order, "asc") == 0) {
        compare = ascending;
    } else if (strcmp(order, "desc") == 0) {
        compare = descending;
    } else {
        printf("Invalid input. Defaulting to ascending order.\n");
        compare = ascending;
    }

    bubbleSort(names, compare);

    printf("\nSorted Names:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}

int ascending(const char *a, const char *b) {
    return strcmp(a, b) > 0;
}

int descending(const char *a, const char *b) {
    return strcmp(a, b) < 0;
}

void bubbleSort(char arr[SIZE][MAX_LEN], int (*compare)(const char *, const char *)) {
    char temp[MAX_LEN];
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (compare(arr[j], arr[j + 1])) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

