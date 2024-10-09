#include <stdio.h>

#define MAX_WORD_LENGTH 15 /* max length of a word, x-axis limit */

/**
 * TODO: how to do this vertically?
 */

int main() {
  int c, word_len;
  int word_lens_frequency[MAX_WORD_LENGTH];
  word_len = 0;

  for (int i = 0; i < MAX_WORD_LENGTH; i++) {
    word_lens_frequency[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == '\t' || c == ' ') {
      ++word_lens_frequency[word_len];
      word_len = 0;
    } else {
      ++word_len;
    }
  }
  for (int i = 0; i < MAX_WORD_LENGTH; i++) {
    printf(" %2d| ", i);
    for (int j = 0; j < word_lens_frequency[i]; j++) {
      printf("%s", "*");
    }
    printf("\n");
  }

  return 0;
}
