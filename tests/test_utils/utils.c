#include <stdbool.h>
#include <stdio.h>

#include "utils.h"


bool test_assert(bool condition, char test_name[])
{
  if (condition == false) {
    printf("test assertion in \"%s\": failed\n", test_name);
  }
  return condition;
}
