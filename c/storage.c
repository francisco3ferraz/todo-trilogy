#include "todo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *path = "~/.todo-trilogy/c.rb";
const int max_todos = 80;

int storage_load(TODO *todos) {
  if (todos == NULL) {
    return -1;
  }

  FILE *fptr =
      fopen(path, "r"); // Text mode is preferred for line/formatted parsing
  if (fptr == NULL) {
    perror("Error opening file");
    return -1;
  }

  char line[128];

  // Read the total count line safely
  if (!fgets(line, sizeof(line), fptr)) {
    fclose(fptr);
    return -1;
  }

  int expected_todos = 0;
  if (sscanf(line, "%d", &expected_todos) != 1 || expected_todos < 0) {
    fclose(fptr);
    return -1;
  }

  todos = calloc(expected_todos, sizeof(TODO));
  if (todos == NULL) {
    perror("Error allocating memory on load");
    return -1;
  }

  int count = 0;
  while (count < expected_todos && count < max_todos &&
         fgets(line, sizeof(line), fptr)) {
    line[strcspn(line, "\r\n")] = '\0';

    if (line[0] == '\0') {
      continue;
    }

    if (sscanf(line, "%d,%49[^,],%d", &todos[count].id,
               todos[count].description, &todos[count].done) == 3) {
      count++;
    }
  }

  fclose(fptr);
  return 0;
}