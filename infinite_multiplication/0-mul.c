#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char ch;

    // Open the file in read mode
    file = fopen("launch_0-mul.sh", "r");

    // Check if file was successfully opened
    if (file == NULL) {
        printf("Error: Could not open file launch_0-mul.sh\n");
        return 1;
    }

    // Read and print each character from the file
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    // Close the file
    fclose(file);

    return 0;
}
