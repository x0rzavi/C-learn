#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 512

int main(void) {
  printf("Enter a string: ");
  char buffer[BUFFER_SIZE];

  if (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
    buffer[strcspn(buffer, "\n")] = '\0';
    char *token = strtok(buffer, ",");

    while (token != NULL) {
      printf("%s\n", token);
      token = strtok(NULL, ",");
    }
  }
}
