#include <assert.h>  // assert
#include <fcntl.h>   // open
#include <limits.h>  // INT_MAX
#include <math.h>    // sqrt
#include <stdbool.h> // bool false true
#include <stdio.h>
#include <stdlib.h> // malloc
#include <stdlib.h> // sort
#include <string.h> // strcmp ..
#include <unistd.h> // sleep

int main(int argc, char *argv[]) {
  char str1[] = "9231000000";
  char str2[] = "019198";

  int len_str1 = sizeof(str1) - 1;
  int len_str2 = sizeof(str2) - 1;
  char *res = (char *)malloc(sizeof(str1) + sizeof(str2) - 2 + 1);
  memset(res, 0, sizeof(str1) + sizeof(str2) - 2 + 1);

  for (int i = 0; i < len_str1; ++i) {

    for (int j = 0; j < len_str2; ++j) {

      if (i + j < len_str1) {
        if (str2[j] > str1[i + j]) {
          // a
          for (int k = 0; k < i; ++k) {
            res[k] = str1[k];
          }

          // b
          for (int k = 0; k < len_str2; ++k) {
            res[i + k] = str2[k];
          }

          // c
          for (int k = i; k < len_str1; ++k) {
            res[k + len_str2] = str1[k];
          }

          printf(" %s\n", res);
          return 0;
        } else if (str2[j] < str1[i + j]) {
          break;
        } else {
        }
      } else {
        break;
      }
    }
  }

  for (int i = 0; i < len_str1; ++i) {
    res[i] = str1[i];
  }
  for (int i = 0; i < len_str2; ++i) {
    res[i + len_str1] = str2[i];
  }
  printf(" %s\n", res);

  return 0;
}
