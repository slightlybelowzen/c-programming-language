#include <stdio.h>

#include "../utils.c"

int main() {
  int c, nwhite, nother;
  int ndigit[10];

  nwhite = nother = 0;
  for (int i = 0; i < 10; i++) {
    ndigit[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9')
      ++ndigit[c - '0'];
    else if (is_whitespace(c)) {
      ++nwhite;
    } else
      ++nother;
  }
  printf("digits:\n");
  for (int i = 0; i < 10; ++i) {
    printf("%d: %d\n", i, ndigit[i]);
  }
  printf("\n");
  printf("white spaces: %d\n", nwhite);
  printf("other chars: %d\n", nother);
}
