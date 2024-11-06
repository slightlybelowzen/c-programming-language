#include <stdio.h>

#include "../utils.c"

int main() {
  char s[] = "something";
  reverse(s);
  printf("%s\n", s);
  return 0;
}
