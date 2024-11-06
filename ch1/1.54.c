#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

void print_wc() {
  int c, state;
  long nc, nl, nw;
  nl = nw = nc = 0;
  state = OUT;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n') ++nl;
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("nc: %ld\n", nc);
  printf("nl: %ld\n", nl);
  printf("nw: %ld\n", nw);
}

void test_wc() {
  printf("%s\n", "running tests");
  // FILE *file = fopen("wc_test.txt", "r");
  // have files with different kinds of inputs to test
}

int main() {
  print_wc();
  // test_wc();
  return 0;
}
