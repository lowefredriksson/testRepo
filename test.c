#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Clear_stdin while (getchar() != '\n')
#define ELEMENTS 200

void printManual(void);

int main(int argc, char *argv[]) {

  puts("\nVälkommen till lagerhantering 1.0");
  puts("==================================");
  printManual();  
  return 0;
}

void printManual(void) {
  puts("\n[L]ägga till en vara");
  puts("[T]a bort en vara");
  puts("[R]edigera en vara");
  puts("Ån[g]ra senaste ändringen");
  puts("Lista [h]ela ändringen");
  puts("[A]vsluta\n");
  puts("Vad vill du göra idag?");
}

char ask_question_char(char *q, char *alt) {
  char input = 0;

  printf("%s [%s]\n", q, alt);
  do {
    if (input) {
      printf("Bad input '%c', try again [%s]\n", input, alt);
      Clear_stdin;
    }

    input = getchar();
  } while (strchr(alt, input) == NULL);

  Clear_stdin;
  return input;
}
  
typedef struct item {
  char *name;
  char *description;
  int price;
  char *storageId; // t.ex A25 inte A 25 eller 25
} item; 

item items[ELEMENTS];
