#include "utils.h"

#include <stdio.h>

/* check if a character is a space */
bool is_whitespace(const char c) { return c == '\n' || c == '\t' || c == ' '; }

/* check if a character is a letter */
bool is_letter(const char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

/* remove trailing and starting blanks, tabs and entirely empty lines */
void strip(char s[]) { int i = 0; }

/* return the length of a given string */
int _strlen(const char s[]) {
  int i = 0, len = 0;
  while (s[i] != '\0') {
    ++i;
    ++len;
  }
  return len;
}

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
void copy(char to[], const char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') ++i;
}

/* reverse a given string */
void reverse(char s[]) {
  // i in 0..len(s) / 2
  // swap(s[i], s[len - i - 1])
  // don't move the last index, terminates the string at index 0
  int i = 0, len = _strlen(s);
  int half_len = len / 2;
  for (i = 0; i < half_len; ++i) {
    char temp = s[i];
    s[i] = s[len - 1 - i];
    s[len - i - 1] = temp;
  }
}
