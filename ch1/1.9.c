#include "../utils.c"

#define MAXLINE 1000 /* max input line length */

/* print the longest line */
void print_longest_line() {
  int len = 0;
  int maxlen = 0;
  char line[MAXLINE];
  char longest[MAXLINE];

  while ((len = _getline(line, MAXLINE)) > 0) {
    if (len > MAXLINE) len = MAXLINE;
    if (len > maxlen) {
      maxlen = len;
      copy(longest, line);
    }
  }
  if (maxlen > 0) printf("longest line: %s\n", longest);
}

/* print every line longer than 80 chars */
void print_longer_than_eighty_chars() {
  int len = 0;
  char line[MAXLINE];

  while ((len = _getline(line, MAXLINE)) > 0) {
    if (len > MAXLINE) len = MAXLINE;
    if (len > 80) {
      printf("%s\n", line);
    }
  }
}

int main() {
  // print_longest_line();
  print_longer_than_eighty_chars();
  return 0;
}
