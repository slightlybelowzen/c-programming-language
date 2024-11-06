#include <assert.h>
#include <stdio.h>

#include "../utils.c"

int main() {
  char s[] = "Something important \t";
  char t[] = "Something important";
  rstrip(s);
  assert(_strlen(s) == _strlen(t));
  return 0;
}
