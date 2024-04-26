#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100]; // Buffer to store file names
    FILE *filePointer;
    int choice;

    while (1) {
        printf("\nFile Explorer Menu:\n");
        printf("1. Create a new file\n");
        printf("2. Open an existing file\n");
        printf("3. Write to an existing file\n");
        printf("4. Read an existing file\n");
        printf("5. Delete an existing file\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the new file: ");
                scanf("%s", filename);
                filePointer = fopen(filename, "w"); // Create a new file
                if (filePointer == NULL) {
                    printf("Error creating the file.\n");
                } else {
                    printf("File created successfully.\n");
                    fclose(filePointer);
                }
                break;

            case 2:
                printf("Enter the name of the existing file: ");
                scanf("%s", filename);
                filePointer = fopen(filename, "r"); 
                if (filePointer == NULL) {
                    printf("File not found.\n");
                } else {
                    printf("File opened successfully.\n");
                    
                    fclose(filePointer);
                }
                break;
            
            case 3:
                printf("Enter the name of the existing file you would like to write to: ");
                scanf("%s", filename);
                filePointer = fopen(filename, "w"); 
                if (filePointer == NULL) {
                    printf("File not found.\n");
                } else {
                    printf("What would you like to write to the file.\n");
                    char text[1000];
                    scanf(" %[^\n]", text);
                    fprintf(filePointer, "%s", text);
                    fclose(filePointer);
                }

                break;
            case 4:
                printf("Enter the name of the existing file you would like to read: ");
                scanf("%s", filename);
                filePointer = fopen(filename, "r"); 
                if (filePointer == NULL) {
                    printf("File not found.\n");
                } else {
                    char text[1000];
                    while (fgets(text, 1000, filePointer) != NULL) {
                        printf("%s", text);
                    }
                    fclose(filePointer);
                }
                break;
            case 5:
                printf("Enter the name of the existing file you would like to delete: ");
                scanf("%s", filename);
                if (remove(filename) == 0) {
                    printf("File deleted successfully.\n");
                } else {
                    printf("Error deleting the file.\n");
                }
                break;
            case 6:
                printf("Exiting the file explorer.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
