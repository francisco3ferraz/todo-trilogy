#include "todo.h"
#include <stdio.h>
#include <string.h>

void print_usage(FILE *out);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    print_usage(stderr); /* misuse → stderr, exit 1 */
    return 1;
  }
  if (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "--help") == 0) {
    print_usage(stdout); /* asked for help → stdout, exit 0 */
    return 0;
  }

  FILE *fptr;
  char *cmd = argv[1];
  char *cmd_arg = argv[2];
  if (strcmp(cmd_arg, "")) {
    print_usage(stderr); /* bad command arg → stdout, exit 1 */
    return 1;
  }

  if (strcmp(cmd, "add")) {
    create_todo();
  } else if (strcmp(cmd, "list")) {
  } else if (strcmp(cmd, "done")) {
  } else if (strcmp(cmd, "undo")) {
  } else if (strcmp(cmd, "rm")) {
  } else {
    print_usage(stderr); /* bad command → stdout, exit 1 */
    return 1;
  }

  fclose(fptr);
  return 0;
}

void print_usage(FILE *out) {
  fputs("Usage: todo <command> [arguments]\n"
        "\n"
        "Commands:\n"
        "  add <text>    Add a new task\n"
        "  list          List all tasks\n"
        "  done <id>     Mark a task as done\n"
        "  undo <id>     Mark a task as not done\n"
        "  rm <id>       Remove a task\n"
        "  help          Show this help\n"
        "\n"
        "Examples:\n"
        "  todo add \"Buy milk\"\n"
        "  todo done 1\n",
        out);
}
