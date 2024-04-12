/* This file manager will only work if the specified filename is directly in the same directory as the CLI directory. */
/* An update should be done later to resolve this. */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_FILE_CONTENT_LEN 10000

char* AspectFLM_getfilebyname(const char* filename) {
    FILE* file;
    char* contents = (char*)malloc(MAX_FILE_CONTENT_LEN * sizeof(char));

    if (contents == NULL) {
        perror("Memory allocation failed.");
        return NULL;
    }

    struct dirent *entry;
    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("Unable to open the directory.");
        free(contents);
        return NULL;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, filename) == 0) {
            file = fopen(filename, "r");
            if (file == NULL) {
                perror("Unable to open the file.");
                free(contents);
                closedir(dir);
                return NULL;
            }

            char line[MAX_FILE_CONTENT_LEN];
            contents[0] = '\0';

            while (fgets(line, sizeof(line), file) != NULL) {
                strcat(contents, line);
                strcat(contents, " ");
            }

            fclose(file);
            closedir(dir);
            return contents;
        }
    }

    fprintf(stderr, "File not found: %s\n", filename);
    free(contents);
    closedir(dir);
    return NULL;
}
