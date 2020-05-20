#include <stddef.h>		/* For NULL */
#include <stdio.h>		/* For printf */

#define CHECK(func, test_str, result)		\
  printf("TEST: %s\n", (func(test_str) == result) ? "pass" : "fail")
  

char long_recursive_mylast(char * list) {
  if (!list[1])
    return *list;
  return long_recursive_mylast(list + 1);
}

char short_recursive_mylast(char * list) {
  return list[1] ? short_recursive_mylast(list + 1) : *list;
}

char imperative_mylast(char * list) {
  while (*++list);
  return *--list;
}

int main() {
  CHECK(long_recursive_mylast, "abcd", 'd');
  CHECK(short_recursive_mylast, "abcd", 'd');
  CHECK(imperative_mylast, "abcd", 'd');
}
