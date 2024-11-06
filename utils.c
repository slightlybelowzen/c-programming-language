#include "utils.h"

#include <stdio.h>

/**
 * @brief Determines if a character is a whitespace character
 *
 * @details Checks whether the given character is considered whitespace
 * according to the C standard. Whitespace characters include: space (' '), form
 * feed ('\f'), newline ('\n'), carriage return ('\r'), horizontal tab ('\t'),
 * and vertical tab ('\v').
 *
 * @param[in] c The character to check
 *
 * @return Returns True if the character is whitespace, False otherwise
 *
 * @note This function follows the C standard definition of whitespace
 * characters
 * @see isspace() - Standard C library function for whitespace checking
 */
bool is_whitespace(const char c) {
  return c == '\n' || c == '\t' || c == ' ' || c == '\r' || c == '\v';
}

/**
 * Tests whether a character is an alphabetic letter (A-Z or a-z).
 *
 * This function determines if the input character is a letter from the English
 * alphabet, either uppercase or lowercase. Characters outside the ranges A-Z
 * and a-z (including numbers, punctuation, spaces, and extended ASCII) are
 * considered non-alphabetic.
 *
 * @param ch    The character to be tested
 *
 * @return      True if the character is a letter
 *              False if the character is not a letter
 *
 * @note        This function only works with ASCII characters. Extended ASCII
 *              or Unicode letters (like é, ñ, etc.) will return false.
 */
bool is_letter(const char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

/**
 * Removes trailing whitespace characters (spaces and tabs) from a string.
 *
 * This function modifies the input string in place by removing all whitespace
 * characters from the end of the string. Whitespace is defined as spaces (' ')
 * and horizontal tabs ('\t'). The function preserves all leading and internal
 * whitespace, only removing whitespace from the end of the string.
 *
 * @param str   Pointer to the null-terminated string to be trimmed.
 *              The string must be modifiable (not a string literal).
 *              If NULL is passed, the function returns NULL.
 *
 * @return      Pointer to the modified string (same as input pointer).
 *
 * @note        The function modifies the string in place and does not allocate
 *              new memory. The input string buffer must be writable.
 */
char* rstrip(char str[]) {
  if (str == NULL) {
    return NULL;
  }
  int i = _strlen(str) - 1;
  while (i >= 0 && (str[i] == ' ' || str[i] == '\t')) {
    --i;
  }
  str[i + 1] = '\0';
  return str;
}

/**
 * Computes the length of a null-terminated string.
 *
 * This function counts the number of characters in a string up to, but not
 * including, the terminating null character ('\0'). The function performs
 * no bounds checking and assumes the string is properly null-terminated.
 *
 * @param str   Pointer to the null-terminated string
 *              If NULL is passed, the function returns 0
 *
 * @return      Number of characters in the string (excluding null terminator)
 *              0 if the string is empty or NULL
 *
 * @note        The function assumes the string is properly null-terminated.
 *              Using it on non-null-terminated strings may cause buffer
 * overruns.
 */
int _strlen(const char str[]) {
  if (str == NULL) {
    return 0;
  }
  int i = 0, len = 0;
  while (str[i] != '\0') {
    ++i;
    ++len;
  }
  return len;
}

/**
 * Reads a line of text from standard input into a string.
 *
 * This function reads characters from stdin until either a newline character
 * ('\n') is encountered, the buffer limit is reached, or EOF is reached. The
 * newline character is included in the string if space permits. The string is
 * always null-terminated.
 *
 * @param s     Array where the line will be stored
 *              Must be able to hold at least lim characters
 *
 * @param lim   Maximum number of characters to read (including null terminator)
 *              Must be greater than 0
 *
 * @return      Number of characters read (including newline if present,
 * excluding null terminator) 0 if EOF is encountered with no characters read -1
 * if error occurs or if lim <= 0
 *
 * @note        If the line length equals or exceeds lim-1, the remaining
 * characters on the line are discarded. The function ensures space for the null
 * terminator.
 */
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

/**
 * Copies a string from source to destination.
 *
 * This function copies characters from the source string to the destination
 * string, including the null terminator. The function performs no bounds
 * checking and assumes the destination buffer is large enough.
 *
 * @param to    Destination array where the string will be copied
 *              Must have sufficient space to hold the entire source string
 *              including null terminator
 *
 * @param from  Source string to be copied
 *              Must be null-terminated
 *
 * @return      Pointer to the destination string
 *              NULL if either parameter is NULL
 *
 * @note        This function provides no buffer overflow protection.
 *              Caller must ensure destination array is large enough.
 */
char* copy(char to[], const char from[]) {
  if (to == NULL || from == NULL) {
    return NULL;
  }
  int i = 0;
  while ((to[i] = from[i]) != '\0') ++i;
  return to;
}

/**
 * Reverses a string in place.
 *
 * This function reverses the characters in a string, modifying the original
 * string. The null terminator remains at the end of the string. For example,
 * "Hello" becomes "olleH".
 *
 * @param str   String to be reversed
 *              Must be null-terminated and modifiable
 *
 * @return      Pointer to the reversed string (same as input pointer)
 *              NULL if input is NULL
 *
 * @note        The function modifies the string in place and does not allocate
 *              new memory. The input string buffer must be writable.
 */
char* reverse(char str[]) {
  if (str == NULL) {
    return NULL;
  }
  int i = 0, len = _strlen(str);
  int half_len = len / 2;
  for (i = 0; i < half_len; ++i) {
    char temp = str[i];
    str[i] = str[len - 1 - i];
    str[len - i - 1] = temp;
  }
  return str;
}
