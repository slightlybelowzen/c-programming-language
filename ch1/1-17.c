#include "../utils.c"

int main() {
  char buffer[200];
  int length = 0;
  int len = _getline(buffer, 200);
  while (len >= 0) {
    if (len >= 80) {
      printf("%s", buffer);
    }
    len = _getline(buffer, 200);
  }
  return 0;
}
