#include "utils.h"

#include <stdio.h>

bool is_whitespace(char c) { return c == '\n' || c == '\t' || c == ' '; }

/* check if a character is a letter */
bool is_letter(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

/* remove trailing and starting blanks, tabs and entirely empty lines */
void strip(char s[]) { int i = 0; }

/* read a line into s, until lim - 1 chars */
int _getline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && ((c = getchar()) != EOF && c != '\n'); ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/* copy 'from' into 'to', assuming 'to' is big enough */
void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') ++i;
}
