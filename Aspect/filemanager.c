/* Aspect File Manager */

#include <stdio.h>
#include <filemanager.h>
#include <unistd.h>

static int file_exists(char* filepath) {
    return access(filepath, F_OK) == 0;
}

char* AspectFLM_getfilebyname(char* filename) {
    if (!file_exists(filename)) {
    fprintf(stderr, "File doesn't exist: %s\n", filename);
    return 0;
  }

  FILE* file_pointer = fopen(filename, "r");
  char* buffer = NULL;
  size_t length;
  ssize_t bytes_read = getdelim(&buffer, &length, '\0', file_pointer);
  
    if (bytes_read == -1) {
    printf("Failed to read the file: `%s`\n", filename);
    return 0;
  }

  fclose(file_pointer);
  return buffer;
}
