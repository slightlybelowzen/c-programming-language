#include <stdbool.h>
#include <stdio.h>

#define CHARACTERS_SET_SIZE 26 /* max length of a word, x-axis limit */

bool is_char(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
  int c;
  int char_frequency[CHARACTERS_SET_SIZE];

  for (int i = 0; i < CHARACTERS_SET_SIZE; i++) {
    char_frequency[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (is_char(c)) {
      int char_index = c - 'a';
      ++char_frequency[char_index];
    } else {
      continue;
    }
  }
  for (int i = 0; i < CHARACTERS_SET_SIZE; i++) {
    char letter = 'a' + i;
    printf(" %c| ", letter);
    for (int j = 0; j < char_frequency[i]; j++) {
      printf("%s", "*");
    }
    printf("\n");
  }

  return 0;
}
