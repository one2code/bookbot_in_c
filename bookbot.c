#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

char* get_directory_from_user() {
    char directory_path[256];
    printf("Please enter the directory path to process: ");
    scanf("%s", directory_path);

    struct stat s;
    if (stat(directory_path, &s) == 0 && S_ISDIR(s.st_mode) && access(directory_path, R_OK) == 0) {
        char* result = malloc(strlen(directory_path) + 1);
        strcpy(result, directory_path);
        return result;
    } else {
        printf("Invalid or inaccessible directory path. Please try again.\n");
        return NULL;
    }
}

int word_count(char* text) {
    int count = 0;
    int in_word = 0;
    while (*text) {
        if (*text == ' ' || *text == '\n' || *text == '\t') {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
        text++;
    }
    return count;
}

int main() {
    char* directory_path = get_directory_from_user();
    if (directory_path != NULL) {
        // Do something with directory_path
        free(directory_path); // Remember to free the memory when you're done with it
    }

    return 0;
}

