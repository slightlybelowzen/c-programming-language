#include <stdio.h>

#include "../utils.c"

int main() {
  char s[] = {'s', 'o', 'm', 'e', 't', 'h', 'i', 'n', 'g', '\0'};
  reverse(s);
  printf("%s\n", s);
  return 0;
}
