#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 *
 * This program reads and prints a file's contents
 *
* */
int main() {
  int test_file_fd = open("IO/test.txt", O_RDONLY);
  if (test_file_fd < 0) {
    fprintf(stderr, "Error: [%s]\n", strerror(errno));
    return 1;
  }

  static const int buf_size = 4096;
  int num_read = 0;
  char content[buf_size];

  while (0 < (num_read = read(test_file_fd, content, buf_size))) {
    if (write(STDOUT_FILENO, content, num_read) != num_read) {
      fprintf(stderr, "Error: [%s]\n", strerror(errno));
      return 1;
    }
  }
  if (num_read == -1) {
    fprintf(stderr, "Error: [%s]\n", strerror(errno));
    return 1;
  }
  if (close(test_file_fd) == -1) {
    fprintf(stderr, "Error: [%s]\n", strerror(errno));
    return 1;
  }
  return 0;
}
